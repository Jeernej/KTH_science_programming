#include <stdio.h>
#include <stdbool.h>
#include <string.h> // must cal to be able to use the strlen() function

const int size_str = 400;

char S[31];
int nS[31];
int inputs=0;
void letters(char *str);

void main(){

    char str[size_str];

    printf("Enter a line of text:\n");
    fgets(str, sizeof(str), stdin); /// stdin is used as argument to read from the standard input.
    printf("\nYou have entered:\n%s", str);

       letters(str); /// the name of the array is its adress by default

    printf("\nFrequency of letters in order of appeance in text:\n\n");
    for (int i=0; i<inputs-1; i++) printf(" %c : %d \n", S[i], nS[i]);      
}


void letters(char *str){
   
    bool new_lett;

    for (int i=0; i<strlen(str) ;i++){ 

        new_lett=true;

        for (int j=0; j<strlen(S) ;j++){
            if (str[i] == S[j]) { nS[j]++; new_lett=false; break;}  // counting requency of chars already in the list
            }

        if (new_lett==true){  // adding new char to list
                S[inputs]=str[i];
                nS[inputs]++;
                inputs++; 
            }
    
        }

}

