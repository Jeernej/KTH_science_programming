#include <stdio.h>
#include <math.h>

double f(double x) {
return (x-cos(x));
}

double fprime(double x) {
return (1+sin(x));
}

main() {

//    float dx=1, x=0.5;
    double dx=1, x=0.5;  // to reach the 1e-12 accuracy one needs double precision !!!
    int    i=0;
    
    while (fabs(dx) > 1e-12) {
        dx = -f(x) / fprime(x);
        x = x + dx;
        printf("%3d %17.12f %15e\n", ++i, x, fabs(dx));

    }        
}