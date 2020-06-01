#include <stdio.h>

void main() {

   int m;
   printf( "\nEnter a positive integer m:");
   scanf("%d", &m );
   printf( "\nYou entered m=%d",m);

   int n;
   label: printf( "\nEnter a positive integer n that is bigger then m:");
   scanf("%d", &n );

   if (m < n) {
        printf( "\nYou entered n=%d",n);
        printf( " wich is bigger than m=%d",m);
        }  
   if (m >= n) {
        printf( "\nYou entered n=%d",n);
        printf( " wich is smaller or equal to m=%d",m);
        goto label;
        }

   printf( "\nAll the numbers divisible by m between 1 and n are:\n %d", m);

   float x,y;

   for (int i=m+1; i<n; i++) {
        
   y= (float) (i/m);
   x= (float) i/m;

       if (x==y) {
           printf(", %d",i);
           }
   }
   printf("\n");

}