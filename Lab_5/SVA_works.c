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
    double data;
    struct el *elements;
};
typedef struct el eltype;

struct svector{
    int size;
    eltype * elements;
};

struct svector SV0;  // home of vector temp
struct svector SV1; // home of results fo calclations v1 = v2 + v3 etc.
struct svector SV2; // dummmy v2
struct svector SV3; // dummmy v3

int ALL_VECTORS;
char OPERATOR;
int INDEX_1;
int INDEX_2;
int INDEX_3;
double SCALAR;

//
//Your program will read a database of sparse vectors from a text file. 
//Each vector is represented as decimal values placed on a separate line.
//The file may contain at most 100 vectors. The vectors will
//be referred to with the keyword v and their order in the database file.
//

//void Menu (int *choice);

int readVector(int INDEX, struct svector *x);
void printVector (struct svector *x);

int ASGN(int index1, int index2) ;

void CALC(char operat, int index1, int index2);
void SUM(int index1, int index2);
void SUB(int index1, int index2);
void MULT(int index1, int index2);
void SCALE(int index2, double scale); 

int vASGN(int index1,struct svector SV);
void vCALC(char operat, int index1, int index2, int index3);
void vSUM(int index1, int index2, int index3);
void vSUB(int index1, int index2, int index3);
void vMULT(int index1, int index2, int index3);
void vSCALE(int index1, int index3, double scale); 



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
//    readVector(&temp); // reads in a vector from standard input or file
//	printf("\nDatabase read, waiting for command\n");
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
     printf("\n>");
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
        double SCALAR=1;
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
                                    double BIG=0;
                                    double SMALL=0;
                                    int real=0;
                                    int r=1;
                                    while (j<DIFF1-3){

                                        if (operat[EQ_pos+2+j]==',') { real=1;}
                                        else if (real==0) { BIG=10*BIG+(double) operat[EQ_pos+2+j] - '0'; }
                                        else if (real==1) { SMALL=SMALL+((double) operat[EQ_pos+2+j] - '0')/(double) pow(10,r); r++;}
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
                        double BIG=0;
                        double SMALL=0;
                        int real=0;
                        int r=1;
                        while (j<OP_pos-1){

                            if (operat[j]==',') { real=1;}
                            else if (real==0) { BIG=10*BIG+(double) operat[j] - '0'; }
                            else if (real==1) { SMALL=SMALL+((double) operat[j] - '0')/(double) pow(10,r); r++;}
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

//    readVector(INDEX,&SV1);
//    printVector(&SV1); 
//        printf("\nEQ_pos=%d, OP_pos=%d Scaled=%d\n",EQ_pos,OP_pos,Scaled);

        if (operat[0]=='\n'){printf("Wrong input form.\n"); }

        else if (EQ_pos==0 && OP_pos==0 && Scaled!=1){ /// printing values  KONČANO!!
            if (INDEX_1==0 && TEMP==0) {printf("Wrong input form.\n"); }
            else if (INDEX_1!=0 && TEMP==0) {
//            if (INDEX_1!=0 && TEMP==0) {
                printf("\nV%d is ", INDEX_1);
                int read=1;
                read=readVector(INDEX_1,&SV1);
                if(read==1) printVector(&SV1); 
                else  printf("Wrong index!\n");
//                printVector(INDEX_1);
                }
            else if (INDEX_1==0 && TEMP!=0) {
                printf("\ntemp is "); 
                if (SV0.elements==NULL) printf("empty.\n");
                else printVector(&SV0); 
//                printVector(0);
                }
            }

        else if (EQ_pos==0 && OP_pos!=0 && Scaled!=1) { /// calculating and printing values KONČANO!!

            if (INDEX_1==0 && INDEX_2==0 && TEMP==0) {printf("Wrong input form.\n"); }
            else if (INDEX_1!=0 && INDEX_2!=0 && TEMP==0) {  // v1 . v2
//            if (INDEX_1!=0 && INDEX_2!=0 && TEMP==0) {  // v1 . v2
//                printf("\nV%d = ", INDEX_1);
                CALC(operat[OP_pos], INDEX_1, INDEX_2);
                }
            else if (INDEX_1!=0 && INDEX_2==0 && TEMP!=0) { // v1 . temp
                if (SV0.elements==NULL) printf("Nothing to calculate here yet...\n");
                CALC(operat[OP_pos], INDEX_1, 0);
                }
            else if (INDEX_1==0 && INDEX_2!=0 && TEMP!=0) { // temp . v2
                if (SV0.elements==NULL) printf("Nothing to calculate here yet...\n");
                CALC(operat[OP_pos], 0, INDEX_2);
                }
            else if (INDEX_1==0 && INDEX_2==0 && TEMP!=0) { // temp . temp
                if (SV0.elements==NULL) printf("Nothing to calculate here yet...\n");
                CALC(operat[OP_pos], 0, 0);
                }
            }
        else if (EQ_pos==0 && OP_pos!=0 && Scaled==1) { /// scaling and printing vectors KONČANO!!

            if (INDEX_2!=0 && TEMP==0) {  // SCALAR . v1
                SCALE(INDEX_2,SCALAR);
                }
            else if (INDEX_2==0 && TEMP!=0) {  // SCALAR . temp
                if (SV0.elements==NULL) printf("Nothing to scale here yet...\n");
                SCALE(0,SCALAR);
                }
            }

        else if (EQ_pos!=0 && OP_pos==0  && Scaled!=1) { /// defining values

            if (INDEX_1==0 && INDEX_2==0 && TEMP==0) {printf("Wrong input form.\n"); }
            else if (INDEX_1!=0 && INDEX_2!=0 && TEMP==0) {  // v1 = v2
                printf("\nV%d = ", INDEX_1);
                if (INDEX_1==INDEX_2) {printVector(&SV1);}
                else ASGN(INDEX_1,INDEX_2);
                }
            else if (INDEX_1!=0 && INDEX_2==0 && TEMP!=0) { // v1 = temp
                if (SV0.elements==NULL) printf("Nothing to be assigned here yet...\n");
                else{
                    printf("\nV%d = ", INDEX_1);
                    ASGN(INDEX_1,0);
                    }
                }
            else if (INDEX_1==0 && INDEX_2!=0 && TEMP!=0) { // temp = v2
                printf("\ntemp = "); 
                ASGN(0,INDEX_2);
                printVector(&SV0);
                }
            else if (INDEX_1==0 && INDEX_2==0 && TEMP!=0) {  // temp = temp
                if (SV0.elements==NULL) printf("Nothing to be assigned here yet...\n");
                else{
                    printf("\ntemp = "); 
                    printVector(&SV0);
                    }
                }
            }

        else if (EQ_pos!=0 && OP_pos!=0 && Scaled==1) { /// scaling  vectors
            if (INDEX_1==0 && INDEX_2==0 && SCALAR==1 && TEMP==0) {printf("Wrong input form.\n"); }
            else if (INDEX_1!=0 && INDEX_3!=0 && TEMP==0) {  // v1 = SCALAR . V3
                printf("\nV%d = ", INDEX_1);
                vSCALE(INDEX_1,INDEX_3,SCALAR);
                }
            else if (INDEX_1!=0 && INDEX_3==0 && TEMP!=0) { // v1 = SCALAR . temp
                if (SV0.elements==NULL) printf("Nothing to scale here yet...\n");
                else{
                    printf("\nV%d = ", INDEX_1);
                    vSCALE(INDEX_1,0,SCALAR);
                    }
                }
            else if (INDEX_1==0 && INDEX_3!=0 && TEMP!=0) { // temp = SCALAR . V3
                printf("\ntemp = "); 
                vSCALE(0,INDEX_3,SCALAR);
                }
            else if (INDEX_1==0 && INDEX_3==0 && TEMP!=0) { // temp = SCALAR . temp
                if (SV0.elements==NULL) printf("Nothing to scale here yet...\n");
                else{
                    printf("\ntemp = "); 
                    vSCALE(0,0,SCALAR);
                    }
                }
            }

        else if (EQ_pos!=0 && OP_pos!=0 && Scaled==0) { /// calculating values
            if (INDEX_1==0 && INDEX_2==0 && INDEX_3==0 && TEMP==0) {printf("Wrong input form.\n"); }
            else if (INDEX_1!=0 && INDEX_3!=0 && TEMP==0 && INDEX_2==INDEX_3 && operat[OP_pos]=='+') {  // v1 = v2 + v2
                printf("\nV%d = ", INDEX_1);
                vSCALE(INDEX_1,INDEX_3,2);
                }
            else if (INDEX_1!=0 && INDEX_3!=0 && TEMP==0 && INDEX_2==INDEX_3 && operat[OP_pos]=='-') {  // v1 = v2 - v2
                printf("\nV%d = ", INDEX_1);
                vSCALE(INDEX_1,INDEX_3,0);
                }
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
            else if (INDEX_1!=0 && INDEX_2==0 && INDEX_3==0 && TEMP!=0 && operat[OP_pos]=='+') {  // v1 = temp + temp
                printf("\nV%d = ", INDEX_1);
                vSCALE(INDEX_1,0,2);
                }
            else if (INDEX_1!=0 && INDEX_2==0 && INDEX_3==0 && TEMP!=0 && operat[OP_pos]=='-') {  // v1 = temp - temp
                printf("\nV%d = ", INDEX_1);
                vSCALE(INDEX_1,0,0);
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
            else if (INDEX_1==0 && INDEX_2==0 && INDEX_3==0 && TEMP!=0  && operat[OP_pos]=='+') {  // temp = temp + temp
                printf("\ntemp = "); 
                vSCALE(0,0,2);
                printVector(&SV0);
                }
            else if (INDEX_1==0 && INDEX_2==0 && INDEX_3==0 && TEMP!=0  && operat[OP_pos]=='-') {  // temp = temp - temp
                printf("\ntemp = "); 
                vSCALE(0,0,0);
                printVector(&SV0);
                }
            }


    else printf("Wrong input form.\n"); 


    } while (out == 0);
    printf("  Bye bye!\n");
}				


/////////////////////////////////////////////////
//*I will help you tomorrow,sleepy now kishore*//
/////////////////////////////////////////////////
//
//struct el{
//    int index;
//    double data;
//    struct el *elements;
//};
//typedef struct el eltype;
//
//struct svector{
//    int size;
//    eltype * elements;
//};
//
/////////////////////////////////////////////////

int ASGN(int index1, int index2) {
// get vectors from both vector indices


   int Lin_el;
   int lin=1;
   struct svector SV_1; 

   if (index2==0) {SV_1=SV0;} // we read from temp to vector file 'v1 = temp'

   else readVector(index2,&SV_1); // we read from vector file and asign it to vector file 'v1 = v2'
   if (index1==0) {SV0=SV_1; return 1;} // we assign value to 'temp = v2' and exit

   int size_1=SV_1.size;
//    printf(" size is %d",size_1);

   char newLine[1000];
   memset(newLine, '\0' , 1000);
///////////////// reading linked list into string newLine ////////////////////////
   struct svector *x=&SV_1;
   eltype * current_x = x-> elements;
    int j=0;
    for(int i=1; i <= x->size; i++){ // print out vector and write the values in file
    
        if(current_x == NULL || current_x->index > i){
            if(i==size_1) {
                newLine[j]='0'; newLine[j+1]='\n';
//                printf("\nZERO element is '%c'", newLine[j]);
                j=j+1;
                }
            else{
                newLine[j]='0';newLine[j+1]=' ';
//                printf("\nZERO element is '%c%c'", newLine[j], newLine[j+1]);
                j=j+2;
                }
            }

        else {
            char c[25];
            memset(c, '\0' , 20);
            sprintf(c, "%f",current_x->data);
            Lin_el=strlen(c);
            for (int k=0; k<Lin_el; k++) {
                newLine[j]=c[k];
//                printf("\nchar %d is %c",j, c[k]); 
                j=j+1;
                }
            if(i==size_1) {
                newLine[j]='\n';
                j=j+1;
                }
            else{
                newLine[j]=' ';
                j=j+1;
                }
//            printf("\nelement is %f", current_x->data);
//            printf("\nelement is %s", c);
//            printf("\nchar is %c", c[0]);
//            printf("\nc size is %d", Lin_el);
            current_x = current_x->elements;
//            j=j+Lin_el;
            }

//        printf("\nnewLine is |%s|",newLine);

    	}
//    printf("\nFinal newLine is |%s|",newLine);


///////////////// writing string newLine to file ////////////////////////

    /* File pointer to hold reference of input file */
    FILE * fPtr;
    FILE * fTemp;
    char buffer[1000];
    int line, count;

    /*  Open all required files */
    fPtr = fopen("test.txt","r");
    fTemp = fopen("replace.tmp", "w"); 

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }

    /*
     * Read line from source file and write to destination 
     * file after replacing given line.
     */
    count = 0;
    while ((fgets(buffer, 1000, fPtr)) != NULL)
    {
        count++;
        /* If current line is line to replace */
        if (count == index1)
            fputs(newLine, fTemp);
        else
            fputs(buffer, fTemp);
    }

    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);

    /* Rename temporary file as original file */
