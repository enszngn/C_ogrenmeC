#include <stdio.h>
#include <math.h>

int main(){

    double a, b, c, e, r, result;

    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf(" %lf", &b);
    printf("Enter c: ");
    scanf(" %lf", &c);
    printf("Enter e: ");
    scanf(" %lf", &e);
    printf("Enter r: ");
    scanf(" %lf", &r);

    result = r + sqrt((c + a * r / b) / (r * a / e)) / ((b + 4) / e);
    
    printf("Result of the equation is %.2f\n", result);

    return 0;
}