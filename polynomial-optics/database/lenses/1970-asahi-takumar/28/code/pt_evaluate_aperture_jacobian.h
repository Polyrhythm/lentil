case asahi__takumar__1970__28mm:
{
const double dx00 =  + 0.586408  + 0.0133273 *lambda + 0.689564 *lens_ipow(dy, 2) + 1.86208 *lens_ipow(dx, 2) + 0.0527357 *y*dy + 0.000744863 *lens_ipow(y, 2) + 0.156041 *x*dx + 0.00221969 *lens_ipow(x, 2) + 9.3398e-05 *lens_ipow(x, 2)*lambda + 7.73494e-06 *lens_ipow(y, 3)*dy + -2.46403e-05 *lens_ipow(x, 3)*y*dx*dy + 4.39668e-07 *lens_ipow(x, 3)*lens_ipow(y, 2)*dx + 1.50085e-05 *lens_ipow(x, 4)*lens_ipow(dy, 2) + -2.67041e-09 *lens_ipow(x, 6) + -0.0795532 *y*lens_ipow(dy, 5)*lambda + 3.91849e-05 *lens_ipow(x, 2)*lens_ipow(y, 2)*lens_ipow(dx, 2)*lambda + 6.19435e-10 *lens_ipow(x, 2)*lens_ipow(y, 5)*dy + -3.37493e-05 *lens_ipow(x, 2)*lens_ipow(y, 2)*lens_ipow(dx, 2)*lens_ipow(lambda, 3)+0.0f;
const double dx01 =  + 1.11936 *dx*dy + 0.0466801 *y*dx + 0.0527357 *x*dy + 0.00148973 *x*y + 2.32048e-05 *x*lens_ipow(y, 2)*dy + -6.16008e-06 *lens_ipow(x, 4)*dx*dy + 2.19834e-07 *lens_ipow(x, 4)*y*dx + -0.0795532 *x*lens_ipow(dy, 5)*lambda + 2.61233e-05 *lens_ipow(x, 3)*y*lens_ipow(dx, 2)*lambda + 1.03239e-09 *lens_ipow(x, 3)*lens_ipow(y, 4)*dy + -2.24995e-05 *lens_ipow(x, 3)*y*lens_ipow(dx, 2)*lens_ipow(lambda, 3)+0.0f;
const double dx02 =  + 29.1443  + 0.52188 *lambda + 5.74335 *lens_ipow(dy, 2) + 18.2134 *lens_ipow(dx, 2) + 1.11936 *y*dy + 0.0233401 *lens_ipow(y, 2) + 3.72417 *x*dx + 0.0780203 *lens_ipow(x, 2) + -6.16008e-06 *lens_ipow(x, 4)*y*dy + 1.09917e-07 *lens_ipow(x, 4)*lens_ipow(y, 2) + 2.61233e-05 *lens_ipow(x, 3)*lens_ipow(y, 2)*dx*lambda + -2.24995e-05 *lens_ipow(x, 3)*lens_ipow(y, 2)*dx*lens_ipow(lambda, 3)+0.0f;
const double dx03 =  + 11.4867 *dx*dy + 1.11936 *y*dx + 1.37913 *x*dy + 0.0527357 *x*y + 7.73494e-06 *x*lens_ipow(y, 3) + -6.16008e-06 *lens_ipow(x, 4)*y*dx + 6.00342e-06 *lens_ipow(x, 5)*dy + -0.397766 *x*y*lens_ipow(dy, 4)*lambda + 2.06478e-10 *lens_ipow(x, 3)*lens_ipow(y, 5)+0.0f;
const double dx04 =  + 0.52188 *dx + 0.0133273 *x + 3.11327e-05 *lens_ipow(x, 3) + -0.0795532 *x*y*lens_ipow(dy, 5) + 1.30616e-05 *lens_ipow(x, 3)*lens_ipow(y, 2)*lens_ipow(dx, 2) + -3.37493e-05 *lens_ipow(x, 3)*lens_ipow(y, 2)*lens_ipow(dx, 2)*lens_ipow(lambda, 2)+0.0f;
const double dx10 =  + 1.14136 *dx*dy + 0.0537161 *y*dx + 0.0474892 *x*dy + 0.00150221 *x*y + 8.13457e-06 *x*lens_ipow(y, 3)*lens_ipow(dx, 2) + 1.76687e-07 *x*lens_ipow(y, 4)*dy + -1.3556e-05 *lens_ipow(x, 2)*lens_ipow(y, 2)*dx*dy + 2.96466e-07 *lens_ipow(x, 2)*lens_ipow(y, 3)*dx + 9.29209e-06 *lens_ipow(x, 3)*y*lens_ipow(dy, 2) + -2.13432e-09 *lens_ipow(x, 5)*y + -8.46395e-06 *lens_ipow(y, 4)*dx*dy*lambda + 1.40969e-05 *x*lens_ipow(y, 3)*lens_ipow(dy, 2)*lambda+0.0f;
const double dx11 =  + 0.584358  + 0.0171163 *lambda + 1.84181 *lens_ipow(dy, 2) + 0.705569 *lens_ipow(dx, 2) + 0.15461 *y*dy + 0.00225417 *lens_ipow(y, 2) + 0.0537161 *x*dx + 0.000751104 *lens_ipow(x, 2) + -2.79693e-09 *lens_ipow(y, 6) + 1.22019e-05 *lens_ipow(x, 2)*lens_ipow(y, 2)*lens_ipow(dx, 2) + 3.53375e-07 *lens_ipow(x, 2)*lens_ipow(y, 3)*dy + -9.03734e-06 *lens_ipow(x, 3)*y*dx*dy + 2.96466e-07 *lens_ipow(x, 3)*lens_ipow(y, 2)*dx + 2.32302e-06 *lens_ipow(x, 4)*lens_ipow(dy, 2) + -3.55721e-10 *lens_ipow(x, 6) + 2.13613e-05 *lens_ipow(y, 4)*lens_ipow(dx, 2)*lambda + -3.38558e-05 *x*lens_ipow(y, 3)*dx*dy*lambda + 2.11454e-05 *lens_ipow(x, 2)*lens_ipow(y, 2)*lens_ipow(dy, 2)*lambda+0.0f;
const double dx12 =  + 11.9777 *dx*dy + 1.41114 *y*dx + 1.14136 *x*dy + 0.0537161 *x*y + 8.13457e-06 *lens_ipow(x, 2)*lens_ipow(y, 3)*dx + -4.51867e-06 *lens_ipow(x, 3)*lens_ipow(y, 2)*dy + 9.88222e-08 *lens_ipow(x, 3)*lens_ipow(y, 3) + 8.54451e-06 *lens_ipow(y, 5)*dx*lambda + -8.46395e-06 *x*lens_ipow(y, 4)*dy*lambda+0.0f;
const double dx13 =  + 29.2795  + 0.491387 *lens_ipow(lambda, 2) + 17.8374 *lens_ipow(dy, 2) + 5.98883 *lens_ipow(dx, 2) + 3.68362 *y*dy + 0.0773049 *lens_ipow(y, 2) + 1.14136 *x*dx + 0.0237446 *lens_ipow(x, 2) + 8.83436e-08 *lens_ipow(x, 2)*lens_ipow(y, 4) + -4.51867e-06 *lens_ipow(x, 3)*lens_ipow(y, 2)*dx + 4.64604e-06 *lens_ipow(x, 4)*y*dy + -8.46395e-06 *x*lens_ipow(y, 4)*dx*lambda + 1.40969e-05 *lens_ipow(x, 2)*lens_ipow(y, 3)*dy*lambda+0.0f;
const double dx14 =  + 0.0171163 *y + 0.982775 *dy*lambda + 4.27225e-06 *lens_ipow(y, 5)*lens_ipow(dx, 2) + -8.46395e-06 *x*lens_ipow(y, 4)*dx*dy + 7.04847e-06 *lens_ipow(x, 2)*lens_ipow(y, 3)*lens_ipow(dy, 2)+0.0f;
const double dx20 =  + -0.012393  + -0.00342989 *lambda + 0.0544787 *lens_ipow(dy, 2) + 0.143822 *lens_ipow(dx, 2) + 0.0049875 *y*dy + 8.64731e-05 *lens_ipow(y, 2) + 0.0146198 *x*dx + 0.000258489 *lens_ipow(x, 2) + -0.00220865 *lens_ipow(y, 2)*lens_ipow(dx, 2)*lens_ipow(dy, 2) + -0.0014497 *lens_ipow(x, 2)*lens_ipow(dx, 4) + -0.0704794 *y*lens_ipow(dx, 2)*lens_ipow(dy, 3)*lens_ipow(lambda, 2) + -0.0260084 *x*lens_ipow(dx, 5)*lens_ipow(lambda, 2) + -2.84724e-05 *lens_ipow(x, 3)*y*lens_ipow(dx, 3)*dy + 3.58015e-08 *lens_ipow(x, 4)*lens_ipow(y, 2)*lens_ipow(dx, 4) + 1.74949e-11 *lens_ipow(x, 8)*lens_ipow(dy, 2)+0.0f;
const double dx21 =  + 0.0891675 *dx*dy + 0.00472793 *y*dx + 0.0049875 *x*dy + 0.000172946 *x*y + -0.00103927 *lens_ipow(y, 2)*dx*lens_ipow(dy, 3) + -0.00441731 *x*y*lens_ipow(dx, 2)*lens_ipow(dy, 2) + -0.0704794 *x*lens_ipow(dx, 2)*lens_ipow(dy, 3)*lens_ipow(lambda, 2) + -7.11809e-06 *lens_ipow(x, 4)*lens_ipow(dx, 3)*dy + -2.80461e-07 *lens_ipow(y, 5)*lens_ipow(dx, 3)*lambda + 1.43206e-08 *lens_ipow(x, 5)*y*lens_ipow(dx, 4)+0.0f;
const double dx22 =  + 1.23234  + -0.696853 *lambda + 0.428269 *lens_ipow(lambda, 2) + 1.14997 *lens_ipow(dy, 2) + 3.53671 *lens_ipow(dx, 2) + 0.0891675 *y*dy + 0.00236396 *lens_ipow(y, 2) + 0.287645 *x*dx + 0.00730991 *lens_ipow(x, 2) + -0.000346424 *lens_ipow(y, 3)*lens_ipow(dy, 3) + -0.00441731 *x*lens_ipow(y, 2)*dx*lens_ipow(dy, 2) + -0.00193294 *lens_ipow(x, 3)*lens_ipow(dx, 3) + -0.140959 *x*y*dx*lens_ipow(dy, 3)*lens_ipow(lambda, 2) + -0.065021 *lens_ipow(x, 2)*lens_ipow(dx, 4)*lens_ipow(lambda, 2) + -2.13543e-05 *lens_ipow(x, 4)*y*lens_ipow(dx, 2)*dy + -1.40231e-07 *lens_ipow(y, 6)*lens_ipow(dx, 2)*lambda + 2.86412e-08 *lens_ipow(x, 5)*lens_ipow(y, 2)*lens_ipow(dx, 3)+0.0f;
const double dx23 =  + 2.29994 *dx*dy + 0.0891675 *y*dx + 0.108957 *x*dy + 0.0049875 *x*y + -0.00103927 *lens_ipow(y, 3)*dx*lens_ipow(dy, 2) + -0.00441731 *x*lens_ipow(y, 2)*lens_ipow(dx, 2)*dy + -0.211438 *x*y*lens_ipow(dx, 2)*lens_ipow(dy, 2)*lens_ipow(lambda, 2) + -7.11809e-06 *lens_ipow(x, 4)*y*lens_ipow(dx, 3) + 3.88776e-12 *lens_ipow(x, 9)*dy+0.0f;
const double dx24 =  + -0.696853 *dx + -0.00342989 *x + 0.856538 *dx*lambda + -0.140959 *x*y*lens_ipow(dx, 2)*lens_ipow(dy, 3)*lambda + -0.0260084 *lens_ipow(x, 2)*lens_ipow(dx, 5)*lambda + -4.67436e-08 *lens_ipow(y, 6)*lens_ipow(dx, 3)+0.0f;
const double dx30 =  + 0.0887055 *dx*dy + 0.00481934 *y*dx + 0.00474443 *x*dy + 0.000174519 *x*y + -0.000123678 *lens_ipow(y, 2)*dx*dy + 2.37978e-06 *lens_ipow(x, 2)*y*dx + -0.000913082 *lens_ipow(x, 2)*lens_ipow(dx, 3)*dy + 0.000120368 *lens_ipow(y, 3)*dx*lens_ipow(dy, 4) + 0.000823722 *x*lens_ipow(y, 2)*lens_ipow(dx, 2)*lens_ipow(dy, 3) + -5.77886e-07 *lens_ipow(x, 3)*lens_ipow(y, 2)*lens_ipow(dy, 3)*lambda+0.0f;
const double dx31 =  + -0.0123109  + -0.00358083 *lambda + 0.139243 *lens_ipow(dy, 2) + 0.0523224 *lens_ipow(dx, 2) + 0.0142719 *y*dy + 0.000254091 *lens_ipow(y, 2) + 0.00481934 *x*dx + 8.72597e-05 *lens_ipow(x, 2) + -0.000247356 *x*y*dx*dy + 7.93259e-07 *lens_ipow(x, 3)*dx + -0.00163995 *lens_ipow(y, 2)*lens_ipow(dy, 4) + 1.61176e-06 *lens_ipow(y, 4)*lens_ipow(dx, 2)*lambda + 0.000361103 *x*lens_ipow(y, 2)*dx*lens_ipow(dy, 4) + 0.000823722 *lens_ipow(x, 2)*y*lens_ipow(dx, 2)*lens_ipow(dy, 3) + 0.00498304 *lens_ipow(y, 2)*lens_ipow(dy, 6)*lambda + -2.88943e-07 *lens_ipow(x, 4)*y*lens_ipow(dy, 3)*lambda+0.0f;
const double dx32 =  + 2.24871 *dx*dy + 0.104645 *y*dx + 0.0887055 *x*dy + 0.00481934 *x*y + -0.000123678 *x*lens_ipow(y, 2)*dy + 7.93259e-07 *lens_ipow(x, 3)*y + -0.000913082 *lens_ipow(x, 3)*lens_ipow(dx, 2)*dy + 6.44704e-07 *lens_ipow(y, 5)*dx*lambda + 0.000120368 *x*lens_ipow(y, 3)*lens_ipow(dy, 4) + 0.000823722 *lens_ipow(x, 2)*lens_ipow(y, 2)*dx*lens_ipow(dy, 3)+0.0f;
const double dx33 =  + 1.22815  + -0.66154 *lambda + 0.386276 *lens_ipow(lambda, 2) + 3.32408 *lens_ipow(dy, 2) + 1.12436 *lens_ipow(dx, 2) + 0.278485 *y*dy + 0.00713593 *lens_ipow(y, 2) + 0.0887055 *x*dx + 0.00237222 *lens_ipow(x, 2) + -0.000123678 *x*lens_ipow(y, 2)*dx + -0.0021866 *lens_ipow(y, 3)*lens_ipow(dy, 3) + -0.000304361 *lens_ipow(x, 3)*lens_ipow(dx, 3) + 0.000481471 *x*lens_ipow(y, 3)*dx*lens_ipow(dy, 3) + 0.00123558 *lens_ipow(x, 2)*lens_ipow(y, 2)*lens_ipow(dx, 2)*lens_ipow(dy, 2) + 0.00996608 *lens_ipow(y, 3)*lens_ipow(dy, 5)*lambda + -4.33414e-07 *lens_ipow(x, 4)*lens_ipow(y, 2)*lens_ipow(dy, 2)*lambda+0.0f;
const double dx34 =  + -0.66154 *dy + -0.00358083 *y + 0.772552 *dy*lambda + 3.22352e-07 *lens_ipow(y, 5)*lens_ipow(dx, 2) + 0.00166101 *lens_ipow(y, 3)*lens_ipow(dy, 6) + -1.44471e-07 *lens_ipow(x, 4)*lens_ipow(y, 2)*lens_ipow(dy, 3)+0.0f;
const double dx40 =  + -0.0596616 *lens_ipow(dx, 3) + -0.00126886 *y*dx*dy + -5.42977e-05 *lens_ipow(y, 2)*dx + -0.000529903 *x*lens_ipow(dy, 2) + -0.00574605 *x*lens_ipow(dx, 2) + -0.000104692 *x*y*dy + -3.35448e-06 *x*lens_ipow(y, 2) + -0.000245209 *lens_ipow(x, 2)*dx + -3.64669e-06 *lens_ipow(x, 3) + -1.80679e-09 *lens_ipow(x, 5) + -1.77182e-11 *lens_ipow(x, 3)*lens_ipow(y, 4)+0.0f;
const double dx41 =  + -0.00122756 *dy + -0.00258709 *y*lens_ipow(dy, 2) + -0.000658641 *y*lens_ipow(dx, 2) + -0.000193112 *lens_ipow(y, 2)*dy + -3.79569e-06 *lens_ipow(y, 3) + -0.00126886 *x*dx*dy + -0.000108595 *x*y*dx + -5.23461e-05 *lens_ipow(x, 2)*dy + -3.35448e-06 *lens_ipow(x, 2)*y + -1.77182e-11 *lens_ipow(x, 4)*lens_ipow(y, 3) + -9.23273e-15 *lens_ipow(y, 9)+0.0f;
const double dx42 =  + -0.581259 *dx*lens_ipow(dy, 2) + -3.48033 *lens_ipow(dx, 3) + -0.000658641 *lens_ipow(y, 2)*dx + -0.178985 *x*lens_ipow(dx, 2) + -0.00126886 *x*y*dy + -5.42977e-05 *x*lens_ipow(y, 2) + -0.00574605 *lens_ipow(x, 2)*dx + -8.17363e-05 *lens_ipow(x, 3)+0.0f;
const double dx43 =  + -0.0843882 *dy + -0.00122756 *y + -0.581259 *lens_ipow(dx, 2)*dy + -0.00258709 *lens_ipow(y, 2)*dy + -6.43706e-05 *lens_ipow(y, 3) + -0.00126886 *x*y*dx + -0.000529903 *lens_ipow(x, 2)*dy + -5.23461e-05 *lens_ipow(x, 2)*y+0.0f;
const double dx44 =  + 0.814393  + -2.23469 *lambda + 1.61963 *lens_ipow(lambda, 2)+0.0f;
} break;
