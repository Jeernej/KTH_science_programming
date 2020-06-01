/*                                                           */
/*  This is Sparse Vector Arithmetic                         */
/*                                                           */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> // must cal to be able to use the strlen() function
#include <math.h>

//Your program will work like an interpreter: it will type a
//prompt > on the screen and wait for user input. The user
//input will consist of single lines. Your program will read this
//line and perform the operations it requests followed by an
//output printed on the screen.

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

char OPERATOR;
int INDEX_1;
int INDEX_2;
int INDEX_3;
float SCALAR;


//
//Your program will read a database of sparse vectors from a text file. 
//Each vector is represented as decimal values placed on a separate line.
//The file may contain at most 100 vectors. The vectors will
//be referred to with the keyword v and their order in the database file.
//

//void Menu (int *choice);

void readVector (struct svector *x);
void printVector (struct svector *x);

void ASGN(int index1, int index2) ;

void CALC(char operat, int index1, int index2);
void SUM(int index1, int index2);
void SUB(int index1, int index2);
void MULT(int index1, int index2);
void SCALE(int index2, float scale); 

void vCALC(char operat, int index1, int index2, int index3);
void vSUM(int index1, int index2, int index3);
void vSUB(int index1, int index2, int index3);
void vMULT(int index1, int index2, int index3);
void vSCALE(int index1, int index3, float scale); 


