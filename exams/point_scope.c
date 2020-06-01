# include <stdio.h>

void func(int a, int *b, int c){

    a = a + 100;
    *b = *b + 200;
    c = c + 300;

    printf("2nd printout: %d %d %d \n", a, *b, c);

}

void main(){

    int a = 10, *b, c = 30;
    b = &a;
    
    printf("1st printout: %d %d \n", a, *b);
    func(c, &a, *b);
    printf("3rd printout: %d %d %d \n", a, *b, c);

}