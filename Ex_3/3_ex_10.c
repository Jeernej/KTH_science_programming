#include <stdio.h>

int fib(int n){
    if (n==1 || n==2) {return 1;}
    else  { return fib(n-1)+fib(n-2); }
}

void main() {

   int n;
   printf( "\nEnter the value 0<n of generation level:");
   scanf("%d", &n );
   printf( "\nYou entered n=%d",n);

   int M,F,A;

   F=fib(n);
   if (n==1 ) {M=0;}
   else  {M=fib(n-1);}

   A=M+F;

   printf( "\nThe total number of ancestors is: %d \n",A);

}
