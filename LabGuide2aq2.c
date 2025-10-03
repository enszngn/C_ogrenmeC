#include <stdio.h>

int main(){
double a, b, c, sol;
a = 3.5;
b = 4.2;
c = 7;

sol = (a + b * b) / (a / c) - b * c / (2 * a);

printf("%.2lf", sol);

    return 0;
}