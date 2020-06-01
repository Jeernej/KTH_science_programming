/*Exercise 5 (by Mikael Eriksson, TA HT2015)
Talked about variable allocation and deallocation, stack vs heap, pointers, lists, trees and the idea of ADT.
Exercise 5.6 Using a queue/list structure to simulate bus traveller queue

Ex 5_6: Bus stop queue
*/

#include <stdio.h>
#include <stdlib.h>
#define BUS_INTERVAL 10
#define PROBABILITY 0.9

// We use elementStorage to store the arrival time of the traveller. That is easier than storing
// waiting time directly as then we would have to do continuous updating every minute.

struct elementStorage {
    int dataitem;
    struct elementStorage * next;
} ;
typedef struct elementStorage element;

// Just copy the definitions (actual code) for the following functions from lab 4
// (Oh and implement size() in order to know how many people are in the queue at any time.)
int  count=0;  // global value for counting the number ob elements in the structure
element * AddItem (element * adt, int data);
element * RemoveItem (element * adt);

void Print (element * adt);

int main () {

    printf("Starting bus simulation\n");
    element *queue = NULL;
    
    for (int t = 0; t < 50; t++) {
    
        double p = (rand() / ((double) RAND_MAX + 1));
        // printf("p = %lf\n", p);
        
        if (p < PROBABILITY) {
            // Add a person to the queue
            queue = AddItem(queue, t); // Why assignement necessary?
//
//The answer to the commented question ”Why assignement necessary?” above, 
//is that it is needed for the first call to AddItem, as that actually gives a pointer 
//to the new element (otherwise the list reference would remain NULL).
//
            if (count==0) printf("A person entered the empty queue.\n");
            else printf("A person entered the queue of %d people.\n",count);
            count++;
            }

    if (t % BUS_INTERVAL == 0) {
    
        // Bus arrived!
        printf("Bus arrived! Number of people in the queue is %d. \n",count);
        int nrOfPassengers = (int) (5 + 10*(rand() / ((double) RAND_MAX + 1)));
        
        for (int i = 0; i < nrOfPassengers; i++) {
        
            if (queue != NULL) {
                printf("Person entering the bus ");
                printf("after %d minutes of waiting.\n", t - (queue -> dataitem));
                queue = RemoveItem(queue);
                count--;
                } 
            else {
                printf("The queue is empty!\n");
                break;
                }
    
            }

        } // end-if bus stop

    } // end-for simulation time
}/* end main */


element *AddItem(element *adt, int data) { 
    element *adtPtr = adt;

    if (adt != NULL) {

	while (adt -> next != NULL) // loop to reach the last next
	adt = adt -> next; // set adt to member "next" of a structure "adt" accessed (*adt).next

	adt -> next = (element  *) malloc (sizeof (element)); //allocte A NEW SPACE FOR ADT at last next
	adt = adt -> next;   // we switch adt to this newly aloceted space
	adt -> next = NULL; // and then we set its poiter to NULL
	adt -> dataitem = data; // finaly assign input data value to this place

	return adtPtr; // return to first elment in adt
    }

    else { // when adding the first element to the queue
	adt = (element  *) malloc (sizeof (element));//Allocates block and stores its pointer in local var
	adt -> next = NULL;
	adt -> dataitem = data;
	return adt; // return to first elment in adt
    }
}
 
element *RemoveItem(element *adt) { // call-by-reference  - so every change gets updated in the structure
    element * tempp;
    printf ("Person left the queue.\n");
    tempp = adt -> next;
    free (adt); // When a memory block is no longer needed, it should be deallocated so that it can be reused for other purposes.
    return tempp;
}

