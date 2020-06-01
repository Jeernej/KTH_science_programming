#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//Write a rational number struct. Then write the following functions:

typedef struct {
    int a;
    int b;
} my_rational;
//The members of a structure can be accessed by either of
//(*pointer_to_struct).member
//pointer_to_struct.member

my_rational negative_rational(my_rational r){

    my_rational R;
    R.a=r.a;
    R.b=r.b;

    if (R.b<0) { R.b=-R.b; R.a=-R.a;} // correct for the minus sign

    return R;
}

my_rational normalize_rational(my_rational r){

    my_rational R;
    R=negative_rational(r);

//    printf ("\nNegative corrected value is R=%d/%d.", R.a , R.b );

    int A=R.a, B=R.b;
    float  x,y;

    x= (float) (A/B); 
    y= (float) A/B;

//    printf ("\nSo far the neg. corrected value is R=%d/%d.", A , B );
//    printf ("\nSo far the neg. corrected value is x=%f, y=%f.", x , y );

    if (abs(R.a)==1) return R;

    else if (x==y) {R.a=A/B; R.b=1;return R;}


    else{
        for (int i=2; i<=abs(A); i++) {
        
            x= (float) (A/i);
            y= (float) A/i;
            
            if (x==y) { 
                x= (float) (B/i);
                y= (float) B/i;
                    if (x==y) { R.a=A/i; R.b=B/i;}
                }

            }
        }
    return R;   
}


my_rational add_rationals(my_rational r1, my_rational r2){

    my_rational r;

    r.b = r1.b  * r2.b ;
    r.a = r1.a  * r2.b + r2.a  * r1.b ;

//    printf ("\nSummed value is R=%d/%d.", r.a , r.b );
//    return r;
    return normalize_rational(r);
}


my_rational multiply_rationals(my_rational r1, my_rational r2){

    my_rational r;

    r.a = r1.a * r2.a ;
    r.b = r1.b * r2.b ;

//    printf ("\nProduct value is R=%d/%d.", r.a , r.b );
//    return r;
    return normalize_rational(r);
}

int rationals_equal(my_rational R1, my_rational R2){

    if ( (R1.a == R2.a) && (R1.b == R2.b) ) return 1;

    else return 0;

}


int main() {

    int a1, b1, a2, b2;
    my_rational r1, r2, R1, R2, SUM, PROD;

		printf ("\nEnter the first rational number r1=a1/b1.\n");

		printf ("\na1=");
		scanf ("%d", &a1); 
		printf ("\nb1=");
		scanf ("%d", &b1); 

		printf ("\nEnter the second rational number r2=a2/b2.\n");
		printf ("\na2=");
		scanf ("%d", &a2); 
		printf ("\nb2=");
		scanf ("%d", &b2); 

    if ( (b1==0) || (b2==0) || (a1==0) || (a2==0)){printf ("\nIntegers must not have a value of zero!!"); return 0;}

    r1.a =a1;
    r1.b =b1;
    r2.a =a2;
    r2.b =b2;

    printf ("\nYou entered r1=%d/%d  and  r2=%d/%d.\n", r1.a , r1.b , r2.a , r2.b  );

    R1 = normalize_rational(r1);
    R2 = normalize_rational(r2);

    printf ("\nNormalised values are r1=%d/%d  and  r2=%d/%d.\n", R1.a , R1.b , R2.a , R2.b  );

    SUM=add_rationals(R1, R2);
    PROD=multiply_rationals(R1, R2);

    if (rationals_equal(R1, R2)==1) printf ("\nEntered rational numbers ARE equal!");
    else printf ("\nEntered rational numbers are NOT equal.");
    printf ("\nSum of the entered rational numbers is: r=%d/%d." , SUM.a , SUM.b  );
    printf ("\nProduct of the entered rational numbers is: r=%d/%d.\n\n", PROD.a , PROD.b  );

return 0;
}

