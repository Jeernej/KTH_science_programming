#include <stdio.h>

main(){
    int *p1, *p2;
    int v, v1;
    
    p1 = &v;
    *p1 = 42;
    p2 = p1;
    printf("*p1 == %d, *p2 == %d\n", *p1, *p2);
    
    *p2 = 53;
    printf("*p1 == %d, *p2 == %d\n", *p1, *p2);
    
    p1 = &v1;
    *p1 = 88;
    printf("*p1 == %d, *p2 == %d\n", *p1, *p2);
    
    printf("I hope you get the point of this example\n");
}