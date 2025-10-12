#include <stdio.h>
#include <math.h>

int main(){
    int binary,decimal;
    printf("Enter a five digit binary number: ");
    scanf("%d",&binary);
    int a1,a2,a3,a4,a5,b1,b2;
    a1 = binary/10000%10;
    a2 = binary/1000%10;
    a3 = binary/100%10;
    a4 = binary/10%10;
    a5 = binary%10;
    decimal = a1 * pow(2,4) + a2 * pow(2,3) + a3 * pow(2,2) + a4 * 2 + a5;
    printf("Decimal equivalent: %d\n",decimal);
    b1 = decimal/10;
    b2 = decimal%10;
    printf("Digits of the decimal: %d and %d\n",b1,b2);
    printf("Sum of its digits: %d\n", b1 + b2);

    return 0;
}