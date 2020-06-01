#include <stdio.h>
#include <stdlib.h>

void Heap1(){
    int *intPtr;
    intPtr=(int *) malloc(sizeof(int));
    printf("%p\n",intPtr);
    free(intPtr);
}


void main(){
    for (int i=0; i<100000000000; i++) 
        Heap1;
} 

