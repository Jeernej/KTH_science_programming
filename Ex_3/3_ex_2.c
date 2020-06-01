#include <stdio.h>

//// a.)
main() {
   int n;
   printf( "\nEnter value n to sum the numbers from 1 to n:");
   scanf("%d", &n );
   printf( "\nYou entered n=%d",n);
   int j=0;
   for (int i=0; i<=n ; i++) {j=j+ (n-i) ;}
   printf( "\nThe sum is: %d \n",j);
}


////// b.)
main() {
   int n;
   printf( "\nEnter value n to sum the numbers from 1 to n:");
   scanf("%d", &n );
   printf( "\nYou entered n=%d",n);
   int i=0;
   int j=0;
   while ( i<=n ) {
       j=j+(n-i);
       i++;
   }
   printf( "\nThe sum is: %d \n",j);
}


///// c.)
//main() {
//   int n;
//   printf( "\nEnter value n to sum the numbers from 1 to n:");
//   scanf("%d", &n );
//   printf( "\nYou entered n=%d",n);
//   int i=0;
//   int j=0;
//    do{
//        j=j+(n-i);
//        i++;
//    }while(i<=n);
//
//   printf( "\nThe sum is: %d \n",j);
//}

main() {
   int n;
   printf( "\nEnter value n to sum the numbers from 1 to n:");
   scanf("%d", &n );
   printf( "\nYou entered n=%d",n);
   int j=0;
   j=n*(n+1)/2;

   printf( "\nThe sum is: %d \n",j);
}