////    rename("replace.tmp", "test.txt");

//    printf("\nSuccessfully replaced '%d' line with '%s' ", index1, newLine);
    printf("%s",newLine);

 return 1;
// print vector 1 in next line: v1 is
}


void SCALE(int index, double scale) {

// get vector from vector index
       struct svector SV; 
       if (index==0) SV=SV0; // write calcualted data to GLOBAL results linked list SV0
       else readVector(index,&SV);; // write calcualted data to GLOBAL results linked list SV0

       struct svector *x=&SV;

	eltype * current_x = x-> elements;

	printf("\n"); // print result in next line
	for(int i=1; i <= x->size; i++){
		if(current_x == NULL || current_x->index > i)
			printf("%f ",0.0);
		else {
			printf("%f ", (current_x->data)*scale); // multiplay all values with the double scalar
			current_x = current_x->elements;
		}
	}
	printf("\n"); 
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
       struct svector SV_1; 
       struct svector SV_2;

       if (index1==0) {SV_1=SV0;} else readVector(index1,&SV_1);
       if (index2==0) {SV_2=SV0;} else readVector(index2,&SV_2);

       int size_1=SV_1.size;
       int size_2=SV_2.size;
       int size_min; 
       int size_max; 
       if(size_1>=size_2){size_max=size_1;size_min=size_2;} else{size_max=size_2;size_min=size_1;}

       struct svector *x1=&SV_1;
       struct svector *x2=&SV_2;
	eltype * current_x1 = x1-> elements;
	eltype * current_x2 = x2-> elements;

	printf("\n"); // print result in next line
	for(int i=1; i <= size_max; i++){

		if( size_2 <i  && size_1<i ){//printf("once");
    			printf("%f ",0.0);
                 }
		else if ( size_2 >=i  && size_1>=i ){//printf("always");

        		if(current_x1->index > i && current_x2->index > i ){
                        printf("%f ",0.0);
                        }
        		else if(current_x1->index > i){
                        printf("%f ",(current_x2->data));
                        current_x2 = current_x2->elements;
                        }        		
        		else if(current_x2->index > i){
                        printf("%f ",(current_x1->data));
                        current_x1 = current_x1->elements;
                        }
        		else {//printf("always2 v3 ");
                        printf("%f ", (current_x1->data)  +  (current_x2->data) );
                        current_x1 = current_x1->elements;
                        current_x2 = current_x2->elements;
                        }
                }  

		else if( size_1 <i  && size_2>=i  ){//printf("something");

        		if(current_x2->index > i)
                        printf("%f ",0.0);
        		else {
                        printf("%f ",(current_x2->data));
                        current_x2 = current_x2->elements;
                        }
                }

		else if( size_2 <i  && size_1>=i  ){//printf("else");
        		if(current_x1->index > i)
                        printf("%f ",0.0);
        		else {
                        printf("%f ",(current_x1->data));
                        current_x1 = current_x1->elements;
                        }
                }
	}
	printf("\n"); 
// sum all elements that have same index /// add or erase elements if sizes differ
// print result in next line
}


