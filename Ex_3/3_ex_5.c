#include <stdio.h>

void main() {

   int m;
   printf( "\nEnter the ammount of cents:");
   scanf("%d", &m );
   printf( "\nYou entered  %d", m);
   printf( " cents, wich can be returned in coins of:\n");
    
    int c50=0;
    int c20=0;
    int c10=0;
    int c5=0;
    int c2=0;
    int c1=0;
   while (m>0) {

       if (m>=50){
           c50++;
           m=m-50; 
           }
       else if (m>=20){
           c20++;
           m=m-20; 
           }
       else if (m>=10){
           c10++;
           m=m-10; 
           }
       else if (m>=5){
           c5++;
           m=m-5; 
           }
       else if (m>=2){
           c2++;
           m=m-2; 
           }
       else if (m>=1){
           c1++;
           m=m-1; 
           }
   }

   printf("%d", c50);
   printf(":50-cent, \n");
   printf("%d", c20);
   printf(":20-cent, \n");
   printf("%d", c10);
   printf(":10-cent, \n");
   printf("%d", c5);
   printf(":5-cent, \n");
   printf("%d", c2);
   printf(":2-cent, \n");
   printf("%d", c1);
   printf(":1-cent \n");

}