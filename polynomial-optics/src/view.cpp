#include "lenssystem.h"
#include "raytrace.h"
#include "raytrace_draw.h"
#include "poly.h"

#include <gtk/gtk.h>
#include <cairo.h>
#include <cairo-svg.h>
#include <cmath>

//json parsing
#include "../ext/json.hpp"
#include <string>
#include <fstream>
using json = nlohmann::json;

#include "../../fmt/include/fmt/format.h"

#ifndef M_PI
  #define M_PI 3.14159265358979323846
#endif



static float zoom = 0.0f; // zoom, if the lens supports it.
//static const int degree = 4;  // degree of the polynomial. 1 is thin lens
//static const float coverage = .5f; // coverage of incoming rays at scene facing pupil (those you point with the mouse)
static int num_rays = 500;
static int dim_up = 0; // xz (top - 0) or plot yz (side - 1) of the lens in 2d?
static poly_system_t poly, poly_aperture;
static float aperture_rad;
static lens_element_t lenses[50];
static int lenses_cnt = 0;
static float lens_pupil_dist = 0.0f;
static float lens_pupil_rad = 0.0f;
static float lens_length = 0;
static float aperture_pos = 0;

static int screenshot = 0;
static int draw_raytraced = 1;
static int draw_polynomials = 0;
static int draw_aspheric = 1;
static int draw_focallength = 0;
static int mode_visual_debug = 0;

static int width = 900;
static int height = 550;
static int gridsize = 10; //10 mm

static float global_scale = 20.0f;
static float window_aspect_ratio = (float)width/(float)height;

const float black[4] = {0.1, 0.1, 0.1, 1.0};
const float darkgrey[4] = {0.15, 0.15, 0.15, 1.0};
const float grey[4] = {0.5, 0.5, 0.5, 1.0};
const float lightgrey[4] = {0.825, 0.825, 0.825, 1.0};
const float yellow[4] = {0.949, 0.882, 0.749, 0.65};
const float green[4] = {0.749, 0.949, 0.874, 1.0};
const float white50[4] = {1.0, 1.0, 1.0, 0.5};
const float white[4] = {1.0, 1.0, 1.0, 1.0};
const float mint[4] = {0.631, 1.0, 0.78, 0.5};
const float salmon[4] = {232.0/255.0, 121.0/255.0, 121.0/255.0, 1.0};

std::string lens_svg_path = "";


gboolean on_keypress (GtkWidget *widget, GdkEventKey *event, gpointer data) {
  if(event->keyval == GDK_KEY_Escape) {
    gtk_main_quit();
    return TRUE;
  }
  else if(event->keyval == GDK_KEY_s) {
    screenshot = !screenshot;
    gtk_widget_queue_draw(widget);
    return TRUE;
  }
  else if(event->keyval == GDK_KEY_a) {
    draw_aspheric = !draw_aspheric;
    fmt::print("Using {}spherical lenses\n", draw_aspheric ? "a" : "");
    gtk_widget_queue_draw(widget);
    return TRUE;
  }
  else if(event->keyval == GDK_KEY_f) {
    draw_focallength = !draw_focallength;
    gtk_widget_queue_draw(widget);
    return TRUE;
  }
  else if(event->keyval == GDK_KEY_plus) {
    global_scale /= 0.95;
    gtk_widget_queue_draw(widget);
    return TRUE;
  }
  else if(event->keyval == GDK_KEY_minus) {
    global_scale *= 0.95;
    gtk_widget_queue_draw(widget);
    return TRUE;
  }
  else if(event->keyval == GDK_KEY_m) {
    num_rays += 10;
    gtk_widget_queue_draw(widget);
    return TRUE;
  }
  else if(event->keyval == GDK_KEY_l) {
    num_rays -= 10;
    gtk_widget_queue_draw(widget);
    return TRUE;
  }
  else if(event->keyval == GDK_KEY_x) {
    dim_up = !dim_up;
    gtk_widget_queue_draw(widget);
    return TRUE;
  }
  else if(event->keyval == GDK_KEY_p) {
    draw_polynomials = !draw_polynomials;
    gtk_widget_queue_draw(widget);
    return TRUE;
  }  
  else if(event->keyval == GDK_KEY_v) {
    mode_visual_debug = !mode_visual_debug;
    gtk_widget_queue_draw(widget);
    return TRUE;
  }

  return FALSE;
}