//////////////// MENU /////////////////////////////////////////
void main () {

    struct svector vector_array[100]; // list of vectors and their sizes
    struct svector temp; // temporary vector and its size

    for(int i=0; i < 100; i++){
	vector_array[i].elements= NULL;
	vector_array[i].size= 0;
    }

    temp.elements = NULL;
    temp.size = 0;

	printf("\nWelcome to SparseLab!\n");
    readVector(&temp); // reads in a vector from standard input or file
	printf("\nDatabase read, waiting for command\n");
//The vectors will be referred to with the keyword v and their order in the database file.
//Each user command can contain at most one operation and at most one assignment. 
//It is enough to type the name of a vector on a single line to print its value. 
     printf ("\nEnter:\n\n 'v#' to print vector number; #=[1,100]\n 'v# =' to assign new vector value\n 'temp =' to define special vector\n '+,-,.,/' inbetween two vectors to define the operation\n 'v# = 0,23 . V# ' for scalar multiplication (use comma as decimal separator)\n 'q' to quit\n");

    char operat[20];    
    int out=0; 
    do {  

     char operat[20]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};     
//     scanf("%[^\n]%*c", operat);
//     scanf("%s", operat);
     fgets (operat, 100, stdin);
//     out=strcmp(operat, "q");
     if(operat[0]=='q') break;      
//     if(operat[1]=='\n') printf("next line here");

     //Finally, one can quit by typing q.
     // > q
     //   Bye bye!
 
        //The operations on vectors that you will be implementing are:
        //    • addition (+)
        //    • subtraction (-)
        //    • product with scalar and scalar product (.). 
        printf("\nEntered operat is %s\n",operat);

        int prnt=0;
        do {
            printf("operat[%d] is %c\n",prnt, operat[prnt]); 
            prnt++;
            } while (prnt<(int)strlen(operat));



//////////////// MENU - Interpreter /////////////////////////////////////////
        int TEMP=0;
        int INDEX_1=0;
        int INDEX_2=0;
        int INDEX_3=0;
        float SCALAR=1;
        int Scaled=0;
        int EQ_pos=0;
        int OP_pos=0;
        int DIFF=0;
        int DIFF1=0;
        int DIFF2=0;

// print out values of vectors 'v#' and 'temp'
        if(operat[0]=='v' || operat[0]=='t' ) { // index1 for vector call  v1 

        //// vector values calls 
            if(operat[0]=='v' && operat[2]=='\n') { // index1 for vector call  v1 
                INDEX_1=(int) operat[1] - '0';
                printf("\nindex10  is v%d\n", INDEX_1);
                } // get vector index1 number from operat[1,2] and print it out
            else if(operat[0]=='v' && operat[3]=='\n') {// index1 for vector call  v12
                int a=(int) operat[1] - '0';
                int b=(int) operat[2] - '0';
                INDEX_1=10*a+b;
                printf("\nindex10  is v%d\n", INDEX_1); 
                } // get vector index1 number from operat[1,2] and print it out
            else if(operat[0]=='v' && operat[4]=='\n' && operat[3]!='=') {// index1 for vector call  v1123 
                int a=(int) operat[1] - '0';
                int b=(int) operat[2] - '0';
                int c=(int) operat[3] - '0';
                INDEX_1=100*a+10*b+c;
                printf("\nindex10  is v%d\n", INDEX_1);
                } // get vector index1 number from operat[1,2,3] and print it out
            else if( (operat[0]=='t') && (operat[1]=='e') && (operat[2]=='m') && (operat[3]=='p') && (operat[4]=='\n') ) {printf("\ntemp10\n"); TEMP=1;} // get temp and print it out
    
    
            //// vector values definitions with calculations
            else {

                if( (operat[0]=='t') && (operat[1]=='e') && (operat[2]=='m') && (operat[3]=='p') && (operat[4]==' ') ) {printf("\ntemp1\n"); TEMP=1;} // get temp and print it out

    
                for (int i=0; operat[i]!='\n'; i++) {

                    if (operat[i]=='=') {// index1 for definitions v1 = v2
                        EQ_pos=i;
                        
                        if (i==3 && operat[0]=='v'){
                            INDEX_1=(int) operat[i-2] - '0';
                            printf("\nindex1  is v%d\n", INDEX_1);
                            }
                        else if (i==4 && operat[0]=='v'){
                            int a=(int) operat[i-3] - '0';
                            int b=(int) operat[i-2] - '0';
                            INDEX_1=10*a+b;
                            printf("\nindex1  is v%d\n", INDEX_1);
                            }
                        else if (i==5 && operat[0]=='v'){
                            int a=(int) operat[i-4] - '0';
                            int b=(int) operat[i-3] - '0';
                            int c=(int) operat[i-2] - '0';
                            INDEX_1=100*a+10*b+c;
                            printf("\nindex1  is v%d\n", INDEX_1);
                            }
                        
                        DIFF=(int)strlen(operat)-EQ_pos;
    
                        if ((operat[EQ_pos+1]==' ') ) {// index2 for definition v1 = v2
    
                            if (DIFF==5 && (operat[EQ_pos+2]=='v') ){
                                INDEX_2=(int) operat[EQ_pos+3] - '0';
                                printf("\nindex20  is v%d\n", INDEX_2);
                                }
                            else if (DIFF==6 && (operat[EQ_pos+2]=='v') ){
                                int a=(int) operat[EQ_pos+3] - '0';
                                int b=(int) operat[EQ_pos+4] - '0';
                                INDEX_2=10*a+b;
                                printf("\nindex20  is v%d\n", INDEX_2);
                                }
                            else if (DIFF==7 && (operat[EQ_pos+2]=='v') ){
                                int a=(int) operat[EQ_pos+3] - '0';
                                int b=(int) operat[EQ_pos+4] - '0';
                                int c=(int) operat[EQ_pos+5] - '0';
                                INDEX_2=100*a+10*b+c;
                                printf("\nindex20  is v%d\n", INDEX_2);
                                }
                            else if( (operat[EQ_pos+2]=='t') && (operat[EQ_pos+3]=='e') && (operat[EQ_pos+4]=='m') && (operat[EQ_pos+5]=='p') && (operat[EQ_pos+6]=='\n') ) {printf("\ntemp20\n"); TEMP=1;} // get temp and print it out
//                            else printf("Wrong input form.\n");    
                            }
//                        else printf("Wrong input form.\n");    
                        }
    

    
                            if ( (EQ_pos!=0 && operat[i]=='+') || (EQ_pos!=0 && operat[i]=='-') || (EQ_pos!=0 && operat[i]=='.')) {
                            OP_pos=i; 
                            OPERATOR=operat[OP_pos];
                            DIFF1 =OP_pos-EQ_pos;
        
                            if(operat[EQ_pos+1]==' ') {// index2 for calculations v1 = v2 + 
        
                                if (DIFF1==5 && operat[EQ_pos+2]=='v'){
                                    INDEX_2=(int) operat[EQ_pos+3] - '0';
                                    printf("\nindex2  is v%d\n", INDEX_2);
                                    }
                                else if (DIFF1==6 && operat[EQ_pos+2]=='v'){
                                    int a=(int) operat[EQ_pos+3] - '0';
                                    int b=(int) operat[EQ_pos+4] - '0';
                                    INDEX_2=10*a+b;
                                    printf("\nindex2  is v%d\n", INDEX_2);
                                    }
                                else if (DIFF1==7 && operat[EQ_pos+2]=='v'){
                                    int a=(int) operat[EQ_pos+3] - '0';
                                    int b=(int) operat[EQ_pos+4] - '0';
                                    int c=(int) operat[EQ_pos+5] - '0';
                                    INDEX_2=100*a+10*b+c;
                                    printf("\nindex2  is v%d\n", INDEX_2);
                                    }
                                else if( (operat[EQ_pos+2]=='t') && (operat[EQ_pos+3]=='e') && (operat[EQ_pos+4]=='m') && (operat[EQ_pos+5]=='p') && (operat[EQ_pos+6]==' ') ) {printf("\ntemp2\n"); TEMP=1;} // get temp and print it out

                                
                                else if (operat[i]=='.' &&  '0'<= operat[EQ_pos+2] &&  operat[EQ_pos+2] <= '9' ) {// get scalar from position v1 = SCALAR
                                    Scaled=1;
                                    int j=0;
                                    float BIG=0;
                                    float SMALL=0;
                                    int real=0;
                                    int r=1;
                                    while (j<DIFF1-3){

                                        if (operat[EQ_pos+2+j]==',') { real=1;}
                                        else if (real==0) { BIG=10*BIG+(float) operat[EQ_pos+2+j] - '0'; }
                                        else if (real==1) { SMALL=SMALL+((float) operat[EQ_pos+2+j] - '0')/(float) pow(10,r); r++;}
                                        j++;

                                        }
                                    SCALAR =BIG+SMALL;
                                    printf("\nSCALAR is %f\n", SCALAR);

                                    }
//                                else printf("Wrong input form.\n");    
                                }
                            printf("\noperator is %c", operat[OP_pos]);
    
                            DIFF2 =(int)strlen(operat)-OP_pos;
                
                            if((operat[OP_pos+1]==' ') ) {// index2 for calculations v1 = v2 + v3
                
                                if (DIFF2==5 && (operat[OP_pos+2]=='v') ){
                                    INDEX_3=(int) operat[OP_pos+3] - '0';
                                    printf("\nindex3  is v%d\n", INDEX_3);
                                    }
                                else if (DIFF2==6 && (operat[OP_pos+2]=='v') ){
                                    int a=(int) operat[OP_pos+3] - '0';
                                    int b=(int) operat[OP_pos+4] - '0';
                                    INDEX_3=10*a+b;
                                    printf("\nindex3  is v%d\n", INDEX_3);
                                    }
                                else if (DIFF2==7 && (operat[OP_pos+2]=='v') ){
                                    int a=(int) operat[OP_pos+3] - '0';
                                    int b=(int) operat[OP_pos+4] - '0';
                                    int c=(int) operat[OP_pos+5] - '0';
                                    INDEX_3=100*a+10*b+c;
                                    printf("\nindex3  is v%d\n", INDEX_3);
                                    }
                                else if( (operat[OP_pos+2]=='t') && (operat[OP_pos+3]=='e') && (operat[OP_pos+4]=='m') && (operat[OP_pos+5]=='p') && (operat[OP_pos+6]=='\n') ) {printf("\ntemp3\n"); TEMP=1;} // get temp and print it out
//                                else printf("Wrong input form.\n");    
                                }
    
                            }
                        }

                        for (int i=0; operat[i]!='\n'; i++) {
            
                            if ( (EQ_pos==0 && operat[i]=='+') || (EQ_pos==0 && operat[i]=='-') || (EQ_pos==0 && operat[i]=='.')) {
                                OP_pos=i; 
                                OPERATOR=operat[OP_pos];
            
                                if (i==3 && operat[0]=='v'){ // index1 for definitions v1 . v2
                                    INDEX_1=(int) operat[i-2] - '0';
                                    printf("\nindex1  is v%d\n", INDEX_1);
                                    }
                                else if (i==4 && operat[0]=='v'){
                                    int a=(int) operat[i-3] - '0';
                                    int b=(int) operat[i-2] - '0';
                                    INDEX_1=10*a+b;
                                    printf("\nindex1  is v%d\n", INDEX_1);
                                    }
                                else if (i==5 && operat[0]=='v'){
                                    int a=(int) operat[i-4] - '0';
                                    int b=(int) operat[i-3] - '0';
                                    int c=(int) operat[i-2] - '0';
                                    INDEX_1=100*a+10*b+c;
                                    printf("\nindex1  is v%d\n", INDEX_1);
                                    }
                        
                                printf("\noperator is %c", operat[OP_pos]);                    
                                DIFF=(int)strlen(operat)-OP_pos;
            
                                if ((operat[OP_pos+1]==' ') ) {// index2 for definition v1 . v2
            
                                    if (DIFF==5 && (operat[OP_pos+2]=='v') ){
                                        INDEX_2=(int) operat[OP_pos+3] - '0';
                                        printf("\nindex2  is v%d\n", INDEX_2);
                                        }
                                    else if (DIFF==6 && (operat[OP_pos+2]=='v') ){
                                        int a=(int) operat[OP_pos+3] - '0';
                                        int b=(int) operat[OP_pos+4] - '0';
                                        INDEX_2=10*a+b;
                                        printf("\nindex2  is v%d\n", INDEX_2);
                                        }
                                    else if (DIFF==7 && (operat[OP_pos+2]=='v') ){
                                        int a=(int) operat[OP_pos+3] - '0';
                                        int b=(int) operat[OP_pos+4] - '0';
                                        int c=(int) operat[OP_pos+5] - '0';
                                        INDEX_2=100*a+10*b+c;
                                        printf("\nindex2  is v%d\n", INDEX_2);
                                        }
                                    else if( (operat[OP_pos+2]=='t') && (operat[OP_pos+3]=='e') && (operat[OP_pos+4]=='m') && (operat[OP_pos+5]=='p') && (operat[OP_pos+6]=='\n') ) {printf("\ntemp2\n"); TEMP=1;} // get temp and print it out
            //                            else printf("Wrong input form.\n");    
                                    }
                                }
                            }

                    }
              }

        else if('0'<= operat[0] &&  operat[0] <= '9') { // index1 for vector call  v1 

            for (int i=0; operat[i]!='\n'; i++) {

                if (operat[i]=='+' || operat[i]=='-' || operat[i]=='.') {
                    OP_pos=i; 
                    OPERATOR=operat[OP_pos];

                    if (operat[i]=='.' &&  '0'<= operat[0] &&  operat[0] <= '9' ) {// get scalar from position SCALAR . v1
                        Scaled=1;
                        int j=0;
                        float BIG=0;
                        float SMALL=0;
                        int real=0;
                        int r=1;
                        while (j<OP_pos-1){

                            if (operat[j]==',') { real=1;}
                            else if (real==0) { BIG=10*BIG+(float) operat[j] - '0'; }
                            else if (real==1) { SMALL=SMALL+((float) operat[j] - '0')/(float) pow(10,r); r++;}
                            j++;

                            }
                        SCALAR =BIG+SMALL;
                        printf("\nSCALAR is %f\n", SCALAR);

                        }

                    printf("\noperator is %c", operat[OP_pos]);                    
                    DIFF=(int)strlen(operat)-OP_pos;

                    if ((operat[OP_pos+1]==' ') ) {// index2 for definition v1 . v2

                        if (DIFF==5 && (operat[OP_pos+2]=='v') ){
                            INDEX_2=(int) operat[OP_pos+3] - '0';
                            printf("\nindex2  is v%d\n", INDEX_2);
                            }
                        else if (DIFF==6 && (operat[OP_pos+2]=='v') ){
                            int a=(int) operat[OP_pos+3] - '0';
                            int b=(int) operat[OP_pos+4] - '0';
                            INDEX_2=10*a+b;
                            printf("\nindex2  is v%d\n", INDEX_2);
                            }
                        else if (DIFF==7 && (operat[OP_pos+2]=='v') ){
                            int a=(int) operat[OP_pos+3] - '0';
                            int b=(int) operat[OP_pos+4] - '0';
                            int c=(int) operat[OP_pos+5] - '0';
                            INDEX_2=100*a+10*b+c;
                            printf("\nindex2  is v%d\n", INDEX_2);
                            }
                        else if( (operat[OP_pos+2]=='t') && (operat[OP_pos+3]=='e') && (operat[OP_pos+4]=='m') && (operat[OP_pos+5]=='p') && (operat[OP_pos+6]=='\n') ) {printf("\ntemp2\n"); TEMP=1;} // get temp and print it out
                        }
                    }
                }
            }

//////////////// MENU - calculations /////////////////////////////////////////

//        int EQ_pos=0;
//        int OP_pos=0;

//        char OPERATOR;
//        int INDEX_1=0;
//        int INDEX_2=0;
//        int INDEX_3=0;
//        float SCALAR=1;

//void ASGNvoid ASGN(int index1, int index2) ;
//
//void CALC(char operat, int index1, int index2);
//void SUM() (int index1, int index2);
//void SUB() (int index1, int index2);
//void MULT() (int index1, int index2);
//void SCALE() (int index2, float scale); 
//
//void vCALC(char operat, int index1, int index2, int index3);
//void vSUM() (int index1, int index2, int index3);
//void vSUB() (int index1, int index2, int index3);
//void vMULT() (int index1, int index2, int index3);
//void vSCALE() (int index1, int index3, float scale); 


        if (EQ_pos==0){ /// printing values

            if (INDEX_1==0 && TEMP==0) {break;}
            else if (INDEX_1!=0 && TEMP==0) {
                printf("\nV%d is ", INDEX_1);
                printVector(INDEX_1);
                }
            else if (INDEX_1==0 && TEMP!=0) {
                printf("\ntemp is "); 
                printVector(0);
                }
            }

        else if (EQ_pos==0 && OP_pos!=0) { /// calculating and printing values

            if (INDEX_1==0 && INDEX_2==0 && TEMP==0) {break;}
            else if (INDEX_1!=0 && INDEX_2!=0 && TEMP==0) {  // v1 . v2
                printf("\nV%d = ", INDEX_1);
                ASGN(INDEX_1,INDEX_2);
                }
            else if (INDEX_1!=0 && INDEX_2==0 && TEMP!=0) { // v1 . temp
                printf("\nV%d = ", INDEX_1);
                ASGN(INDEX_1,0);
                }
            else if (INDEX_1==0 && INDEX_2!=0 && TEMP!=0) { // temp . v2
                printf("\ntemp = "); 
                ASGN(0,INDEX_2);
                }
            else if (INDEX_1==0 && INDEX_2!=0 && TEMP!=0) { // temp . temp
                printf("\ntemp = "); 
                ASGN(0,INDEX_2);
                }
            }

        else if (EQ_pos==0 && OP_pos!=0 && Scaled==1) { /// scaling and printing vectors

            if (INDEX_2!=0 && TEMP==0) {  // SCALAR . v1
                printVector(0);
                SCALE(INDEX_2,SCALAR);
                }
            else if (INDEX_2==0 && TEMP!=0) {  // SCALAR . temp
                printVector(0);
                SCALE(0,SCALAR);
                }
            }

        else if (EQ_pos!=0 && OP_pos==0) { /// defining values

            if (INDEX_1==0 && INDEX_2==0 && TEMP==0) {break;}
            else if (INDEX_1!=0 && INDEX_2!=0 && TEMP==0) {  // v1 = v2
                printf("\nV%d = ", INDEX_1);
                if (INDEX_1==INDEX_2) {printVector(INDEX_1);}
                else ASGN(INDEX_1,INDEX_2);
                }
            else if (INDEX_1!=0 && INDEX_2==0 && TEMP!=0) { // v1 = temp
                printf("\nV%d = ", INDEX_1);
                ASGN(INDEX_1,0);
                }
            else if (INDEX_1==0 && INDEX_2!=0 && TEMP!=0) { // temp = v2
                printf("\ntemp = "); 
                ASGN(0,INDEX_2);
                }
            else if (INDEX_1==0 && INDEX_2==0 && TEMP!=0) {  // temp = temp
                printf("\ntemp = "); 
                printVector(0);
                }
            }

        else if (EQ_pos!=0 && OP_pos!=0 && Scaled==1) { /// scaling  vectors
            if (INDEX_1==0 && INDEX_2==0 && SCALAR==1 && TEMP==0) {break;}
            else if (INDEX_1!=0 && INDEX_3!=0 && TEMP==0) {  // v1 = SCALAR . V3
                printf("\nV%d = ", INDEX_1);
                vSCALE(INDEX_1,INDEX_3,SCALAR);
                }
            else if (INDEX_1!=0 && INDEX_3==0 && TEMP!=0) { // v1 = SCALAR . temp
                printf("\nV%d = ", index);
                vSCALE(INDEX_1,0,SCALAR);
                }
            else if (INDEX_1==0 && INDEX_3!=0 && TEMP!=0) { // temp = SCALAR . V3
                printf("\ntemp = "); 
                vSCALE(0,INDEX_3,SCALAR);
                }
            }

        else if (EQ_pos!=0 && OP_pos!=0 && Scaled==0) { /// calculating values
            if (INDEX_1==0 && INDEX_2==0 && INDEX_3==0 && TEMP==0) {break;}
            else if (INDEX_1!=0 && INDEX_2!=0 && INDEX_3!=0 && TEMP==0) {  // v1 = v2 + v3
                printf("\nV%d = ", INDEX_1);
                vCALC(operat[OP_pos], INDEX_1, INDEX_2, INDEX_3);
                }
            else if (INDEX_1!=0 && INDEX_2!=0 && INDEX_3==0 && TEMP!=0) {  // v1 = v2 + temp
                printf("\nV%d = ", INDEX_1);
                vCALC(operat[OP_pos], INDEX_1, INDEX_2, 0);
                }
            else if (INDEX_1!=0 && INDEX_2==0 && INDEX_3!=0 && TEMP!=0) {  // v1 = temp + v3
                printf("\nV%d = ", INDEX_1);
                vCALC(operat[OP_pos], INDEX_1, 0, INDEX_3);
                }
            else if (INDEX_1!=0 && INDEX_2==0 && INDEX_3==0 && TEMP!=0) {  // v1 = temp + temp
                printf("\nV%d = ", INDEX_1);
                vCALC(operat[OP_pos], INDEX_1, 0, 0);
                }
            else if (INDEX_1==0 && INDEX_2!=0 && INDEX_3!=0 && TEMP!=0) {  // temp = v2 + v3
                printf("\ntemp = "); 
                vCALC(operat[OP_pos], 0, INDEX_2, INDEX_3);
                }
            else if (INDEX_1==0 && INDEX_2!=0 && INDEX_3==0 && TEMP!=0) {  // temp = v2 + temp
                printf("\ntemp = "); 
                vCALC(operat[OP_pos], 0, INDEX_2, 0);
                }
            else if (INDEX_1==0 && INDEX_2==0 && INDEX_3!=0 && TEMP!=0) {  // temp = temp + v3
                printf("\ntemp = "); 
                vCALC(operat[OP_pos], 0, 0, INDEX_3);
                }
            else if (INDEX_1==0 && INDEX_2==0 && INDEX_3==0 && TEMP!=0) {  // temp = temp + temp
                printf("\ntemp = "); 
                vCALC(operat[OP_pos], 0, 0, 0);
                }
            }


    else printf("Wrong input form.\n"); 


    } while (out == 0);
    printf("  Bye bye!\n");
}				


