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
    eltype *elements;
};


//////////////////////////////////////////////////////////////////////
//void readVector (float *array, struct svector *x){
//
//      eltype *last_x = NULL;
//	float data;
//	int index=0;
//
//	for(int j=1; j <= i; j++){
//		index++;  
//		/* if there is a non-zero element to add */
//		if(data != 0){
//			/* if the list is empty */
//			if(last_x == NULL) { 	
//				 last_x = (eltype *) malloc(sizeof(eltype));		
//				 x->elements = last_x;
//				 last_x->data = data;
//				 last_x->index = index;
//				 last_x->elements = NULL;
//			}
//			else{
//				last_x->elements = (eltype *) malloc(sizeof(eltype));
//				last_x = last_x->elements;
//				last_x->data = data;
//                     last_x->index = index;
//                     last_x->elements = NULL;
//			}
//		}
//        }

//////////////////////////////////////////////////////////////////////

void printVector (struct svector *x){
	eltype * current_x = x-> elements;

	for(int i=1; i <= x->size; i++){
		if(current_x == NULL || current_x->index > i)
			printf("%f ",0.0);
		else {
			printf("%f ", current_x->data);
			current_x = current_x->elements;
		}
	}
	printf("\n");
}


void readVector(int INDEX, struct svector *x);
void printVector (struct svector *x);

//////////////////////////////////////////////////////////////////////


void main() {

    struct svector SV0; 
    struct svector SV1; 
    struct svector SV2; 
    struct svector SV3; 

    int INDEX=3;
    readVector(INDEX,&SV1);
    printVector(&SV0); 
    printVector(&SV1); 

//    writeVector(INDEX);

}




void readVector(int INDEX, struct svector *x) {

   int lin=1;
   char readtemp;
   int size=615;
   float array[615];

//   float *array;
//   array=(float *)malloc(sizeof(float));

//   float *array=NULL;
//   array=realloc(array,sizeof(float));
   int i=0;
   int flag=0;
   int exp=1;
//   int NumbfileV=0;
   FILE *fp;
  
   fp = fopen("test.txt","r");

   if (fp == NULL) perror("Error in opening file"); 

   do {

        readtemp = fgetc(fp);
        if ( feof(fp) ) break;
        printf("%c", readtemp);

        if ( readtemp == '\n'){ // fgetc(FILE *stream) gets the next unsigned char from the stream and advances the position indicator for the stream.
            printf("line %d \n",lin);
            lin++;
            }

        if (readtemp != '\n' && lin==INDEX){ 

            if ('0'<= readtemp &&  readtemp <= '9'){

                if (flag==0) {array[i]= (float) (readtemp - '0');flag=1;}

                else if (flag==1) {array[i]= 10 * array[i] + (float) (readtemp - '0');}

                else if (flag==-1) {array[i]= array[i] + ((float) (readtemp - '0')) / (float)(pow(10.0,exp));exp=exp+1;}

                else flag=1;

                }
            else if (readtemp=='.'){
                flag=-1;
                }
            else if (readtemp==' '){
                flag=0;
//                if((float *)realloc(array, sizeof(float))==NULL){printf("Not enough memory for array from line %d!!",INDEX);break;}
//                array=(float *)realloc(array, sizeof(float));
                i++;
                exp=1;
                }
//           printf(" %d ",i);
           }

   } while(1 || lin!=INDEX);

    printf("\nNumber of vectors in file is %d.\n",lin-1);    


    printf("\narray %d is\n ",INDEX);    
    for (int j=0; j<=i; j++) printf("%f ", array[j]);
//    printf("\n");    
    printf("\nwith size %d and last value %f\n\n",i+1,array[i]);    

//////////////////////////////////////////////////////////////////////
//void readVector (float *array, struct svector *x){
//////////////////////////////////////////////////////////////////////
      eltype *last_x = NULL;
	int index=0;
     x->size=i+1;
	for(int j=0; j <=size; j++){
		index++;  
		/* if there is a non-zero element to add */
		if(array[j] != 0){
			/* if the list is empty */
			if(last_x == NULL) { 	
				 last_x = (eltype *) malloc(sizeof(eltype));		
				 x->elements = last_x;
				 last_x->data = array[j];
				 last_x->index = index;
				 last_x->elements = NULL;
			}
			else{
				last_x->elements = (eltype *) malloc(sizeof(eltype));
				last_x = last_x->elements;
				last_x->data = array[j];
                     last_x->index = index;
                     last_x->elements = NULL;
			}
		}
        }

    fclose(fp);
//    free(array);
    free(last_x);
}