void SUB(int index1, int index2) {

       struct svector SV_1; 
       struct svector SV_2;

       if (index1==0) {SV_1=SV0;} else readVector(index1,&SV_1);
       if (index2==0) {SV_2=SV0;} else readVector(index2,&SV_2);

       int size_1=SV_1.size;
       int size_2=SV_2.size;
       int size_min; 
       int size_max; 
       if(size_1>=size_2){size_max=size_1;size_min=size_2;} else{size_max=size_2;size_min=size_1;}

       struct svector *x1=&SV_1;
       struct svector *x2=&SV_2;
	eltype * current_x1 = x1-> elements;
	eltype * current_x2 = x2-> elements;

	printf("\n"); // print result in next line
	for(int i=1; i <= size_max; i++){

		if( size_2 <i  && size_1<i ){//printf("once");
    			printf("%f ",0.0);
                 }
		else if ( size_2 >=i  && size_1>=i ){//printf("always");

        		if(current_x1->index > i && current_x2->index > i ){
                        printf("%f ",0.0);
                        }
        		else if(current_x1->index > i){
                        printf("%f ",(-current_x2->data));
                        current_x2 = current_x2->elements;
                        }        		
        		else if(current_x2->index > i){
                        printf("%f ",(current_x1->data));
                        current_x1 = current_x1->elements;
                        }
        		else {//printf("always2 v3 ");
                        printf("%f ", (current_x1->data)  -  (current_x2->data) );
                        current_x1 = current_x1->elements;
                        current_x2 = current_x2->elements;
                        }
                }  

		else if( size_1 <i  && size_2>=i  ){//printf("something");

        		if(current_x2->index > i)
                        printf("%f ",0.0);
        		else {
                        printf("%f ",(-current_x2->data));
                        current_x2 = current_x2->elements;
                        }
                }

		else if( size_2 <i  && size_1>=i  ){//printf("else");
        		if(current_x1->index > i)
                        printf("%f ",0.0);
        		else {
                        printf("%f ",(current_x1->data));
                        current_x1 = current_x1->elements;
                        }
                }
	}
	printf("\n"); 
}


