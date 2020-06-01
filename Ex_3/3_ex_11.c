#include <stdio.h>
#include <math.h>

//// a.)
void main() {

   double a;
   printf( "\nEnter first value a for the interval of integration [a,b] to calculate integral: ");
   scanf("%lf", &a );
   double b;
   printf( "\nEnter first value b for the interval of integration [a,b] to calculate integral: ");
   scanf("%lf", &b );
   int n;
   printf( "\nEnter value n for the number of smaller subintervals: ");
   scanf("%d", &n );

   printf( "\nYou entered values [a=%lf, b=%lf] and n=%d: ",a,b,n);


   double INT=0, FUN=0, xk=0;

   for (int k=0; k<=n ; k++) {  
     
        xk=a+k*(b-a)/n;
//
//        if (k==0 || k==n){FUN= sqrt(xk*xk+1) ;}
//        else{FUN=2*sqrt(xk*xk+1);}

        if (k==0 || k==n){FUN= sqrt(1-xk*xk) ;}
        else{FUN=2*sqrt(1-xk*xk);}
        INT=INT+FUN;

        }

   INT=INT*(b-a)/(2*n);

   printf( "\nThe value of the integral is: %lf \n",INT);


}

