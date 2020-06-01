#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//Write a struct called node that will be used in a linked list containing integers.
// A structure with a pointer member that points to the structure itself is called a self-referential structure.
struct node{
    int number;
    struct node *next;  // pointer member that points to the structure itself and names it next (here is node address stored)
};

//Given an int and a reference to the head pointer (i.e. a struct
//node** pointer to the head pointer), add a new node at the head of
//the list.

struct node *start=NULL;  // this is the HEAD of the linked list with ddress field set to NULL (it contains ONLY address)

void Nodes (struct node *start);
void Print (struct node *start);
void Count (struct node *start);
int GetNth (struct node *start, int index);


void main(){

    int option;
    int input;
    struct node *new_node, *current_node; // here we initialize pointers to the node strucures

    do{
    new_node=(struct node*) malloc(sizeof(struct node)); // here we assign memory space to initialized new node

        // here we will insert data to a node in a list
        printf("\nEnter an integer value to a list: ");
        scanf("%d", &input); // here we insert data to an adress of a number in a list trough a pointer (*new_node).number
        new_node->number=input; // here we insert data to an adress of a number in a list trough a pointer (*new_node).number
        new_node->next=NULL; // here we set address field to NULL - link to a TAIL 

    if (start==NULL){ // when adding the first element right after the HEAD of the list
	start= new_node;// we give the address of our new node to a HEAD node
	current_node= new_node; // we copy our new node address to a CURRENT node variable and new_node can be now reused for a next input 
    }
    else { // when adding the element in next nodes
	current_node->next= new_node; // we give the address of our new node to CURRENT node
	current_node= new_node; // we copy our new node address to a CURRENT node variable
    }

    printf("\nDo you want to create another node? 1/0: ");
    scanf("%d", &option);

    } while (option!=0);

    Nodes (start);
    Print (start);
    Count (start);

    int index;
    int value;
    printf("\nEnter an index to get the data value stored in that list's node: ");
    scanf("%d", &index);
    value=GetNth(start,index);
    printf("\nValue at an index %d is: %d\n\n",index ,value );



    while (start != NULL) {  // clear the list from memory
    start = start -> next;
    free(start);    
    }

}
// Write a function which returns the number of nodes in the list.

void Nodes (struct node *start) { // call-by-reference to the HEAD of the linked list

    int nodes=0;

    if (start == NULL)
        printf ("\n\nList is empty!\n");
    else
        while (start != NULL){
            nodes++;
            start = start -> next;
            }
    printf ("\n\nThe number of nodes in the list is %d.\n\n", nodes);

}

// Write a main loop that reads in the list {1, 2, 3}.

void Print (struct node *start) { // call-by-reference to the HEAD of the linked list

    if (start == NULL)
        printf ("List is empty!\n");
    else
        while (start != NULL){
            printf ("%d -> ", start -> number);
            start = start -> next;
            }
    printf ("NULL\n");
}

//Building on the first linked list example, write a Count function that counts
//the number of times a given int value occurs in a list. The code for this has
//the classic list traversal structure.

void Count(struct node *start){
   
    int value;
    int inputs=0;
    int *numb = NULL;
    int *freq = NULL;
    bool new_int;

    if (start == NULL)
        printf ("List is empty!\n");
    else
        while (start != NULL){

            new_int=true;

            value= start -> number;
            start= start -> next;
            

            for (int j=0; j<inputs ;j++){
                if (value == numb[j]) { freq[j]++; new_int=false; break;}  // counting requency of ints already in the list
                }
    
            if (new_int==true){  // adding new int to list  
    
                    numb=realloc(numb, sizeof(int)); // it resizes 'int numb' for size of int 
                    freq=realloc(freq, sizeof(int)); // it resizes 'int freq' for size of int 
                    numb[inputs]=value; /* Your input goes here */
                    freq[inputs]++; /* Your first requency count goes here */

                    inputs++;  // increase number of inputs new int to list 
                }
 
        }
    printf("\nFrequency of values in order of appeance in list:\n\n");
    for (int i=0; i<inputs; i++) printf(" %d : %d \n", numb[i], freq[i]); 
    free(numb);
    free(freq);

}

//Building on the first linked list example, write a function GetNth that takes
//a linked list and an integer index and returns the data value stored in the
//node at that index position. GetNth() uses the C numbering convention
//that the first node is index 0, the second is index 1, . . . and so on.

int GetNth(struct node *start, int index) { 
   
    int value;
    int inputs=0;

    if (start == NULL)
        printf ("List is empty!\n");
    else
        while (start != NULL){

            value= start -> number;
            start= start -> next;
            if (inputs==index) break;
            inputs++; 

        }
    return value;
}