static inline float hue_2_rgb(float v1, float v2, float vH) {
  if (vH < 0.0f) vH += 1.0f;
  if (vH > 1.0f) vH -= 1.0f;
  if ((6.0f * vH) < 1.0f) return (v1 + (v2 - v1) * 6.0f * vH);
  if ((2.0f * vH) < 1.0f) return (v2);
  if ((3.0f * vH) < 2.0f) return (v1 + (v2 - v1) * ((2.0f / 3.0f) - vH) * 6.0f);
  return (v1);
}

static inline void hsl_2_rgb(const float *HSL, float *RGB) {
  float H = HSL[0];
  float S = HSL[1];
  float L = HSL[2];

  float var_1, var_2;

  if (S < 1e-6f) {
    RGB[0] = RGB[1] = RGB[2] = L;
  } else {
    if (L < 0.5f) var_2 = L * (1.0f + S);
    else          var_2 = (L + S) - (S * L);

    var_1 = 2.0f * L - var_2;

    RGB[0] = hue_2_rgb(var_1, var_2, H + (1.0f / 3.0f));
    RGB[1] = hue_2_rgb(var_1, var_2, H);
    RGB[2] = hue_2_rgb(var_1, var_2, H - (1.0f / 3.0f));
  }
}

static void stroke_with_pencil(cairo_t *cr, float scale, float line_width) {
  cairo_save(cr);
  cairo_scale(cr, 1./scale, 1./scale);
  cairo_set_line_width(cr, line_width);
  cairo_stroke(cr);
  cairo_restore(cr);
}

void draw_optical_axis(cairo_t *cr) {
  cairo_set_line_width(cr, 4.0f);
  cairo_set_source_rgba(cr, lightgrey[0], lightgrey[1], lightgrey[2], 0.5);
  cairo_move_to(cr, 0, height/2.0);
  cairo_line_to(cr, width, height/2.0);
  cairo_stroke(cr);
}

void draw_sensor(cairo_t *cr) {
  float sensor_size = 0.0;
  if (dim_up) sensor_size = 24.0;
  else        sensor_size = 35.0;

  cairo_move_to(cr, -1.0, -sensor_size/2.0);
  cairo_line_to(cr, -1.0,  sensor_size/2.0);
  cairo_line_to(cr,  0.0,  sensor_size/2.0);
  cairo_line_to(cr,  0.0, -sensor_size/2.0);
  cairo_close_path(cr);
  cairo_set_source_rgb(cr, grey[0], grey[1], grey[2]);
  cairo_fill(cr);
}

void draw_grid(cairo_t *cr) {
  cairo_set_line_width(cr, 200.0/width);
  cairo_set_source_rgb(cr, black[0], black[1], black[2]);
  for (int i = -width; i<width; i += gridsize){
    cairo_move_to(cr, i, -height);
    cairo_line_to(cr, i, height);
    cairo_stroke(cr);
  }

  for (int i = -height/2; i<height; i += gridsize){
    cairo_move_to(cr, -width, i);
    cairo_line_to(cr, width, i);
    cairo_stroke(cr);
  }
}

