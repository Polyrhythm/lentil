case asahi__takumar__1969__58mm:
{
const double dx00 =  + -0.0308817  + 0.050174 *lambda + 0.577339 *lens_ipow(dx, 2) + 0.0130109 *y*dy + -0.000330382 *lens_ipow(y, 2) + 0.0425088 *x*dx + -0.00134931 *lens_ipow(x, 2) + 1.69639 *lens_ipow(dy, 2)*lambda + 0.000128385 *lens_ipow(y, 2)*lambda + 0.00131433 *lens_ipow(x, 2)*lambda + -1.58964 *lens_ipow(dy, 2)*lens_ipow(lambda, 2) + 0.000337425 *lens_ipow(y, 2)*lens_ipow(dy, 2) + 0.00104155 *lens_ipow(x, 2)*lens_ipow(dy, 2) + -1.3385 *lens_ipow(dx, 2)*lens_ipow(dy, 2)*lambda + -7.18387e-05 *lens_ipow(x, 3)*dx*lambda + -3.64186e-09 *lens_ipow(x, 2)*lens_ipow(y, 4) + 0.281565 *x*lens_ipow(dx, 5)*lambda + -6.35557e-06 *lens_ipow(x, 4)*lens_ipow(lambda, 3) + -1.06974e-11 *lens_ipow(x, 6)*lens_ipow(y, 2)+0.0f;
const double dx01 =  + 0.0123537 *y*dx + 0.0130109 *x*dy + -0.000660765 *x*y + 0.00025677 *x*y*lambda + 0.000674851 *x*y*lens_ipow(dy, 2) + -4.85581e-09 *lens_ipow(x, 3)*lens_ipow(y, 3) + -3.05639e-12 *lens_ipow(x, 7)*y+0.0f;
const double dx02 =  + 57.7741  + 0.613972 *lens_ipow(lambda, 2) + -24.4595 *lens_ipow(dy, 2) + -71.2079 *lens_ipow(dx, 2) + 0.00617687 *lens_ipow(y, 2) + 1.15468 *x*dx + 0.0212544 *lens_ipow(x, 2) + -2.67701 *x*dx*lens_ipow(dy, 2)*lambda + -1.79597e-05 *lens_ipow(x, 4)*lambda + 0.703912 *lens_ipow(x, 2)*lens_ipow(dx, 4)*lambda+0.0f;
const double dx03 =  + -48.9189 *dx*dy + 0.0130109 *x*y + 3.39279 *x*dy*lambda + -3.17927 *x*dy*lens_ipow(lambda, 2) + 0.000674851 *x*lens_ipow(y, 2)*dy + 0.000694369 *lens_ipow(x, 3)*dy + -2.67701 *x*lens_ipow(dx, 2)*dy*lambda+0.0f;
const double dx04 =  + 0.050174 *x + 1.22794 *dx*lambda + 1.69639 *x*lens_ipow(dy, 2) + 0.000128385 *x*lens_ipow(y, 2) + 0.000438111 *lens_ipow(x, 3) + -3.17927 *x*lens_ipow(dy, 2)*lambda + -1.3385 *x*lens_ipow(dx, 2)*lens_ipow(dy, 2) + -1.79597e-05 *lens_ipow(x, 4)*dx + 0.140782 *lens_ipow(x, 2)*lens_ipow(dx, 5) + -3.81334e-06 *lens_ipow(x, 5)*lens_ipow(lambda, 2)+0.0f;
const double dx10 =  + 0.0129471 *y*dx + 0.012379 *x*dy + -0.000671245 *x*y + 0.000245197 *x*y*lambda + 0.000656255 *x*y*lens_ipow(dx, 2) + -5.27396e-12 *x*lens_ipow(y, 7) + -1.95747e-11 *lens_ipow(x, 5)*lens_ipow(y, 3)+0.0f;
const double dx11 =  + -0.0294735  + 0.049727 *lambda + 0.58088 *lens_ipow(dy, 2) + 0.0426007 *y*dy + -0.00139008 *lens_ipow(y, 2) + 0.0129471 *x*dx + -0.000335623 *lens_ipow(x, 2) + 1.66746 *lens_ipow(dx, 2)*lambda + 0.00129123 *lens_ipow(y, 2)*lambda + 0.000122598 *lens_ipow(x, 2)*lambda + -1.54388 *lens_ipow(dx, 2)*lens_ipow(lambda, 2) + 0.00107753 *lens_ipow(y, 2)*lens_ipow(dx, 2) + 0.000328128 *lens_ipow(x, 2)*lens_ipow(dx, 2) + -1.36066 *lens_ipow(dx, 2)*lens_ipow(dy, 2)*lambda + -7.18102e-05 *lens_ipow(y, 3)*dy*lambda + 0.27703 *y*lens_ipow(dy, 5)*lambda + -8.15278e-06 *lens_ipow(y, 4)*lens_ipow(lambda, 4) + -1.84588e-11 *lens_ipow(x, 2)*lens_ipow(y, 6) + -9.78733e-12 *lens_ipow(x, 6)*lens_ipow(y, 2)+0.0f;
const double dx12 =  + -48.9652 *dx*dy + 0.0129471 *x*y + 3.33491 *y*dx*lambda + -3.08776 *y*dx*lens_ipow(lambda, 2) + 0.000718352 *lens_ipow(y, 3)*dx + 0.000656255 *lens_ipow(x, 2)*y*dx + -2.72132 *y*dx*lens_ipow(dy, 2)*lambda+0.0f;
const double dx13 =  + 57.7731  + 0.602644 *lens_ipow(lambda, 2) + -70.964 *lens_ipow(dy, 2) + -24.4826 *lens_ipow(dx, 2) + 1.16176 *y*dy + 0.0213003 *lens_ipow(y, 2) + 0.00618951 *lens_ipow(x, 2) + -2.72132 *y*lens_ipow(dx, 2)*dy*lambda + -1.79525e-05 *lens_ipow(y, 4)*lambda + 0.692576 *lens_ipow(y, 2)*lens_ipow(dy, 4)*lambda+0.0f;
const double dx14 =  + 0.049727 *y + 1.20529 *dy*lambda + 1.66746 *y*lens_ipow(dx, 2) + 0.000430412 *lens_ipow(y, 3) + 0.000122598 *lens_ipow(x, 2)*y + -3.08776 *y*lens_ipow(dx, 2)*lambda + -1.36066 *y*lens_ipow(dx, 2)*lens_ipow(dy, 2) + -1.79525e-05 *lens_ipow(y, 4)*dy + 0.138515 *lens_ipow(y, 2)*lens_ipow(dy, 5) + -6.52222e-06 *lens_ipow(y, 5)*lens_ipow(lambda, 3)+0.0f;
const double dx20 =  + -0.0153871  + -0.00554684 *lambda + 0.00401261 *lens_ipow(lambda, 2) + -0.000185438 *y*dy + 6.04255e-06 *lens_ipow(y, 2) + -0.000238817 *x*dx + 1.77825e-05 *lens_ipow(x, 2) + -0.0245715 *lens_ipow(dy, 2)*lambda + 3.98393e-05 *x*y*dx*dy + -1.425e-06 *lens_ipow(x, 3)*dx + 0.0561268 *lens_ipow(dy, 2)*lens_ipow(lambda, 3) + 1.2385e-06 *lens_ipow(x, 3)*dx*lambda + -0.0548824 *lens_ipow(dy, 2)*lens_ipow(lambda, 5) + -2.70906e-05 *lens_ipow(y, 3)*lens_ipow(dx, 2)*lens_ipow(dy, 3) + 3.13825e-05 *lens_ipow(x, 3)*dx*lens_ipow(dy, 4) + 9.50663e-13 *lens_ipow(x, 4)*lens_ipow(y, 4) + -1.01372e-12 *lens_ipow(x, 4)*lens_ipow(y, 4)*lambda+0.0f;
const double dx21 =  + 6.09703e-05 *y*dx + -0.000185438 *x*dy + 1.20851e-05 *x*y + -0.0020329 *dx*dy*lambda + 2.21771e-05 *lens_ipow(y, 2)*dx*dy + 1.99197e-05 *lens_ipow(x, 2)*dx*dy + 0.000717623 *y*lens_ipow(dx, 3)*lambda + -8.12717e-05 *x*lens_ipow(y, 2)*lens_ipow(dx, 2)*lens_ipow(dy, 3) + 7.6053e-13 *lens_ipow(x, 5)*lens_ipow(y, 3) + -8.10972e-13 *lens_ipow(x, 5)*lens_ipow(y, 3)*lambda+0.0f;
const double dx22 =  + -0.908304  + 0.0841608 *lens_ipow(dy, 2) + 1.24345 *lens_ipow(dx, 2) + 3.04851e-05 *lens_ipow(y, 2) + -0.000119408 *lens_ipow(x, 2) + -0.0020329 *y*dy*lambda + 7.39235e-06 *lens_ipow(y, 3)*dy + 1.99197e-05 *lens_ipow(x, 2)*y*dy + -3.5625e-07 *lens_ipow(x, 4) + 0.00107643 *lens_ipow(y, 2)*lens_ipow(dx, 2)*lambda + 3.09625e-07 *lens_ipow(x, 4)*lambda + -5.41811e-05 *x*lens_ipow(y, 3)*dx*lens_ipow(dy, 3) + 7.84563e-06 *lens_ipow(x, 4)*lens_ipow(dy, 4)+0.0f;
const double dx23 =  + 0.168322 *dx*dy + -0.000185438 *x*y + -0.0020329 *y*dx*lambda + -0.0491431 *x*dy*lambda + 7.39235e-06 *lens_ipow(y, 3)*dx + 1.99197e-05 *lens_ipow(x, 2)*y*dx + 0.112254 *x*dy*lens_ipow(lambda, 3) + -0.109765 *x*dy*lens_ipow(lambda, 5) + -8.12717e-05 *x*lens_ipow(y, 3)*lens_ipow(dx, 2)*lens_ipow(dy, 2) + 3.13825e-05 *lens_ipow(x, 4)*dx*lens_ipow(dy, 3)+0.0f;
const double dx24 =  + -0.00554684 *x + 0.00802523 *x*lambda + -0.0020329 *y*dx*dy + -0.0245715 *x*lens_ipow(dy, 2) + 0.000358812 *lens_ipow(y, 2)*lens_ipow(dx, 3) + 0.168381 *x*lens_ipow(dy, 2)*lens_ipow(lambda, 2) + 3.09625e-07 *lens_ipow(x, 4)*dx + -0.274412 *x*lens_ipow(dy, 2)*lens_ipow(lambda, 4) + -2.02743e-13 *lens_ipow(x, 5)*lens_ipow(y, 4)+0.0f;
const double dx30 =  + 0.0134282 *dx*dy + -0.0001819 *y*dx + 1.15117e-05 *x*y + 0.00087816 *x*lens_ipow(dy, 3) + 0.00139603 *x*lens_ipow(dx, 2)*dy + 2.00456e-05 *lens_ipow(x, 2)*dx*dy + -2.46812e-06 *lens_ipow(y, 3)*dx*lens_ipow(dy, 2) + 9.52368e-08 *lens_ipow(x, 3)*y*lens_ipow(dy, 2) + 1.98511e-10 *lens_ipow(x, 3)*lens_ipow(y, 3) + -2.34041e-10 *lens_ipow(x, 3)*lens_ipow(y, 3)*lambda + 7.58675e-14 *x*lens_ipow(y, 7)+0.0f;
const double dx31 =  + -0.0154621  + -0.00532167 *lambda + 0.00385934 *lens_ipow(lambda, 2) + -0.00634462 *lens_ipow(dx, 2) + -0.000351627 *y*dy + 1.77906e-05 *lens_ipow(y, 2) + -0.0001819 *x*dx + 5.75584e-06 *lens_ipow(x, 2) + 0.000172001 *y*dy*lambda + -1.59985e-05 *lens_ipow(y, 2)*lens_ipow(dx, 2) + -6.20812e-07 *lens_ipow(y, 3)*dy + -0.000273953 *lens_ipow(y, 2)*lens_ipow(dx, 2)*lens_ipow(dy, 2) + -7.40436e-06 *x*lens_ipow(y, 2)*dx*lens_ipow(dy, 2) + 2.38092e-08 *lens_ipow(x, 4)*lens_ipow(dy, 2) + 1.48883e-10 *lens_ipow(x, 4)*lens_ipow(y, 2) + -1.75531e-10 *lens_ipow(x, 4)*lens_ipow(y, 2)*lambda + 2.65536e-13 *lens_ipow(x, 2)*lens_ipow(y, 6)+0.0f;
const double dx32 =  + 1.4087 *dx*dy + -0.0126892 *y*dx + 0.0134282 *x*dy + -0.0001819 *x*y + -1.06656e-05 *lens_ipow(y, 3)*dx + 0.00139603 *lens_ipow(x, 2)*dx*dy + 6.68186e-06 *lens_ipow(x, 3)*dy + -0.000182635 *lens_ipow(y, 3)*dx*lens_ipow(dy, 2) + -2.46812e-06 *x*lens_ipow(y, 3)*lens_ipow(dy, 2)+0.0f;
const double dx33 =  + -0.904689  + 1.17187 *lens_ipow(dy, 2) + 0.70435 *lens_ipow(dx, 2) + -0.000175813 *lens_ipow(y, 2) + 0.0134282 *x*dx + 8.60007e-05 *lens_ipow(y, 2)*lambda + -1.55203e-07 *lens_ipow(y, 4) + 0.00131724 *lens_ipow(x, 2)*lens_ipow(dy, 2) + 0.000698016 *lens_ipow(x, 2)*lens_ipow(dx, 2) + 6.68186e-06 *lens_ipow(x, 3)*dx + -0.000182635 *lens_ipow(y, 3)*lens_ipow(dx, 2)*dy + -4.93624e-06 *x*lens_ipow(y, 3)*dx*dy + 4.76184e-08 *lens_ipow(x, 4)*y*dy+0.0f;
const double dx34 =  + -0.00532167 *y + 0.00771867 *y*lambda + 8.60007e-05 *lens_ipow(y, 2)*dy + -5.85103e-11 *lens_ipow(x, 4)*lens_ipow(y, 3)+0.0f;
const double dx40 =  + -1.09653e-05 *x + -0.000818915 *dx*lambda + -0.0167656 *dx*lens_ipow(dy, 2) + -0.000473471 *y*dx*dy + -0.00025621 *x*lens_ipow(dy, 2) + -0.0289851 *lens_ipow(dx, 3)*lambda + -0.00127163 *x*lens_ipow(dx, 2)*lambda + -1.41703e-14 *lens_ipow(x, 5)*lens_ipow(y, 4)+0.0f;
const double dx41 =  + -0.00023108 *dy + -0.0187692 *lens_ipow(dy, 3) + -0.0165798 *lens_ipow(dx, 2)*dy + -0.000909708 *y*lens_ipow(dy, 2) + -0.000263361 *y*lens_ipow(dx, 2) + -0.000473471 *x*dx*dy + -1.59682e-07 *lens_ipow(y, 3)*lambda + -1.69813e-05 *lens_ipow(y, 2)*dy*lens_ipow(lambda, 2) + -9.44689e-15 *lens_ipow(x, 6)*lens_ipow(y, 3)+0.0f;
const double dx42 =  + -0.000818915 *x*lambda + -1.83951 *dx*lens_ipow(dy, 2) + -0.947243 *lens_ipow(dx, 3) + -0.0331597 *y*dx*dy + -0.000263361 *lens_ipow(y, 2)*dx + -0.0167656 *x*lens_ipow(dy, 2) + -0.000473471 *x*y*dy + -1.55363 *lens_ipow(dx, 3)*lambda + -0.0869552 *x*lens_ipow(dx, 2)*lambda + -0.00127163 *lens_ipow(x, 2)*dx*lambda+0.0f;
const double dx43 =  + -0.00023108 *y + -1.63753 *lens_ipow(dy, 3) + -1.83951 *lens_ipow(dx, 2)*dy + -0.0563075 *y*lens_ipow(dy, 2) + -0.0165798 *y*lens_ipow(dx, 2) + -0.000909708 *lens_ipow(y, 2)*dy + -0.0335311 *x*dx*dy + -0.000473471 *x*y*dx + -0.00025621 *lens_ipow(x, 2)*dy + -5.66045e-06 *lens_ipow(y, 3)*lens_ipow(lambda, 2) + -5.39205 *lens_ipow(dy, 5)*lens_ipow(lambda, 2)+0.0f;
const double dx44 =  + 2.1378  + -9.4833 *lambda + 14.8182 *lens_ipow(lambda, 2) + -0.000818915 *x*dx + -7.95188 *lens_ipow(lambda, 3) + -0.388407 *lens_ipow(dx, 4) + -3.99206e-08 *lens_ipow(y, 4) + -0.0289851 *x*lens_ipow(dx, 3) + -0.000635817 *lens_ipow(x, 2)*lens_ipow(dx, 2) + -1.13209e-05 *lens_ipow(y, 3)*dy*lambda + -1.79735 *lens_ipow(dy, 6)*lambda+0.0f;
} break;
