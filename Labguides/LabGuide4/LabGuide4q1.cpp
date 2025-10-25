#include <stdio.h>
#include <math.h>

int main(){

    int a, b;
    double c, d, result;
    

    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);
    printf("Enter c and d: ");
    scanf(" %lf %lf", &c, &d);

    result = fabs((a*a+sqrt(b)) / (c / sqrt(pow(5, d)) - pow(b,3) / 7 + 2));
    printf("Result is %lf.", result);

    return 0;
}