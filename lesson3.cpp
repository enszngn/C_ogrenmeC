#include <stdio.h>
#include <stdbool.h>

int main(){


    //format specifiers %d for int
    //%f for float and double
    //%c for char
    //%s for string (char array)
    //%lf for double

    int age = 19;
    float price = 39.99;
    double pi = 3.1415926;
    char grade = 'A';
    char name[] = "Enes Zengin";

    printf("%d years old\n", age);
    printf("%f is the price\n", price);         //these two
    printf("%lf is the value of pi\n", pi);     //are same in printf
    printf("%c is my grade\n", grade);
    printf("%s is my name\n", name);

    //after some time we're gonna take user input with scanf. When we want to get a double we want to use %lf so generally using %lf is a good habit

    //i watched a video about it. So it's basically in c language printf uses %f for both float and double but scanf uses %f for float and %lf for double
    //so when we want to use scanf for double we have to use %lf. So it's a good habit to use %lf for double in printf too.

    //width

    int num1, num2, num3;
    num1 = 1;
    num2 = 10;
    num3 = 100;

    printf("%10d\n", num1);
    printf("%10d\n", num2);
    printf("%010d\n", num3);

    //precision

    float num4 = 1.999999;
    float num5 = 10.123456;
    float num6 = -100.123456;
    float num7 = 100.030;

    printf("%2.4lf\n", num4);
    printf("%.4lf\n", num5);
    printf("%.5lf\n", num6);
    printf("%8.2lf\n", num7);

    //flags

    printf("%-5.6lf\n", num4);
    printf("%+5.2lf\n", num5);
    printf("%05.2lf\n", num6);


    return 0;
}