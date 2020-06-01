#include <stdio.h>
#include <stdlib.h>

//Complete the program below. It reads in n (variable) integer values from
//the user and stores these integer values in the dynamic array numbers whose
//size is updated after reading in each new number.

void main (){

    int input, n;
    int count=0;
    int *numbers = NULL;
    
    do {
        printf("Enter an integer value (0 to end):");
        scanf("%d", &input);
        count++;
//
//The C library function void *realloc(void *ptr, size_t size) attempts to resize the memory block pointed to by ptr 
//that was previously allocated with a call to malloc or calloc.
//
        numbers=realloc(numbers, sizeof(int)); // it resizes 'int numbers' for size of int 
        numbers[count-1]=input; /* Your input goes here */

    } while (input!=0);
    

    printf ("Numbers entered: ");
    for (n=0; n<count; n++) printf("%d ", numbers[n]);
    printf ("\n ");

    free(numbers);
    
}
