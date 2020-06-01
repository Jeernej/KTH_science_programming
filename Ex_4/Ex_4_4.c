#include <stdio.h>
#include <math.h>
#include <stdbool.h>


int InOrder(int l_arr, double *array);

void main(){

    double a, b, c, d, e;
    int l_arr=5;
    int CH=0;

		printf ("\nEnter array values.\n");

		printf ("\na=");
		scanf ("%lf", &a); 
		printf ("\nb=");
		scanf ("%lf", &b); 
		printf ("\nc=");
		scanf ("%lf", &c); 
		printf ("\nd=");
		scanf ("%lf", &d); 
		printf ("\ne=");
		scanf ("%lf", &e); 

    double array[5] = {a,b,c,d,e};


    printf ("\ne=%d",CH);

          CH=InOrder(l_arr, array);

    printf ("\ne=%d",CH);

    if (CH==1) printf ("\nThe array IS sorted in ascending order!\n\n");

    else printf("\nThe array is NOT sorted in ascending order!\n");

}

/////  Arrays are always passed by reference!! 
/////  That is, all changes to the parameter will also affect the argument.
int InOrder(int l_arr, double *array){

    int k=0;
    
    for (int i=0; i<l_arr-1 ;i++) if ( array[i] > array[i+1]) k++; 

    if (k==0) return 1;

    else return 0;

}