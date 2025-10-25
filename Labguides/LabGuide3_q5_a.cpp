#include <stdio.h>
#include <math.h>

int main(){

    double a, b, c, e, r, result;

    a= 4;
    b= 6;
    c= 7;
    e= 3.5;
    r= 2;

    result = r + sqrt((c + a * r / b) / (r * a / e)) / ((b + 4) / e);
    
    printf("Result of the equation is %.2f\n", result);

    return 0;
}
