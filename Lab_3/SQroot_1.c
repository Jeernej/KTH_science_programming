#include <stdio.h>
#include <math.h>
//The method will usually converge, 
//provided this initial guess is close enough to the unknown zero, 
//and that f ′(x0) ≠ 0. 
//
//float x=2
//float guess=1
//float acc=10^(-4)
//
//int Imax=100

int i=1; //global


float squareRoot(float x, float guess, float acc, int Imax)
{
//    printf(" acc-\n %f\n", acc);
    while((float) fabs(guess*guess - x) > acc && i<Imax){
        guess = ( guess + (x/guess) ) / 2.0;
//        printf("the value of gues is-%f \n",((float)fabs(guess*guess - x)));
        i=i+1;
        
        }

    return guess;//,i;
}

void main() {

   printf( "This program will use the Newton-Raphson’s method to calculate the squareroot of X and the error.\n");

   float x;
   printf( "\nEnter value X to be calculated:");
   scanf("%f", &x );
   printf( "\nYou entered X=: %f",x);
//   putchar( x );

   float guess;
   printf( "\nEnter an initial guess for the result value:");
   scanf("%f", &guess );
   printf( "\nYou entered a guess=: %f",guess);
//   putchar( guess );

   float acc;
   printf( "\nEnter the desired decimal place accuracy :");
   scanf("%f", &acc );
   acc= pow(10.00,-acc) ;
   printf( "\nYour desired accuaracy is: %.15lf ", acc );

//   putchar( 10^(-acc) );

   int Imax;
   printf( "\nEnter value for maximum number of iteration:");
   scanf("%d", &Imax );
   printf( "\nMaximum number of iterations will be: %d",Imax);
//   putchar(Imax);

    float result=squareRoot(x,guess,acc,Imax);
    
//    if (i==Imax) {printf("Maximal number of iterations excecuted. The desired accuracy could not be reached.")}
    
    printf("\nSquare root of input X is: %.15lf", result);
//    putchar(guess);
    printf("\nThe error is: %.15lf \n", (float)fabs(result*result - x));
//    putchar( abs(guess*guess - x) );
    printf("\nValue reached after %d iterations.  \n", i);
    printf("\nTrue value is %f:\n", sqrt(x));
//    return 0;
}



//int main(void)
//{
//    squareRoot(x));
//
//    if (i==Imax) {printf("Maximal number of iterations excecuted. The desired accuracy could not be reached.")}
//
//    printf("\nSquare root of input X is: %f", guess);
//    printf("\nThe error is:", absolute(guess*guess - x);
//    printf("\nNumber of itertions:", i);
//
//    return 0;
//}