void draw_rulers(cairo_t *cr, float max_housing_radius, float ruler_padding) {
  float ruler_height = 2.5;
  cairo_set_source_rgb(cr, grey[0], grey[1], grey[2]);
  cairo_set_line_width(cr, 200.0/width);

  // x axis
  cairo_move_to(cr, -ruler_padding, max_housing_radius + ruler_padding);
  cairo_line_to(cr, lens_length, max_housing_radius + ruler_padding);
  cairo_stroke(cr);
  for (int i = 0; i<lens_length + ruler_padding; i += gridsize){
    cairo_move_to(cr, i, max_housing_radius + ruler_padding);
    cairo_line_to(cr, i, max_housing_radius + ruler_padding - ruler_height);
    cairo_stroke(cr);

    cairo_move_to(cr, i, max_housing_radius + ruler_padding*1.5);
    std::string number = std::to_string(i);
    char const *pchar = number.c_str();
    cairo_set_font_size(cr, 2.5);
    cairo_show_text(cr, pchar);
    cairo_new_path(cr);
  }

  // y axis down
  cairo_move_to(cr, 0.0 - ruler_padding, max_housing_radius + ruler_padding);
  cairo_line_to(cr, 0.0 - ruler_padding, -max_housing_radius);
  cairo_stroke(cr);
  for (int i = 0; i < max_housing_radius + ruler_padding; i += gridsize){
    cairo_move_to(cr, -ruler_padding, i);
    cairo_line_to(cr, -ruler_padding + ruler_height, i);
    cairo_stroke(cr);

    cairo_move_to(cr, -ruler_padding*1.5, i);
    std::string number = std::to_string(-i);
    char const *pchar = number.c_str();
    cairo_set_font_size(cr, 2.5);
    cairo_show_text(cr, pchar);
    cairo_new_path(cr);
  }
  for (int i = gridsize; i < max_housing_radius + ruler_padding; i += gridsize){
    cairo_move_to(cr, -ruler_padding, -i);
    cairo_line_to(cr, -ruler_padding + ruler_height, -i);
    cairo_stroke(cr);

    cairo_move_to(cr, -ruler_padding*1.5, -i);
    std::string number = std::to_string(i);
    char const *pchar = number.c_str();
    cairo_set_font_size(cr, 2.5);
    cairo_show_text(cr, pchar);
    cairo_new_path(cr);
  }
}

void draw_axis_text(cairo_t *cr, float max_housing_radius, float ruler_padding) {
  cairo_move_to(cr, 0.0 - ruler_padding, max_housing_radius + ruler_padding*2);
  std::string dim_up_text;
  if (dim_up) dim_up_text = "dim_up = 1 [side]";
  else        dim_up_text = "dim_up = 0 [top]";
  char const *pchar = dim_up_text.c_str();
  cairo_set_font_size(cr, 2.5);
  cairo_show_text(cr, pchar);
  cairo_new_path(cr);
}

void draw_aperture(cairo_t *cr) {
  int aperture_element = lens_get_aperture_element(lenses, lenses_cnt-1);
  float aperture_pos = lens_get_aperture_pos_reverse(lenses, lenses_cnt-1, 0.0f);
  float housing_radius = lenses[aperture_element].housing_radius;

  cairo_set_source_rgba(cr, lightgrey[0], lightgrey[1], lightgrey[2], lightgrey[3]);
  cairo_set_line_width(cr, 500.0/width);

  cairo_move_to(cr, aperture_pos, housing_radius+10);
  cairo_line_to(cr, aperture_pos, housing_radius);
  cairo_stroke(cr);
  cairo_move_to(cr, aperture_pos, -housing_radius-10);
  cairo_line_to(cr, aperture_pos, -housing_radius);
  cairo_stroke(cr);
}