/////////////////////////////////////////////////
//*I will help you tomorrow,sleepy now kishore*//
/////////////////////////////////////////////////


void ASGN(int index1, int index3) {

// get vectors from both vector indices

// owervrite vector 1 with vector 2  /// add or erase elements if sizes differ

// print vector 1 in next line: v1 is
}

void SCALE(int index1, float scale) {

// get vector from vector index

// multiplay all values with the float scalar

// print result in next line
}

void CALC(char operat, int index1, int index2) {
    if (operat=='+') {  // v1 + v2
        SUM(index1, index2);
        }
    else if (operat=='-') {  // v1 - v2 
        SUB(index1, index2);
        }
    else if (operat=='.') {  // v1 . v2
        MULT(index1, index2);
        }
}

void SUM(int index1, int index2) {

// get vectors from both vector indices

// sum all elements that have same index /// add or erase elements if sizes differ

// print result in next line
}


void SUB(int index1, int index2) {

// get vectors from both vector indices

// substract all elements that have the same index /// add or erase elements if sizes differ

// print result in next line
}

void MULT(int index1, int index2) {

// get vectors from both vector indices

// multiply all elements that have the same index and add these values together // until smallest vector size is reached

// print result in next line
}


void vSCALE(int index1, int index3, float scale) {

// get vectors from both vector indices

// multiply vector 3 values with the float scalar and assign them to vector 1 /// add or erase elements if sizes differ

// print vector 1 in next line: v1 is
}