void MULT(int index1, int index2) {

       double result;
// get vectors from both vector indices
       struct svector SV_1; 
       struct svector SV_2;

       if (index1==0) {SV_1=SV0;} else readVector(index1,&SV_1);
       if (index2==0) {SV_2=SV0;} else readVector(index2,&SV_2);

       int size_1=SV_1.size;
       int size_2=SV_2.size;
       int size_min; if(size_1<=size_2){size_min=size_1;} else{size_min=size_2;}
       struct svector *x1=&SV_1;
       struct svector *x2=&SV_2;
	eltype * current_x1 = x1-> elements;
	eltype * current_x2 = x2-> elements;

        
	printf("\n"); // print result in next line
	for(int i=1; i <= size_min; i++){
		if(current_x1 == NULL || current_x2 == NULL) {result=result;} else if (current_x1->index > i || current_x2->index > i) {result=result;}
//			result=result;
		else {
			result = result + (current_x1->data) * (current_x2->data); // multiplay all values with the double scalar
			current_x1 = current_x1->elements;
                    current_x2 = current_x2->elements;
		}
	}
       
	printf("%f\n",result); 
// multiply all elements that have the same index and add these values together // until smallest vector size is reached

// print result in next line
}


int vASGN(int index1,struct svector SV) {
// get vectors from both vector indices
   int Lin_el;
   int lin=1;
   struct svector SV_1; 

   if (index1==0) {SV0=SV; return 1;} // we assign calculated value to 'temp = v2 + v3' and exit
   if (index1!=0) {SV_1=SV;} // we write calculated value from linked list SV1 to vector in file 'v1 = calcualted'

   int size_1=SV_1.size;
//    printf(" size is %d",size_1);

   char newLine[1000];
   memset(newLine, '\0' , 1000);
///////////////// reading linked list into string newLine ////////////////////////
   struct svector *x=&SV_1;
   eltype * current_x = x-> elements;
    int j=0;
    for(int i=1; i <= x->size; i++){ // print out vector and write the values in file
    
        if(current_x == NULL || current_x->index > i){
            if(i==size_1) {
                newLine[j]='0'; newLine[j+1]='\n';
//                printf("\nZERO element is '%c'", newLine[j]);
                j=j+1;
                }
            else{
                newLine[j]='0';newLine[j+1]=' ';
//                printf("\nZERO element is '%c%c'", newLine[j], newLine[j+1]);
                j=j+2;
                }
            }

        else {
            char c[25];
            memset(c, '\0' , 20);
            sprintf(c, "%f",current_x->data);
            Lin_el=strlen(c);
            for (int k=0; k<Lin_el; k++) {
                newLine[j]=c[k];
//                printf("\nchar %d is %c",j, c[k]); 
                j=j+1;
                }
            if(i==size_1) {
                newLine[j]='\n';
                j=j+1;
                }
            else{
                newLine[j]=' ';
                j=j+1;
                }
//            printf("\nelement is %f", current_x->data);
//            printf("\nelement is %s", c);
//            printf("\nchar is %c", c[0]);
//            printf("\nc size is %d", Lin_el);
            current_x = current_x->elements;
//            j=j+Lin_el;
            }
//        printf("\nnewLine is |%s|",newLine);
    	}
//    printf("\nFinal newLine is |%s|",newLine);

///////////////// writing string newLine to file ////////////////////////

    /* File pointer to hold reference of input file */
    FILE * fPtr;
    FILE * fTemp;
    char buffer[1000];
    int line, count;

    /*  Open all required files */
    fPtr = fopen("test.txt","r");
    fTemp = fopen("replace.tmp", "w"); 

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }

    /*
     * Read line from source file and write to destination 
     * file after replacing given line.
     */
    count = 0;
    while ((fgets(buffer, 1000, fPtr)) != NULL)
    {
        count++;
        /* If current line is line to replace */
        if (count == index1)
            fputs(newLine, fTemp);
        else
            fputs(buffer, fTemp);
    }

    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);

    /* Rename temporary file as original file */
