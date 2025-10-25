#include <stdio.h>

int main(){

    double num;

    printf("Enter a number (2 digits decimal and 4 digits fractional):  ");
    scanf("%lf", &num);
    
    printf("%.0lf\n", num);
    printf("%.5lf\n", num);
    printf("%.8lf\n", num);
    printf("%9.1lf\n", num);
    printf("%.7lf\n", num);
    printf("%.2lf\n", num);
    printf("%6.0lf\n", num);


    return 0;
}