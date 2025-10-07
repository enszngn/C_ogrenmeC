#include <stdio.h>

int main(){

    //arithmetic operators: +, -, *, /, %, ++, --
    
    //+ - * self explanatory

    int x = 2;
    int y = 3;
    int z = 0;

    z = x / y; //because both all the variables are int answer will be int

    int x1 = 2;
    int y1 = 3;
    float z1 = 0;

    z1 = x1 / y1; //this also doesn't work because two ints divided by each other will be an int

    float x2 = 2;
    int y2 = 3;
    float z2 = 0; 

    z2 = x2 / y2; //this will work. if there is one float in the operation answer will be float



    printf("%d\n", z);
    printf("%lf\n", z1);
    printf("%lf\n", z2);

    int a;

    a = 10;

    a++; // generally used in loops
    printf("%d is a\n", a);
    a--; //generally used in loops
    printf("%d this is now a\n", a);
    if(a>5)
        a--;

    printf("%d azaldi\n", a);
    a = 10;
    a = a + 10; //bununla a+=10 ayni sey
    printf("%d\n", a);
    a+=10;
    printf("%d\n", a);
    a = a * 2;
    printf("%d\n", a);
    a*=2;
    printf("%d\n", a);
    a = a / 2;
    printf("%d\n", a);
    a/=2;
    printf("%d\n", a);  //hepsi bunlar icin de gecerli

    return 0;
}