////    rename("replace.tmp", "test.txt");

//    printf("\nSuccessfully replaced '%d' line with '%s' ", index1, newLine);
    printf("%s",newLine);

 return 1;
// print vector 1 in next line: v1 is
}


void vSCALE(int index1, int index3, double scale) {  /// v1 = 3 . v3

// get vector from vector index
       struct svector SV; 
       readVector(index3,&SV); /// read data into GLOBAL dummy linked list
       struct svector *x=&SV;  /// for reading 

//       readVector(index3,&SV3); /// read data into GLOBAL dummy linked list
//       struct svector *x=&SV3;  /// for reading 

       struct svector *result; // write calcualted data to GLOBAL results linked list SV1
       if (index1==0) {result=&SV0; printf("\n inside temp"); }// write calcualted data to GLOBAL results linked list SV0
       else result=&SV; // write calcualted data to GLOBAL results linked list SV0

	eltype * current_x = x-> elements;
	eltype * current_result = result-> elements;

//	printf("\n%d\n",x->size); // print result in next line
	for(int i=1; i <= x->size; i++){
		if(current_x == NULL || current_x->index > i){
			printf("edfv %f ",0.0);
//                    current_result->data=0.0;
//                    current_result = result-> elements;
                }
		else {
			printf("%f ", (current_x->data)*scale); // multiplay all values with the double scalar
                    current_result->data=(current_x->data)*scale;  /// rewrite scaled elements to vctoe SV1
                    current_result->index=current_x->index;   /// rewrite indexes of scaled values to SV1

			current_x = current_x->elements;
                    current_result = current_result-> elements;
		}
//             if (current_x->elements==NULL) {current_result-> elements=NULL; break;}
	}
	printf("\n print VECTOR SV1 \n"); 
       printVector(&SV);

       vASGN(index1,SV);
//       SV1.elements=NULL;
//       SV3.elements=NULL;
       x->elements=NULL;
//       result->elements=NULL;

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

// get vector from vector index
       struct svector SV; 
       struct svector SV_1; 
       struct svector SV_2; 

       readVector(index2,&SV_1); /// read data into GLOBAL dummy linked list
       readVector(index3,&SV_2); /// read data into GLOBAL dummy linked list

       struct svector *x1=&SV_1;  /// for reading 
       struct svector *x2=&SV_2;  /// for reading 

       struct svector *result; // write calcualted data to GLOBAL results linked list SV1
       if (index1==0) {result=&SV0; printf("\n inside temp"); }// write calcualted data to GLOBAL results linked list SV0
       else result=&SV; // write calcualted data to GLOBAL results linked list SV0

       int size_1=SV_1.size;
       int size_2=SV_2.size;
       int size_min; 
       int size_max; 

       if(size_1>=size_2){size_max=size_1;size_min=size_2;	printf("hi");} 
       else{size_max=size_2;size_min=size_1;printf("hiy");}

       printf("\n size max is %d", size_max); 
//       readVector(index3,&SV3); /// read data into GLOBAL dummy linked list
//       struct svector *x=&SV3;  /// for reading 


	eltype * current_x1 = x1-> elements;
	eltype * current_x2 = x2-> elements;

	eltype * current_result = result-> elements;

	printf("hi"); // print result in next line
	for(int i=1; i <= size_max; i++){
//             printf("hy");
		if( size_2 <i  && size_1<i ){//printf("once");
    			printf("%f ",0.0);
                 }
		else if ( size_2 >=i  && size_1>=i ){//printf("always");

        		if(current_x1->index > i && current_x2->index > i ){
                        printf("%f ",0.0);
                        }
        		else if(current_x1->index > i){
                        printf("%f ",(current_x2->data));
                        current_result->data=current_x2->data;  /// rewrite scaled elements to vctoe SV1
                        current_result->index=current_x2->index;   /// rewrite indexes of scaled values to SV1
    
                        current_result = current_result-> elements;
                        current_x2 = current_x2->elements;
                        }        		
        		else if(current_x2->index > i){
                        printf("%f ",(current_x1->data));
                        current_result->data=current_x1->data;  /// rewrite scaled elements to vctoe SV1
                        current_result->index=current_x1->index;   /// rewrite indexes of scaled values to SV1
    
                        current_result = current_result-> elements;
                        current_x1 = current_x1->elements;
                        }
        		else {//printf("always2 v3 ");
                        printf("%f ", (current_x1->data)  +  (current_x2->data) );
                        current_result->data=(current_x1->data)  +  (current_x2->data);  /// rewrite scaled elements to vctoe SV1
                        current_result->index=current_x1->index;   /// rewrite indexes of scaled values to SV1
    
                        current_result = current_result-> elements;
                        current_x1 = current_x1->elements;
                        current_x2 = current_x2->elements;
                        }
                        
                }  

		else if( size_1 <i  && size_2>=i  ){//printf("something");

        		if(current_x2->index > i)
                        printf("%f ",0.0);
        		else {
                        printf("%f ",(current_x2->data));
                        current_result->data=current_x2->data;  /// rewrite scaled elements to vctoe SV1
                        current_result->index=current_x2->index;   /// rewrite indexes of scaled values to SV1
    
                        current_result = current_result-> elements;
                        current_x2 = current_x2->elements;
                        }
                }

		else if( size_2 <i  && size_1>=i  ){//printf("else");
        		if(current_x1->index > i)
                        printf("%f ",0.0);
        		else {
                        printf("%f ",(current_x1->data));
                        current_result->data=current_x1->data;  /// rewrite scaled elements to vctoe SV1
                        current_result->index=current_x1->index;   /// rewrite indexes of scaled values to SV1
    
                        current_result = current_result-> elements;
                        current_x1 = current_x1->elements;
                        }
                }
                 printf("hy");
	}
	printf("\n print VECTOR SV \n"); 
       printVector(&SV);
	printf("\n print VECTOR SV0 \n"); 
       printVector(&SV0);

       vASGN(index1,SV);
       SV1.elements=NULL;
       SV2.elements=NULL;
       x1->elements=NULL;
       x2->elements=NULL;

    free(current_result);
    free(current_x1);
    free(current_x2);
//       result->elements=NULL;

}

