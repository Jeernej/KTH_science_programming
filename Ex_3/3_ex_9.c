#include <stdio.h>
#include <math.h>

//// a.)
void main() {

   double x;
   printf( "\nEnter value x to calculate e^x: ");
   scanf("%lf", &x );
   int N;
   printf( "\nYou entered x=%lf , now enter N>0 for the sum length: ",x);
   scanf("%d", &N );
   printf( "\nYou entered N=%d \n: ",N);

   double xn=1,I=1,Ex=1;
   for (int i=1; i<=N ; i++) {       
        xn=xn*x;
        I=I*i;
        Ex=Ex+(xn/I);
        }

   printf( "\nThe sum is: %lf \n",Ex);

   printf( "\nThis differs from the true value of %lf for %lf \n \n",exp(x), exp(x)-Ex );

}