void vCALC(char operat, int index1, int index2, int index3) {
    if (operat=='+') {  // v1 = v2 + v3
//        printf("\nV%d = ", INDEX_1);
        vSUM(index1, index2, index3);
        }
    else if (operat=='-') {  // v1 = v2 - v3
//        printf("\nV%d = ", INDEX_1);
        vSUB(index1, index2, index3);
        }
    else if (operat=='.') {  // v1 = v2 . v3
//        printf("\nV%d = ", INDEX_1);
        vMULT(index1, index2, index3);
        }
}

void vSUM(int index1, int index2, int index3) {
// get vectors from all three vector indices

// sum all elements of vector 2 and 3  that have the same index and assign them to vector 1 /// add or erase elements if sizes differ

// print vector 1 in next line: v1 is
}

void vSUB(int index1, int index2, int index3) {
// get vectors from all three vector indices

// substract all elements of vector 2 and 3 that have the same index and assign them to vector 1 /// add or erase elements if sizes differ

// print vector 1 in next line: v1 is
}

void vMULT(int index1, int index2, int index3) {
// get vectors from all three vector indices

// multiply all elements of vector 2 and 3  that have the same index and add these values together// assign the value to vector 1 // until smallest vector size is reached

// print vector 1 in next line: v1 is
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