void vSUB(int index1, int index2, int index3) {
// get vectors from all three vector indices

// substract all elements of vector 2 and 3 that have the same index and assign them to vector 1 /// add or erase elements if sizes differ

// print vector 1 in next line: v1 is
}

void vMULT(int indexx, int index1, int index2) {

       double result=0;
// get vectors from both vector indices
       struct svector SV_1; 
       struct svector SV_2;

       if (index1==0) {SV_1=SV0;} else readVector(index1,&SV_1);
       if (index2==0) {SV_2=SV0;} else readVector(index2,&SV_2);

       int size_1=SV_1.size;
       int size_2=SV_2.size;
       int size_min; if(size_1<=size_2){size_min=size_1;} else{size_min=size_2;}
       struct svector *x1=&SV_1;
       struct svector *x2=&SV_2;
	eltype * current_x1 = x1-> elements;
	eltype * current_x2 = x2-> elements;

        
	printf("\n"); // print result in next line
	for(int i=1; i <= size_min; i++){
		if(current_x1 == NULL || current_x2 == NULL) {result=result;} else if (current_x1->index > i || current_x2->index > i) {result=result;}
//			result=result;
		else {
			result = result + (current_x1->data) * (current_x2->data); // multiplay all values with the double scalar
			current_x1 = current_x1->elements;
                    current_x2 = current_x2->elements;
		}
	}
       
	printf("%f\n",result); 


    char newLine[25];
    memset(newLine, '\0' , 25);

    char c[25];
    memset(c, '\0' , 25);
    sprintf(c, "%f",result);
    int Lin_el=strlen(c);
    int j=0;
    for (int k=0; k<Lin_el; k++) {
        newLine[j]=c[k];
    //                printf("\nchar %d is %c",j, c[k]); 
        j=j+1;
        }
    newLine[j]='\n';

    FILE * fPtr;
    FILE * fTemp;
    char buffer[1000];
    memset(c, '\0' , 1000);
    int line, count;

    /*  Open all required files */
    fPtr = fopen("test.txt","r");
    fTemp = fopen("replace.tmp", "w"); 

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }

    /*
     * Read line from source file and write to destination 
     * file after replacing given line.
     */
    count = 0;
    while ((fgets(buffer, 1000, fPtr)) != NULL)
    {
        count++;
        /* If current line is line to replace */
        if (count == indexx)
            fputs(newLine, fTemp);
        else
            fputs(buffer, fTemp);
    }

    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);

    /* Rename temporary file as original file */
