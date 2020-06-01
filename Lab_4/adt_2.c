/*                                                           */
/*  This is an abstract data type                            */
/*                                                           */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
////////////////////////////GLOBAL VARIABLES////////////////////////////////////////////////
//
int max;
bool cont=false;  // global falg for cheking if elements are allready contained
int  count=0;  // global value for counting the number ob elements in the structure

//Structures are collections of values (members), possibly of different
//types, used for storing related data.
//The value of a member is accessed through identifier.member - elementStorage.dataitem
struct elementStorage {
    int     dataitem;
    struct elementStorage *next; // A structure with a pointer member that points to the structure itself is called a self-referential structure.
} ;  // Using the tag, a structure variable can be declared as -> struct tag name;
//A typedef can be used to simplify the declaration for a struct or
//pointer type, and to eliminate the need for the struct key word.
typedef struct elementStorage element; // element is now part of the elementStorage

void Menu (int *choice);
element *AddItem (element *adt, int data);
element *RemoveItem (element *adt);
void Print (element *adt);
void Clear (element *adt);
element *contained (element *adt, int data);
void IsEmpty (element *adt);
void IsFull (element *adt);


/////////////////////////////////////////////////////////////////////////////////////////////

int main () {
    element *adt;
    int data, choice;

    adt = NULL; 
    max=100; // default max size when rhe program is ran CAN be changed later in menu

    do {

	Menu (&choice);

	switch (choice) {
          
	       case 1: 
                count++; //printf("%d",count);
                if((adt !=NULL)){
                    if((count > max)){printf ("Maximmum data alread in the queue."); count--; break;}
                }
    
        		printf ("Enter data item value to add  ");
        		scanf ("%d", &data);  
                contained(adt, data); //call function to check if the input is alread contained in the queue
    
            		if (!cont){
                		adt = AddItem (adt, data); //
                        }
        
                    else{
                        printf ("Element with this value is already in the queue. Add an element with different value."); 
                        count--;
                    }

                cont=false; //reset global flag
                break;

	     case 2: 
		 if (adt == NULL) // if it si empty there is nothing to be removed
		    printf ("Empty!\n"); //
		 else{
		    adt = RemoveItem (adt);
               count--;//printf("%d",count);  // keep the counter updatet bro! 
            }
		break;

	    case 3: 
		Print (adt);
		break;

	    case 4: 
           IsEmpty (adt);
		break;

	    case 5: 
           IsFull (adt);
		break;

	    case 6: 
            printf ("Enter max size of ADS:");
            scanf ("%d", &max); 
		break;

	    case 7: 
		break;

	    default: 
		printf ("Invalid menu choice - try again\n");
		break;
	}
    } while (choice != 7);
    Clear (adt); // Why is it important to have a function like Clear? -> To avoid memory leaks.
}				/* main */


void Menu (int *choice) {

    char local;

    printf ("\nEnter\t1 to add item\n\t2 to remove item\n\t3 to print contents\n\t4 to check if ADT is empty\n\t5 to check if queue is full\n\t6 to set queue size\n\t7 to quit\n");
    do {
   	local = getchar();
	if ( !( '0'< local &&  local < '8') && (local != '\n')) {
	    printf ("\nyou must enter an integer.\n");
	    printf ("Enter 1 to add, 2 to remove, 3 to print, 4 to check if queue is empty, 5 to check if queue is full, 6 to set queue size, 7 to quit\n");
	}
    } while (!('0'< local &&  local < '8'));
 
   *choice = (int) local - '0';
}

element * contained(element *adt, int data) { 
    element *adtPtr = adt;

    if (adt != NULL) {
	while (adt != NULL){// loop to go trough adt!!
        if (adt->dataitem==data) {cont=true; break;}  // if input same as an element in adt set the flag and break
	   adt = adt -> next; 
     }
    }
    return adtPtr; // return to the first elment in adt
}

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
    printf ("Element removed is %d\n", adt -> dataitem);
    tempp = adt -> next;
    free (adt); // When a memory block is no longer needed, it should be deallocated so that it can be reused for other purposes.
    return tempp;
}


void Print (element *adt) { // call-by-reference - so every change gets updated in the structure

    if (adt == NULL)
	printf ("Empty!\n");
    else
	while (adt != NULL) {
	    printf ("%d\t", adt -> dataitem);
	    adt = adt -> next;
	}
    printf ("\n");
}

void IsEmpty (element *adt) {
    if (adt == NULL){
	printf ("\nQueue IS empty!\n");
    }
    else{
	printf ("\nQueue is NOT empty!\n");
    }
}

void IsFull (element *adt) {
    if (malloc (sizeof (element))==NULL) printf ("\nNot enough memory is available.\n");
    else if (adt != NULL){
        if (count >= max)
    	   printf ("\nQueue IS full!\n");
        else
        printf ("\nQueue is NOT full!\n");
    }
    else
	printf ("\nQueue is NOT full!\n");
}


void Clear (element *adt) {
    while (adt != NULL) {
	adt = RemoveItem (adt);
    }
}