gboolean draw_callback(GtkWidget *widget, cairo_t *cr, gpointer data) {
  cairo_surface_t *svg_surface = 0;
  if(screenshot) { 
    svg_surface = cairo_svg_surface_create(lens_svg_path.c_str(), width, height);
    cairo_svg_surface_restrict_to_version (svg_surface, CAIRO_SVG_VERSION_1_2);
    cr = cairo_create(svg_surface);
  } 

  cairo_set_line_cap(cr, CAIRO_LINE_CAP_ROUND);
  cairo_set_line_join(cr, CAIRO_LINE_JOIN_BEVEL);
  cairo_set_source_rgb(cr, darkgrey[0], darkgrey[1], darkgrey[2]);
  cairo_paint(cr);
  cairo_set_line_width(cr, 1.0f);

  draw_optical_axis(cr);

  cairo_translate(cr, 0, height/2.0);
  if (!mode_visual_debug){
    cairo_translate(cr, width/2.0, 0);
  }

  cairo_scale(cr, ((float)width/window_aspect_ratio)/20.0, (float)height/20.0);
  cairo_set_line_width(cr, 40.0/width);

  const float scale = global_scale/lens_length;
  cairo_scale(cr, scale, scale); // scale by arbitrary factor

  if (!mode_visual_debug){
    float center_shift = -((lens_length + lenses[lenses_cnt-1].thickness_short) / 2.0);
    cairo_translate(cr, center_shift, 0);
  } else {
    cairo_translate(cr, 20.0, 0.0); // move 20mm away
    draw_grid(cr);

    // find max housing radius
    float max_housing_radius = 0.0;
    for (int i=0; i < lenses_cnt; i++){
      if (lenses[i].housing_radius > max_housing_radius){
        max_housing_radius = lenses[i].housing_radius;
      }
    }

    float ruler_padding = gridsize;
    draw_rulers(cr, max_housing_radius, ruler_padding);
    draw_axis_text(cr, max_housing_radius, ruler_padding);
  }


  cairo_set_line_width(cr, 90.0/width);
  cairo_set_source_rgba(cr, lightgrey[0], lightgrey[1], lightgrey[2], 0.5);

  float pos = lens_length;
  aperture_pos = lens_length/2.0f; // why is this so arbitrary..?
  float hsl[3], rgb[3];

  
  if(draw_focallength){
    fmt::print("Drawing in forward direction. \n");

    // FORWARD TRACING/DRAWING, calculate focal length
    float cam_pos[3] = {0.0f};
    float cam_dir[3] = {0.0f};
    cam_pos[dim_up] = lenses[lenses_cnt-1].housing_radius * 0.5f;
    cam_dir[2] = cam_pos[2] + 99999;
    cam_dir[dim_up] = cam_pos[dim_up];

    const float lambda = 0.5f;
    float in[5] = {0.0f};
    float out[5] = {0.0f};
    float ap[5] = {0.0f};
    in[4] = out[4] = ap[4] = lambda;
    float inrt[5] = {cam_pos[0], cam_pos[1], cam_pos[2], 0.0f, lambda};
    float outrt[5] = {cam_dir[0], cam_dir[1], cam_dir[2], 0.0f, lambda};

    int error = 0;
    if(draw_raytraced)
      error = evaluate_draw(lenses, lenses_cnt, zoom, inrt, outrt, cr, scale, dim_up, draw_aspheric, true, true);

  } else {

    fmt::print("Drawing in backward direction. \n");

    const float len = lens_length/10.0f;
    for(int k=0; k<num_rays; k++){

      float cam_pos[3] = {0.0, 0.0, 9999.0f};
      const float y = 2.0f * (num_rays/2-k)/(float)num_rays * lenses[0].housing_radius;
      cam_pos[dim_up] = y;

      float cam_dir[3] = {0.0, 0.0, -cam_pos[2]*10.0f};
      cam_dir[dim_up] = cam_pos[dim_up];
      raytrace_normalise(cam_dir);

      const float lambda = 0.5f;
      float in[5] = {0.0f};
      float out[5] = {0.0f};
      float ap[5] = {0.0f};
      float inrt[5] = {0.0f};
      float outrt[5] = {0.0f};
      inrt[4] = outrt[4] = in[4] = out[4] = ap[4] = lambda;
      float t, n[3] = {0.0f};

      // intersection with first lens element
      if (!strcmp(lenses[0].geometry, "cyl-y")){
        cylindrical(cam_pos, cam_dir, &t, lenses[0].lens_radius, lens_length - lenses[0].lens_radius, lenses[0].housing_radius, n, true);
        for(int i=0;i<3;i++) cam_dir[i] = - cam_dir[i]; // need to point away from surface (dot(n,dir) > 0)
        csToCylinder(cam_pos, cam_dir, in, in+2, lens_length - lenses[0].lens_radius, lenses[0].lens_radius, true);
        // cylinderToCs(in, in + 2, cam_pos, cam_dir, lens_length - lenses[0].lens_radius, lenses[0].lens_radius, true);
      }
      else if (!strcmp(lenses[0].geometry, "cyl-x")){
        cylindrical(cam_pos, cam_dir, &t, lenses[0].lens_radius, lens_length - lenses[0].lens_radius, lenses[0].housing_radius, n, false);
        for(int i=0;i<3;i++) cam_dir[i] = - cam_dir[i]; // need to point away from surface (dot(n,dir) > 0)
        csToCylinder(cam_pos, cam_dir, in, in+2, lens_length - lenses[0].lens_radius, lenses[0].lens_radius, false);
        // cylinderToCs(in, in + 2, cam_pos, cam_dir, lens_length - lenses[0].lens_radius, lenses[0].lens_radius, false);
      }
      else {
        spherical(cam_pos, cam_dir, &t, lenses[0].lens_radius, lens_length - lenses[0].lens_radius, lenses[0].housing_radius, n);
        for(int i=0;i<3;i++) cam_dir[i] = - cam_dir[i]; // need to point away from surface (dot(n,dir) > 0)
        csToSphere(cam_pos, cam_dir, in, in+2, lens_length - lenses[0].lens_radius, lenses[0].lens_radius);
        // sphereToCs(in, in + 2, cam_pos, cam_dir, lens_length - lenses[0].lens_radius, lenses[0].lens_radius);
      }

      for(int i=0;i<5;i++) inrt[i] = in[i];

      int error = 0;
      if(draw_raytraced) {
        error = evaluate_reverse_draw(lenses, lenses_cnt, zoom, inrt, outrt, cr, scale, dim_up, draw_aspheric);
      } else {
        error = evaluate_reverse(lenses, lenses_cnt, zoom, inrt, outrt, draw_aspheric);
      }
    
      // ray color:
      hsl[0] = k/(num_rays+1.);
      hsl[1] = .7f;
      hsl[2] = .5f;
      hsl_2_rgb(hsl, rgb);

      if(!error)
      {
        // evaluate sensor -> light
        for(int i=0;i<5;i++) in[i] = outrt[i];
        in[2] = -in[2];
        in[3] = -in[3];
        //outrt[4] equals transmittance
        in[4] = lambda;
        poly_system_evaluate(&poly, in, out, 15);
      }

      if(!error && draw_polynomials)
      {
        // draw everything grayed out in case it got killed on the aperture
        poly_system_evaluate(&poly_aperture, in, ap, 15);
        const int aperture_death = (ap[0]*ap[0] + ap[1]*ap[1] > aperture_rad*aperture_rad);
        if(!aperture_death)
        {
          // use transmittance from polynomial evaluation
          float transmittance = out[4];
          cairo_set_source_rgba(cr, rgb[0], rgb[1], rgb[2], 6.0 * transmittance);

          // sensor
          cairo_move_to(cr, 0, in[dim_up]);
          cairo_line_to(cr, 0+len, in[dim_up] + len*in[dim_up+2]);
          stroke_with_pencil(cr, scale, aperture_death ? 40./width : 60./width);

          // aperture
          cairo_move_to(cr, aperture_pos, ap[dim_up]);
          cairo_line_to(cr, aperture_pos+.2*len, ap[dim_up] + .2*len*ap[dim_up+2]);
          stroke_with_pencil(cr, scale, aperture_death ? 40./width : 60./width);

          // outer pupil
          if (!strcmp(lenses[0].geometry, "cyl-y") && !dim_up) cylinderToCs(out, out+2, cam_pos, cam_dir, lens_length - lenses[0].lens_radius, lenses[0].lens_radius, true);
          else if (!strcmp(lenses[0].geometry, "cyl-y") && dim_up) cylinderToCs(out, out+2, cam_pos, cam_dir, lens_length - 99999.0, 99999.0, true);
          else if (!strcmp(lenses[0].geometry, "cyl-x") && !dim_up) cylinderToCs(out, out+2, cam_pos, cam_dir, lens_length - 99999.0, 99999.0, false);
          else if (!strcmp(lenses[0].geometry, "cyl-x") && dim_up) cylinderToCs(out, out+2, cam_pos, cam_dir, lens_length - lenses[0].lens_radius, lenses[0].lens_radius, false);
          else sphereToCs(out, out+2, cam_pos, cam_dir, lens_length - lenses[0].lens_radius, lenses[0].lens_radius);
          cairo_move_to(cr, cam_pos[2], cam_pos[dim_up]);
          cairo_line_to(cr, cam_pos[2]+len*cam_dir[2], cam_pos[dim_up] + len*cam_dir[dim_up]);
          stroke_with_pencil(cr, scale, aperture_death ? 40./width : 60./width);
        }
      }

      if(0)//!error)
      {
        outrt[2] = -outrt[2];
        outrt[3] = -outrt[3];
        outrt[4] = lambda;
        error = evaluate_draw(lenses, lenses_cnt, zoom, outrt, inrt, cr, scale, dim_up, draw_aspheric, false, false);
      }  
    }
  }

  for(int i=0; i<lenses_cnt; i++){
    float rad = lenses[i].lens_radius;
    if (!strcmp(lenses[i].geometry, "cyl-y") && dim_up) rad = 99999.0;
    else if (!strcmp(lenses[i].geometry, "cyl-x") && !dim_up) rad = 99999.0;
    
    float hrad = lenses[i].housing_radius;
    float t = lens_get_thickness(lenses+i, zoom);

    // skip aperture drawing
    if(!strcasecmp(lenses[i].material, "iris")) {
      pos -= t;
      continue;
    }

    if(!strcasecmp(lenses[i].material, "iris")) aperture_pos = pos;

    if(lenses[i].ior != 1.0f && i < lenses_cnt-1) {
      cairo_save(cr);

      float rad2 = lenses[i+1].lens_radius;
      if (!strcmp(lenses[i+1].geometry, "cyl-y") && dim_up) rad2 = 99999.0;
      else if (!strcmp(lenses[i+1].geometry, "cyl-x") && !dim_up) rad2 = 99999.0;
    
      float hrad2 = lenses[i+1].housing_radius;
      float off  = rad  > 0.0f ? 0.0f : M_PI;
      float off2 = rad2 > 0.0f ? 0.0f : M_PI;
      float alpha  = asinf(fminf(1.0f, fmaxf(-1.0f, fabsf(hrad/rad))));
      float alpha2 = asinf(fminf(1.0f, fmaxf(-1.0f, fabsf(hrad2/rad2))));

      if(draw_aspheric) {
        const int num_steps = 50;

        for(int j = 0; j <= num_steps; j++)
        {
          float y[] = {hrad*(2 * j / (float)num_steps - 1), 0};
          float *coeff = lenses[i].aspheric_correction_coefficients;
          float x = pos-evaluate_aspherical(y, rad, lenses[i].aspheric, coeff);
          cairo_line_to(cr, x, y[0]);
        }

        for(int j = num_steps; j >= 0; j--)
        {
          float y[] = {hrad2*(2 * j / (float)num_steps - 1), 0};
          float *coeff = lenses[i+1].aspheric_correction_coefficients;
          float x = pos-t-evaluate_aspherical(y, rad2, lenses[i+1].aspheric, coeff);
          cairo_line_to(cr, x, y[0]);
        }
      } else {
        cairo_arc(cr, pos-rad, 0.0f, fabsf(rad), off-alpha, off+alpha);
        if(rad * rad2 > 0.0f)
          cairo_arc_negative(cr, pos-t-rad2, 0.0f, fabsf(rad2), off2+alpha2, off2-alpha2);
        else
          cairo_arc(cr, pos-t-rad2, 0.0f, fabsf(rad2), off2-alpha2, off2+alpha2);
      }

      cairo_close_path(cr);
      
      if (!strcmp(lenses[i+1].geometry, "cyl-y") || !strcmp(lenses[i+1].geometry, "cyl-x")) cairo_set_source_rgba(cr, mint[0], mint[1], mint[2], 0.85);
      else if (!strcmp(lenses[i+1].geometry, "aspherical")) cairo_set_source_rgba(cr, green[0], green[1], green[2], 0.85);
      else cairo_set_source_rgba(cr, grey[0], grey[1], grey[2], 0.85);
      cairo_fill_preserve(cr);

      cairo_set_source_rgba(cr, lightgrey[0], lightgrey[1], lightgrey[2], lightgrey[3]);
      stroke_with_pencil(cr, scale, 70.0/width);

      cairo_restore(cr);

    } else {
      // backside (air-facing), actually drawn double most of the time
      cairo_save(cr);
      cairo_rectangle(cr, pos-rad-2, -hrad, 2*rad+4, 2*hrad);
      cairo_clip(cr);
      
      if(draw_aspheric) {
        const int num_steps = 50;

        for(int j = 0; j <= num_steps; j++) {
          float y[] = {hrad*(2 * j / (float)num_steps - 1), 0};
          float *coeff = lenses[i].aspheric_correction_coefficients;
          float x = pos-evaluate_aspherical(y, rad, lenses[i].aspheric, coeff);
          cairo_line_to(cr, x, y[0]);
        }
      } else {
        cairo_arc(cr, pos-rad, 0.0f, fabsf(rad), .0f, 2.0f*M_PI);
      }

      if (!strcmp(lenses[i].geometry, "cyl-y") || !strcmp(lenses[i].geometry, "cyl-x")) cairo_set_source_rgba(cr, mint[0], mint[1], mint[2], 0.85);
      else if (!strcmp(lenses[i].geometry, "aspherical")) cairo_set_source_rgba(cr, green[0], green[1], green[2], 0.85);
      else cairo_set_source_rgba(cr, grey[0], grey[1], grey[2], 0.85);

      cairo_set_source_rgba(cr, lightgrey[0], lightgrey[1], lightgrey[2], lightgrey[3]);
      stroke_with_pencil(cr, scale, 70.0/width);
      cairo_close_path(cr);
      cairo_fill(cr);

      cairo_restore(cr);
    }

    pos -= t;
  }

  draw_sensor(cr);
  draw_aperture(cr);

  
  if(screenshot) {
    cairo_surface_finish(svg_surface);
    cairo_surface_destroy(svg_surface);
    fmt::print("Saved lens drawing to '{}'\n", lens_svg_path);
    screenshot = !screenshot;
  }

  return FALSE;
}