////    rename("replace.tmp", "test.txt");

//    printf("\nSuccessfully replaced '%d' line with '%s' ", index1, newLine);
    printf("%s",newLine);
//    free(current_x1);
//    free(current_x2);
}


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


int readVector(int INDEX, struct svector *x) {

   int lin=1;
   char readtemp;
   int size=1000;
   double array[1000];
//   double *array;
//   array=(double *)malloc(sizeof(double));

//   double *array=NULL;
//   array=realloc(array,sizeof(double));
   int i=0;
   int flag=0;
   int exp=1;
//   int NumbfileV=0;
   FILE *fp;
  
   fp = fopen("test.txt","r");

   if (fp == NULL) perror("Error in opening file"); 

   do {
        readtemp = fgetc(fp);
//        printf("%c", readtemp);
        if ( feof(fp) ) {ALL_VECTORS=lin-1;break;}

        if ( readtemp == '\n'){ // printf("line %d \n",lin);
            lin++;
            }

        if (readtemp != '\n' && lin==INDEX){

            if ('0'<= readtemp &&  readtemp <= '9'){

                if (flag==0) {array[i]= (double) (readtemp - '0');flag=1;}

                else if (flag==1) {array[i]= 10.0 * array[i] + (double) (readtemp - '0');} //88

                else if (flag==-1) {
//                     printf(" \narr i=%d is %f ",i,array[i]);
//                     printf(" \narr i=%d is %f ",i,(double) (readtemp - '0') / (pow(10,exp)));
                    array[i]= array[i] + ((double) (readtemp - '0')) / (pow(10,exp));exp=exp+1;
//                     printf(" \narr i=%d is %f ",i,array[i]);

                    } //.99
                else flag=1;
              

                }
            else if (readtemp=='.'){
                flag=-1;
                }
            else if (readtemp==' ' || readtemp=='\n'){
                flag=0;
//                if((double *)realloc(array, sizeof(double))==NULL){printf("Not enough memory for array from line %d!!",INDEX);break;}
//                array=(double *)realloc(array, sizeof(double));
                i++;
                exp=1;
                }
           }

   } while(lin<=INDEX || !feof(fp));

   if (INDEX>ALL_VECTORS) { printf("\nNumber of vectors in file is only %d.\n",ALL_VECTORS);return 0;}
//    printf("\narray %d is\n ",INDEX);    
//    for (int j=0; j<=i; j++) printf("%f ", array[j]);
//    printf("\n");    
//    printf("\nwith size %d and last value %f\n",i+1,array[i]);    
//    printf("\nNumber of vectors in file is %d.\n",lin-1);    

//////////////////////////////////////////////////////////////////////
//void readVector (double *array, struct svector *x){
//////////////////////////////////////////////////////////////////////
       eltype *last_x = NULL;
	int index=0;
       x->size=i+1;
	for(int j=0; j <= size ; j++){
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
    return 1;
}
