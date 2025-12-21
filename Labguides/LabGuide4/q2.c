#include <stdio.h>
#include <math.h>

int main(){

    int a, b, result; 
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    result = (fabs(a + b) + 5 == 25) || ((a / b != 3) && !(a + a * b - 2) < 1);
    printf("Result is %d.\n", result);

    return 0;
}