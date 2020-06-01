#include <stdio.h>
#include <math.h>

//typedef struct {
//    double re;
//    double im;
//} Complex;
void roots(double *a,double *b,double *c,double *D,double *x1,double *x2,double *x12);
void swapper(double *x1,double *x2);

void main(){

    double a, b, c, D, x1, x2, x12 ;

		printf ("Enter the coefficients of  a quadratic equation 'a * x^2 + b *x + c = 0 ' to calculate the roots.\n");

		printf ("\na=");
		scanf ("%lf", &a); 
		printf ("\nb=");
		scanf ("%lf", &b); 
		printf ("\nc=");
		scanf ("%lf", &c); 

          roots( &a,&b,&c, &D, &x1, &x2, &x12 );


    if (D<0) printf ("\n Error - for this coefficients the equation yields imaginary roots\n\n");
    
    else if (D==0) printf("\nThe value of double root is x12=%lf. \n\n", x12);

    else {
        swapper(&x1,&x2);
        printf("\nThe roots are x1=%lf and x2=%lf. \n\n", x1,x2);
        }
}


void roots(double *a,double *b,double *c,double *D,double *x1,double *x2,double *x12){
    
    *D=*b**b-4**a**c;

    if (*D<0)  return 0; //printf ("\n Error - for this coefficients the equation yields imaginary roots\n\n");
    
    else if (*D==0) {
        *x12=(-*b-sqrt(*D))/(2**a);
//        printf("\nThe value of double root is x12=%lf. \n\n", x12);

    }

    else{
        *x1=(-*b-sqrt(*D))/(2**a);
        *x2=(-*b+sqrt(*D))/(2**a);
//        printf("\nThe roots are x1=%lf and x2=%lf. \n\n", x1,x2);
    }
}

void swapper(double *x1,double *x2){

    

    if (*x1<*x2){  
//        double temp;
        double temp=*x2;
        *x2=*x1;
        *x1=temp;
    }
}