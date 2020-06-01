#include <stdio.h>
#include <stdlib.h>

#include <cstdlib>
#include <cmath>

////    File opening, reading, and closing


void main () {

   FILE *fp;
   char str[1500];

   /* opening file for reading */
   fp = fopen("file.txt" , "r"); //read only then the mode argument is "r"

   if(fp == NULL) { ///// If an error occurs, a null pointer is returned.
      perror("Error opening file"); 
   }

// fgets(char *str, int n, FILE *stream): It reads a line from the specified stream and stores it into the string pointed to by str. 
//It stops when either (n-1) characters are read, the newline character is read, or the end-of-file is reached.
//whichever comes first.
   if( fgets (str, 1500, fp)!=NULL ) {
      /* writing content to stdout */
      puts(str); //writes a string to stdout up to but not including the null character. A newline character is appended to the output.
   }

   fclose(fp);
}