int main(int argc, char *argv[])
{
  const char *id = argv[1];
  int lens_focal_length = atol(argv[2]);

  // read lens database
  std::string lens_database_path = fmt::format("{}/database/lenses.json", std::getenv("LENTIL_PATH"));
  std::ifstream in_json(lens_database_path.c_str());
  json lens_database = json::parse(in_json);

  for (const auto& i : lens_database[id]["polynomial-optics"]){
    if (i == lens_focal_length){
      std::string fit_location_exitpupil = fmt::format("{}/fitted/exitpupil.fit", find_lens_id_location(id, lens_focal_length));
      if(poly_system_read(&poly, fit_location_exitpupil.c_str())){
        fmt::print("[view] could not read poly system '{}'\n", fit_location_exitpupil.c_str());
      }
    } else {
      fmt::print("[view] no exitpupil poly system focal length {}\n", lens_focal_length);
    }
  }
  for (const auto& i : lens_database[id]["polynomial-optics-aperture"]){
    if (i == lens_focal_length){
      std::string fit_location_aperture = fmt::format("{}/fitted/aperture.fit", find_lens_id_location(id, lens_focal_length));
      if(poly_system_read(&poly_aperture, fit_location_aperture.c_str())){
        fmt::print("[view] could not read poly system '{}'\n", fit_location_aperture.c_str());
      }
    } else {
      fmt::print("[view] no aperture poly system focal length {}\n", lens_focal_length);
    }
  }


  lens_svg_path = fmt::format("{0}/database/lenses/{1}-{2}-{3}/{1}-{2}-{3}.svg", 
                              std::getenv("LENTIL_PATH"),
                              lens_database[id]["year"].get<int>(),
                              lens_database[id]["company"].get<std::string>(),
                              lens_database[id]["product-name"].get<std::string>()
  );


  lenses_cnt = lens_configuration(lenses, id, lens_focal_length);
  lens_length = 0;
  for(int i=0;i<lenses_cnt;i++) lens_length += lens_get_thickness(lenses+i, zoom);

  lens_pupil_dist = lens_get_thickness(lenses + lenses_cnt-1, zoom);
  lens_pupil_rad  = lenses[lenses_cnt-1].housing_radius;
  aperture_rad = lens_get_aperture_radius(lenses, lenses_cnt);


  // GTK window setup
  GtkWidget *window, *drawing_area;
  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect(window,"destroy", G_CALLBACK(gtk_main_quit), NULL);

  drawing_area = gtk_drawing_area_new();
  gtk_container_add(GTK_CONTAINER(window), drawing_area);
  gtk_widget_set_size_request (drawing_area, width, height);
  g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(draw_callback), NULL);

  gtk_widget_add_events(window, GDK_KEY_PRESS_MASK);
  g_signal_connect (G_OBJECT (window), "key_press_event", G_CALLBACK (on_keypress), NULL);

  gtk_widget_show_all(window);
  gtk_main();


  // cleanup
  poly_system_destroy(&poly);
  poly_system_destroy(&poly_aperture);

  return 0;
}
