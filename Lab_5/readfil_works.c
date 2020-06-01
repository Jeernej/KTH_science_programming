#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> // must call to be able to use the strlen() function
#include <math.h>

struct el{
    int index;
    float data;
    struct el *elements;
};
typedef struct el eltype;

struct svector{
    int size;
    eltype * elements;
};


void readVector(int INDEX);

void main() {

    struct svector SV1; 
    struct svector SV2; 
    struct svector SV3; 

    int INDEX=2;
    readVector(INDEX);


}

void readVector(int INDEX) {

   int lin=1;
   char temp;
   int size=615;
   float array[615];

//   float *array;
//   array=(float *)malloc(sizeof(float));

//   float *array=NULL;
//   array=realloc(array,sizeof(float));
   int i=0;
   int flag=0;
   int exp=1;

   FILE *fp;
  
   fp = fopen("test.txt","r");

   if (fp == NULL) perror("Error in opening file"); 

   do {

        temp = fgetc(fp);
        if ( feof(fp) ) break;
        printf("%c", temp);

        if ( temp == '\n'){ // fgetc(FILE *stream) gets the next unsigned char from the stream and advances the position indicator for the stream.
            printf("line %d \n",lin);
            lin++;
            }

        if (temp != '\n' && lin==INDEX){ 

            if ('0'<= temp &&  temp <= '9'){

                if (flag==0) {array[i]= (float) (temp - '0');flag=1;}

                else if (flag==1) {array[i]= 10 * array[i] + (float) (temp - '0');}

                else if (flag==-1) {array[i]= array[i] + ((float) (temp - '0')) / (float)(pow(10.0,exp));exp=exp+1;}

                else flag=1;

                }
            else if (temp=='.'){
                flag=-1;
                }
            else if (temp==' '){
                flag=0;
//                if((float *)realloc(array, sizeof(float))==NULL){printf("Not enough memory for array from line %d!!",INDEX);break;}
//                array=(float *)realloc(array, sizeof(float));
                i++;
                exp=1;
                }
//           printf(" %d ",i);
           }

   } while(1 || lin!=INDEX);


    printf("\narray %d is ",INDEX);    

    for (int j=0; j<=i; j++) printf("%f ", array[j]);

    printf("\n");    

    fclose(fp);
//    free(array);

}