case asahi__takumar__1970__35mm:
{
const double dx00 =  + -0.077231  + -0.00787569 *lambda + 0.333408 *lens_ipow(dy, 2) + 0.826914 *lens_ipow(dx, 2) + 0.0343351 *y*dy + 0.000576986 *lens_ipow(y, 2) + 0.10047 *x*dx + 0.00173135 *lens_ipow(x, 2) + 0.402836 *lens_ipow(dx, 4) + 0.000744982 *lens_ipow(y, 2)*lens_ipow(dx, 2) + 0.0490296 *x*lens_ipow(dx, 3) + -0.00257706 *x*y*dx*dy + -4.91766e-05 *lens_ipow(x, 2)*y*dy*lambda + -3.09719e-06 *x*lens_ipow(y, 3)*dx*dy + 0.00839213 *lens_ipow(x, 2)*lens_ipow(dy, 4) + -0.000348126 *lens_ipow(x, 2)*y*lens_ipow(dx, 2)*dy + -1.7607e-05 *lens_ipow(x, 3)*y*dx*dy + 6.50449e-06 *lens_ipow(x, 4)*lens_ipow(dy, 2) + -0.0113158 *lens_ipow(x, 2)*lens_ipow(dy, 4)*lens_ipow(lambda, 2)+0.0f;
const double dx01 =  + 0.537496 *dx*dy + 0.0332631 *y*dx + 0.0343351 *x*dy + 0.00115397 *x*y + 0.0318823 *y*dx*lens_ipow(dy, 2) + 0.0378363 *y*lens_ipow(dx, 3) + 0.00148996 *x*y*lens_ipow(dx, 2) + -0.00128853 *lens_ipow(x, 2)*dx*dy + -1.63922e-05 *lens_ipow(x, 3)*dy*lambda + -4.64579e-06 *lens_ipow(x, 2)*lens_ipow(y, 2)*dx*dy + -0.000116042 *lens_ipow(x, 3)*lens_ipow(dx, 2)*dy + -4.40175e-06 *lens_ipow(x, 4)*dx*dy+0.0f;
const double dx02 =  + 34.013  + 2.46685 *lambda + -1.89011 *lens_ipow(lambda, 2) + -7.30244 *lens_ipow(dy, 2) + -22.2808 *lens_ipow(dx, 2) + 0.537496 *y*dy + 0.0166315 *lens_ipow(y, 2) + 1.65383 *x*dx + 0.0502348 *lens_ipow(x, 2) + 0.0159411 *lens_ipow(y, 2)*lens_ipow(dy, 2) + 0.0567544 *lens_ipow(y, 2)*lens_ipow(dx, 2) + 1.61135 *x*lens_ipow(dx, 3) + 0.00148996 *x*lens_ipow(y, 2)*dx + 0.0735444 *lens_ipow(x, 2)*lens_ipow(dx, 2) + -0.00128853 *lens_ipow(x, 2)*y*dy + -1.5486e-06 *lens_ipow(x, 2)*lens_ipow(y, 3)*dy + -0.000232084 *lens_ipow(x, 3)*y*dx*dy + -4.40175e-06 *lens_ipow(x, 4)*y*dy+0.0f;
const double dx03 =  + -14.6049 *dx*dy + 0.537496 *y*dx + 0.666816 *x*dy + 0.0343351 *x*y + 0.0318823 *lens_ipow(y, 2)*dx*dy + -0.00128853 *lens_ipow(x, 2)*y*dx + -1.63922e-05 *lens_ipow(x, 3)*y*lambda + -1.5486e-06 *lens_ipow(x, 2)*lens_ipow(y, 3)*dx + 0.0111895 *lens_ipow(x, 3)*lens_ipow(dy, 3) + -0.000116042 *lens_ipow(x, 3)*y*lens_ipow(dx, 2) + -4.40175e-06 *lens_ipow(x, 4)*y*dx + 2.6018e-06 *lens_ipow(x, 5)*dy + -0.0150877 *lens_ipow(x, 3)*lens_ipow(dy, 3)*lens_ipow(lambda, 2)+0.0f;
const double dx04 =  + 2.46685 *dx + -0.00787569 *x + -3.78022 *dx*lambda + -1.63922e-05 *lens_ipow(x, 3)*y*dy + -0.00754384 *lens_ipow(x, 3)*lens_ipow(dy, 4)*lambda+0.0f;
const double dx10 =  + 0.578627 *dx*dy + 0.0340502 *y*dx + 0.0358348 *x*dy + 0.00116168 *x*y + -0.00145267 *lens_ipow(y, 2)*dx*dy + -1.82503e-05 *x*lens_ipow(y, 2)*dy + -0.00171746 *lens_ipow(x, 2)*dx*dy + -5.30131e-05 *lens_ipow(x, 3)*dy*lambda + -1.94661e-08 *lens_ipow(x, 2)*lens_ipow(y, 4)*dx*dy + 2.93999e-07 *lens_ipow(x, 5)*dy*lens_ipow(lambda, 4)+0.0f;
const double dx11 =  + -0.0774611  + -0.00816395 *lambda + 0.882954 *lens_ipow(dy, 2) + 0.321885 *lens_ipow(dx, 2) + 0.103734 *y*dy + 0.00174578 *lens_ipow(y, 2) + 0.0340502 *x*dx + 0.00058084 *lens_ipow(x, 2) + -0.00211514 *y*dy*lambda + 0.448028 *lens_ipow(dy, 4) + 0.0492647 *y*lens_ipow(dy, 3) + 0.00141134 *lens_ipow(y, 2)*lens_ipow(dx, 2) + -0.00290535 *x*y*dx*dy + -1.82503e-05 *lens_ipow(x, 2)*y*dy + -2.59548e-08 *lens_ipow(x, 3)*lens_ipow(y, 3)*dx*dy + 1.96237 *lens_ipow(y, 2)*lens_ipow(dx, 6)*lens_ipow(dy, 2) + 0.0671237 *lens_ipow(y, 3)*lens_ipow(dx, 6)*dy + 0.000658981 *lens_ipow(y, 4)*lens_ipow(dx, 6)+0.0f;
const double dx12 =  + -12.5115 *dx*dy + 0.64377 *y*dx + 0.578627 *x*dy + 0.0340502 *x*y + 0.000940892 *lens_ipow(y, 3)*dx + -0.00145267 *x*lens_ipow(y, 2)*dy + -0.000572487 *lens_ipow(x, 3)*dy + -6.48871e-09 *lens_ipow(x, 3)*lens_ipow(y, 4)*dy + 3.92475 *lens_ipow(y, 3)*lens_ipow(dx, 5)*lens_ipow(dy, 2) + 0.100686 *lens_ipow(y, 4)*lens_ipow(dx, 5)*dy + 0.000790777 *lens_ipow(y, 5)*lens_ipow(dx, 5)+0.0f;
const double dx13 =  + 33.8432  + 2.74914 *lambda + -2.03363 *lens_ipow(lambda, 2) + -18.2248 *lens_ipow(dy, 2) + -6.25575 *lens_ipow(dx, 2) + 1.76591 *y*dy + 0.0518671 *lens_ipow(y, 2) + 0.578627 *x*dx + 0.0179174 *lens_ipow(x, 2) + -0.00105757 *lens_ipow(y, 2)*lambda + 1.79211 *y*lens_ipow(dy, 3) + 0.0738971 *lens_ipow(y, 2)*lens_ipow(dy, 2) + -0.00145267 *x*lens_ipow(y, 2)*dx + -9.12517e-06 *lens_ipow(x, 2)*lens_ipow(y, 2) + -0.000572487 *lens_ipow(x, 3)*dx + -1.32533e-05 *lens_ipow(x, 4)*lambda + -6.48871e-09 *lens_ipow(x, 3)*lens_ipow(y, 4)*dx + 1.30825 *lens_ipow(y, 3)*lens_ipow(dx, 6)*dy + 0.0167809 *lens_ipow(y, 4)*lens_ipow(dx, 6) + 4.89998e-08 *lens_ipow(x, 6)*lens_ipow(lambda, 4)+0.0f;
const double dx14 =  + 2.74914 *dy + -0.00816395 *y + -4.06727 *dy*lambda + -0.00105757 *lens_ipow(y, 2)*dy + -1.32533e-05 *lens_ipow(x, 4)*dy + 1.95999e-07 *lens_ipow(x, 6)*dy*lens_ipow(lambda, 3)+0.0f;
const double dx20 =  + -0.0283593  + 0.000404443 *lambda + 0.00516284 *lens_ipow(dy, 2) + 0.000171135 *y*dy + 9.40061e-06 *lens_ipow(y, 2) + -0.00023994 *x*dx + 1.98703e-05 *lens_ipow(x, 2) + -0.00380207 *lens_ipow(dx, 2)*lambda + 0.514387 *lens_ipow(dx, 4) + 0.00138241 *x*dx*lens_ipow(dy, 2) + 0.0461492 *x*lens_ipow(dx, 3) + 0.00149307 *lens_ipow(x, 2)*lens_ipow(dx, 2) + -1.65947e-06 *lens_ipow(x, 2)*y*dy + -2.4306e-08 *lens_ipow(x, 2)*lens_ipow(y, 2) + 2.00382e-05 *lens_ipow(x, 3)*dx + 8.80096e-08 *lens_ipow(x, 4) + -7.6774e-07 *lens_ipow(y, 3)*lens_ipow(dy, 3) + -4.6337e-06 *lens_ipow(y, 3)*lens_ipow(dx, 2)*dy + -4.71013e-06 *x*lens_ipow(y, 2)*lens_ipow(dx, 3)*lambda + -4.83164e-11 *lens_ipow(x, 2)*lens_ipow(y, 4)*lambda+0.0f;
const double dx21 =  + 0.0115947 *dx*dy + 0.000270412 *y*dx + 0.000171135 *x*dy + 1.88012e-05 *x*y + -5.53155e-07 *lens_ipow(x, 3)*dy + -1.6204e-08 *lens_ipow(x, 3)*y + -0.0243593 *dx*lens_ipow(dy, 3)*lambda + -0.0191939 *lens_ipow(dx, 3)*dy*lambda + 9.49508e-06 *lens_ipow(y, 3)*lens_ipow(dx, 3) + -2.30322e-06 *x*lens_ipow(y, 2)*lens_ipow(dy, 3) + -1.39011e-05 *x*lens_ipow(y, 2)*lens_ipow(dx, 2)*dy + -4.71013e-06 *lens_ipow(x, 2)*y*lens_ipow(dx, 3)*lambda + -6.44219e-11 *lens_ipow(x, 3)*lens_ipow(y, 3)*lambda+0.0f;
const double dx22 =  + -0.22702  + 0.286552 *lens_ipow(dy, 2) + 0.0115947 *y*dy + 0.000135206 *lens_ipow(y, 2) + -0.00011997 *lens_ipow(x, 2) + -0.00760414 *x*dx*lambda + 24.0274 *lens_ipow(dx, 4) + 2.05755 *x*lens_ipow(dx, 3) + 0.000691205 *lens_ipow(x, 2)*lens_ipow(dy, 2) + 0.0692237 *lens_ipow(x, 2)*lens_ipow(dx, 2) + 0.000995377 *lens_ipow(x, 3)*dx + 5.00954e-06 *lens_ipow(x, 4) + -0.0243593 *y*lens_ipow(dy, 3)*lambda + -0.0575818 *y*lens_ipow(dx, 2)*dy*lambda + 7.12131e-06 *lens_ipow(y, 4)*lens_ipow(dx, 2) + -9.2674e-06 *x*lens_ipow(y, 3)*dx*dy + -7.0652e-06 *lens_ipow(x, 2)*lens_ipow(y, 2)*lens_ipow(dx, 2)*lambda+0.0f;
const double dx23 =  + 0.573104 *dx*dy + 0.0115947 *y*dx + 0.0103257 *x*dy + 0.000171135 *x*y + 0.00138241 *lens_ipow(x, 2)*dx*dy + -5.53155e-07 *lens_ipow(x, 3)*y + -0.0730778 *y*dx*lens_ipow(dy, 2)*lambda + -0.0191939 *y*lens_ipow(dx, 3)*lambda + -2.30322e-06 *x*lens_ipow(y, 3)*lens_ipow(dy, 2) + -4.6337e-06 *x*lens_ipow(y, 3)*lens_ipow(dx, 2)+0.0f;
const double dx24 =  + 0.000404443 *x + -0.00380207 *x*lens_ipow(dx, 2) + -0.0243593 *y*dx*lens_ipow(dy, 3) + -0.0191939 *y*lens_ipow(dx, 3)*dy + -2.35507e-06 *lens_ipow(x, 2)*lens_ipow(y, 2)*lens_ipow(dx, 3) + -1.61055e-11 *lens_ipow(x, 3)*lens_ipow(y, 4)+0.0f;
const double dx30 =  + 0.0125955 *dx*dy + 0.000126138 *y*dx + 0.000255138 *x*dy + 1.69821e-05 *x*y + -2.38566e-07 *lens_ipow(y, 3)*dx + -0.0260346 *lens_ipow(dx, 3)*dy*lambda + 0.0250034 *x*lens_ipow(dy, 5) + 0.00129022 *x*y*lens_ipow(dy, 4) + 1.77533e-05 *x*lens_ipow(y, 2)*lens_ipow(dy, 3) + -2.62861e-06 *lens_ipow(x, 2)*y*lens_ipow(dx, 3) + 1.32209e-09 *lens_ipow(x, 2)*lens_ipow(y, 4)*dx*dy + -4.2181e-13 *lens_ipow(x, 3)*lens_ipow(y, 5) + 1.54103e-08 *lens_ipow(x, 5)*lens_ipow(dy, 3)+0.0f;
const double dx31 =  + -0.0283847  + 0.000390904 *lambda + 0.0158023 *lens_ipow(dy, 2) + 0.00476643 *lens_ipow(dx, 2) + 0.000417736 *y*dy + 2.59414e-05 *lens_ipow(y, 2) + 0.000126138 *x*dx + 8.49105e-06 *lens_ipow(x, 2) + -0.00359898 *lens_ipow(dy, 2)*lambda + 0.000989702 *y*lens_ipow(dx, 2)*dy + -7.15698e-07 *x*lens_ipow(y, 2)*dx + 0.153887 *lens_ipow(dy, 4)*lambda + 0.0220717 *y*lens_ipow(dy, 3)*lambda + 0.00075867 *lens_ipow(y, 2)*lens_ipow(dy, 2)*lambda + 7.36833e-06 *lens_ipow(y, 3)*dy*lambda + 0.00064511 *lens_ipow(x, 2)*lens_ipow(dy, 4) + 1.77533e-05 *lens_ipow(x, 2)*y*lens_ipow(dy, 3) + -8.76202e-07 *lens_ipow(x, 3)*lens_ipow(dx, 3) + 1.76279e-09 *lens_ipow(x, 3)*lens_ipow(y, 3)*dx*dy + -5.27263e-13 *lens_ipow(x, 4)*lens_ipow(y, 4)+0.0f;
const double dx32 =  + 0.599542 *dx*dy + 0.00953286 *y*dx + 0.0125955 *x*dy + 0.000126138 *x*y + 0.000989702 *lens_ipow(y, 2)*dx*dy + -2.38566e-07 *x*lens_ipow(y, 3) + -0.0781037 *x*lens_ipow(dx, 2)*dy*lambda + -2.62861e-06 *lens_ipow(x, 3)*y*lens_ipow(dx, 2) + 4.40698e-10 *lens_ipow(x, 3)*lens_ipow(y, 4)*dy+0.0f;
const double dx33 =  + -0.230758  + 0.898954 *lens_ipow(dy, 2) + 0.299771 *lens_ipow(dx, 2) + 0.0316045 *y*dy + 0.000208868 *lens_ipow(y, 2) + 0.0125955 *x*dx + 0.000127569 *lens_ipow(x, 2) + -0.00719795 *y*dy*lambda + 0.000494851 *lens_ipow(y, 2)*lens_ipow(dx, 2) + 0.61555 *y*lens_ipow(dy, 3)*lambda + 0.0331075 *lens_ipow(y, 2)*lens_ipow(dy, 2)*lambda + 0.00050578 *lens_ipow(y, 3)*dy*lambda + 1.84208e-06 *lens_ipow(y, 4)*lambda + -0.0260346 *x*lens_ipow(dx, 3)*lambda + 0.0625084 *lens_ipow(x, 2)*lens_ipow(dy, 4) + 0.00258044 *lens_ipow(x, 2)*y*lens_ipow(dy, 3) + 2.663e-05 *lens_ipow(x, 2)*lens_ipow(y, 2)*lens_ipow(dy, 2) + 4.40698e-10 *lens_ipow(x, 3)*lens_ipow(y, 4)*dx + 7.70515e-09 *lens_ipow(x, 6)*lens_ipow(dy, 2)+0.0f;
const double dx34 =  + 0.000390904 *y + -0.00359898 *y*lens_ipow(dy, 2) + 0.153887 *y*lens_ipow(dy, 4) + 0.0110358 *lens_ipow(y, 2)*lens_ipow(dy, 3) + 0.00025289 *lens_ipow(y, 3)*lens_ipow(dy, 2) + 1.84208e-06 *lens_ipow(y, 4)*dy + -0.0260346 *x*lens_ipow(dx, 3)*dy+0.0f;
const double dx40 =  + -0.00152429 *dx + -3.79866e-05 *x + -0.000407693 *y*dx*dy + -1.35039e-05 *lens_ipow(y, 2)*dx + -0.000193039 *x*lens_ipow(dy, 2) + -2.73203e-05 *x*y*dy + -7.51388e-07 *x*lens_ipow(y, 2) + -2.26373e-07 *lens_ipow(x, 4)*dx + -4.85635e-09 *lens_ipow(x, 5) + 1.05333e-06 *lens_ipow(x, 4)*lens_ipow(dx, 3) + 5.36462e-12 *lens_ipow(x, 7) + -3.97535e-15 *lens_ipow(x, 3)*lens_ipow(y, 6) + -2.63457e-06 *lens_ipow(x, 4)*lens_ipow(dx, 5)+0.0f;
const double dx41 =  + -0.000303137 *dy + -0.0392203 *lens_ipow(dy, 3) + -0.00308518 *y*lens_ipow(dy, 2) + -0.000186661 *y*lens_ipow(dx, 2) + -9.49029e-05 *lens_ipow(y, 2)*dy + -1.15622e-06 *lens_ipow(y, 3) + -0.000407693 *x*dx*dy + -2.70078e-05 *x*y*dx + -1.36601e-05 *lens_ipow(x, 2)*dy + -7.51388e-07 *lens_ipow(x, 2)*y + -5.96302e-15 *lens_ipow(x, 4)*lens_ipow(y, 5)+0.0f;
const double dx42 =  + -0.0636713 *dx + -0.00152429 *x + -0.569313 *dx*lens_ipow(dy, 2) + -0.800685 *lens_ipow(dx, 3) + -0.000186661 *lens_ipow(y, 2)*dx + -0.000407693 *x*y*dy + -1.35039e-05 *x*lens_ipow(y, 2) + -4.52746e-08 *lens_ipow(x, 5) + 6.31997e-07 *lens_ipow(x, 5)*lens_ipow(dx, 2) + -2.63457e-06 *lens_ipow(x, 5)*lens_ipow(dx, 4)+0.0f;
const double dx43 =  + -0.0152742 *dy + -0.000303137 *y + -2.47862 *lens_ipow(dy, 3) + -0.569313 *lens_ipow(dx, 2)*dy + -0.117661 *y*lens_ipow(dy, 2) + -0.00308518 *lens_ipow(y, 2)*dy + -3.16343e-05 *lens_ipow(y, 3) + -0.000407693 *x*y*dx + -0.000193039 *lens_ipow(x, 2)*dy + -1.36601e-05 *lens_ipow(x, 2)*y+0.0f;
const double dx44 =  + 2.00858  + -8.75135 *lambda + 13.4665 *lens_ipow(lambda, 2) + -7.13333 *lens_ipow(lambda, 3)+0.0f;
} break;
