#include <stdio.h>
#include <math.h>
#include <stdbool.h>


void area(double *a,double *b,double *c, double *s,double *A);
bool check(double *a,double *b,double *c);
double s, A;

void main(){

    double a, b, c;
    bool CH=false;


		printf ("\nEnter the triangle lenghts to calculate its area.\n");

		printf ("\na=");
		scanf ("%lf", &a); 
		printf ("\nb=");
		scanf ("%lf", &b); 
		printf ("\nc=");
		scanf ("%lf", &c); 

          CH=check(&a,&b,&c);


    if (!CH) printf ("\nThe input  lengths can not construct a trinagle!\n\n");

    else {
        area( &a,&b,&c, &s, &A);
        printf("\nThe area of a triangle with perimeter s=%lf is A=%lf. \n\n", s, A);
        }
}


void area(double *a,double *b,double *c, double *s,double *A){
    
    *s=0.5*(*a+*b+*c);

    *A=sqrt(*s * (*s-*a) * (*s-*b) * (*s-*c));

}

bool check(double *a,double *b,double *c){

    if ((*a>=*b) && (*a>=*c)){  
        if (*a>=(*b+*c)) return false;
        else return true;
        }
    else if (*b>=*a && *b>=*c){  
        if (*b>=(*a+*c)) return false;
        else return true;
        }       
    else if (*c>=*a && *c>=*b){  
        if (*c>=(*a+*b)) return false;
        else return true;
        }
         
}