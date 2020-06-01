/* Template Program for Sparse Vectors 			     */
/* Demo of dynamic data structures in C                      */

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define NULL 0   //"NULL" redefined the previous definition #define NULL ((void *)0)

struct el {
    int index;	 
    float data;
    struct el *elements;
} ;
typedef struct el eltype;

struct svector {
    int size;
    eltype *elements;
} ;


void printVector (struct svector *x);
void readVector (struct svector *x);



int main () {
    struct svector vector_array[100];
    struct svector temp;

    for(int i=0; i < 100; i++){
	vector_array[i].elements= NULL;
	vector_array[i].size= 0;
    }

    temp.elements = NULL;
    temp.size = 0;

    readVector(&temp);
    printVector(&temp); 

    return 0;

}				


/* reads in a vector from standard input, assumes that x is NULL from beginning */
void readVector (struct svector *x){
/* last_x will always point to the last element in the link list*/
     eltype *last_x = NULL;
	float data;
	int index=0;

	printf("Type each entry on a separate line and press Ctrl-d on a seperate line to finish\n"); 
	while( scanf("%f",&data) != EOF){ 
		index++;  
		/* if there is a non-zero element to add */
		if(data != 0){
			/* if the list is empty */
			if(last_x == NULL) { 	
				 last_x = (eltype *) malloc(sizeof(eltype));		
				 x->elements = last_x;
				 last_x->data = data;
				 last_x->index = index;
				 last_x->elements = NULL;
			}
			else{
				last_x->elements = (eltype *) malloc(sizeof(eltype));
				last_x = last_x->elements;
				last_x->data = data;
                     last_x->index = index;
                     last_x->elements = NULL;
			}
		}
	}
/* the size of the vector is equal to the index of the last element */ 
	x-> size = index;
}


void printVector (struct svector *x){
	eltype * current_x = x-> elements;

	for(int i=1; i <= x->size; i++){
		if(current_x == NULL || current_x->index > i)
			printf("0 ");
		else {
			printf("%f ", current_x->data);
			current_x = current_x->elements;
		}
	}
	printf("\n");
}


