/*                                                           */
/*  This is an abstract data type                            */
/*                                                           */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
////////////////////////////GLOBAL VARIABLES////////////////////////////////////////////////
//
int max=10;
bool cont=false;
int  count=0;
//Structures are collections of values (members), possibly of different
//types, used for storing related data.
//The value of a member is accessed through identifier.member - elementStorage.dataitem
struct elementStorage {
    int     dataitem;
     // A structure with a pointer member that points to the structure itself is called a self-referential structure.
} ; // Using the tag, a structure variable can be declared as -> struct tag name;

struct elementStorage adt[10];  // same value as max !!
//A typedef can be used to simplify the declaration for a struct or
//pointer type, and to eliminate the need for the struct key word.
//typedef struct elementStorage element; // element is now part of the elementStorage

void Menu (int *choice);
void RemoveItem (adt);
void Print (adt);
void Clear ();
void contained ( int data);
void IsEmpty ( adt);
void IsFull ( adt);

//
/////////////////////////////////////////////////////////////////////////////////////////////

// element adt[max];
int main () {
    // adt declared here!!
    int data, choice;
    

    //adt = NULL;  // why this?
   /// strange things for intigers with more than nine cifers 3333333333

    do {
	Menu (&choice);

	switch (choice) {
          
	    case 1: 
            count++; printf("%d",count);
            if((count >max)){printf ("Maximmum data in the ADT."); count--; break;}

   		 printf ("Enter data item value to add  ");
		 scanf ("%d", &data); // strange things for intigers with more than nine cifers 3333333333
//           for(int i = 0; i < sizeof(elementStorage); i++)
            contained( data);
		 if (!cont){
               adt[count-1].dataitem=data; //traversing through array
                }

           else{printf ("Element with this value is already in the queue. Add an element with different value."); count--;}
           cont=false;
        	break;

	    case 2: 
		if (count==0)
		    printf ("Empty!\n");
		else{
		     RemoveItem (adt);
               count--;//printf("%d",count);
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
		break;

	    default: 
		printf ("Invalid menu choice - try again\n");
		break;
	}
    } while (choice != 6);
    Clear (); // Why is it important to have a function like Clear? -> To avoid memory leaks.				/* main */
   return 0;
}

void Menu (int *choice) {

    char local;

    printf ("\nEnter\t1 to add item\n\t2 to remove item\n\t3 to print contents\n\t4 to check if ADT is empty\n\t5 to check if ADT is full\n\t6 to quit\n");
    do {
   	local = getchar();
	if ( !( '0'< local &&  local < '7') && (local != '\n')) {
	    printf ("\nyou must enter an integer.\n");
	    printf ("Enter 1 to add, 2 to remove, 3 to print, 4 to check if ADT is empty, 5 to check if ADT is full, 6 to quit\n");
	}
    } while (!('0'< local &&  local < '7'));
 
   *choice = (int) local - '0';
}


void contained( int data) { 

     for(int i=0;i<count;i++){
         if(adt[i].dataitem==data){
            cont=true;break;
          }
    }
}
   
void RemoveItem( struct elementStorage adt[]) { // call-by-value
    printf ("Element removed is %d\n", adt[0].dataitem); // print the element that will be owerwritten 
    for(int i=0;i<count-1;i++) adt[i]=adt[i+1]; // overwrite first in the queue by moving all elements on place down 
}

void Print (struct elementStorage adt[]) { // call-by-value
 for(int i=0;i<count;i++) printf("%d\t\t",adt[i].dataitem);
}

void IsEmpty (struct elementStorage adt[]) {
    if (count == 0){
	printf ("\nQueue IS empty!\n");
    }
    else{
	printf ("\nQueue is NOT empty!\n");
    }
}

void IsFull (struct elementStorage adt[]) {
     if (count == max){
    	   printf ("\nQueue IS full!\n");
    }
    else
	printf ("\nQueue is NOT full!\n");
}


void Clear () {
    while (count>0) {
//    printf ("Element removed is %d\n", adt[0].dataitem);
    RemoveItem (adt);
    count--;
    }
}


