#include <stdio.h>
#include <math.h>
//The method will usually converge, 
//provided this initial guess is close enough to the unknown zero, 
//and that f ′(x0) ≠ 0. 
//
//double x=2
//double guess=1
//double acc=10^(-4)
//
//int Imax=100

int i=1;


double squareRoot(double x, double guess, double acc, int Imax)
{
//    printf(" acc-\n %lf\n", acc);
    while((float) fabs(guess*guess - x) > acc && i<Imax){
        guess = ( guess + (x/guess) ) / 2.0;
//        printf("the value of gues is-%lf \n",((double)fabs(guess*guess - x)));
        i=i+1;
        }

    return guess;//,i;
}

void main() {

   printf( "This program will use the Newton-Raphson’s method to calculate the squareroot of X and the error.\n");

   double x;
   printf( "\nEnter value X to be calculated:");
   scanf("%lf", &x );
   printf( "\nYou entered X=: %lf",x);
//   putchar( x );

   double guess;
   printf( "\nEnter an initial guess for the result value:");
   scanf("%lf", &guess );
   printf( "\nYou entered a guess=: %lf",guess);
//   putchar( guess );

   double acc;
   printf( "\nEnter the desired decimal place accuracy :");
   scanf("%lf", &acc );
   acc= pow(10.00,-acc) ;
   printf( "\nYour desired accuaracy is: %e ", acc );

//   putchar( 10^(-acc) );

   int Imax;
   printf( "\nEnter value for maximum number of iteration:");
   scanf("%d", &Imax );
   printf( "\nMaximum number of iterations will be: %d",Imax);
//   putchar(Imax);

    double result=squareRoot(x,guess,acc,Imax);
    
//    if (i==Imax) {printf("Maximal number of iterations excecuted. The desired accuracy could not be reached.")}
    
    printf("\nSquare root of input X is: %lf", result);
//    putchar(guess);
    printf("\nThe error is: %e \n", (double)fabs(result*result - x));
//    putchar( abs(guess*guess - x) );
    printf("\nValue reached after %d iterations.  \n", i);
    printf("\nTrue value is %fl:", sqrt(x));
    printf("\nThe error with respect to true value is: %e \n", fabs(sqrt(x)-result));

//    return 0;
}



//int main(void)
//{
//    squareRoot(x));
//
//    if (i==Imax) {printf("Maximal number of iterations excecuted. The desired accuracy could not be reached.")}
//
//    printf("\nSquare root of input X is: %lf", guess);
//    printf("\nThe error is:", absolute(guess*guess - x);
//    printf("\nNumber of itertions:", i);
//
//    return 0;
//}