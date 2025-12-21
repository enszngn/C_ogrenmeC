#include <stdio.h>
#include <math.h>

int convertToBase(int num, int base);

int main(){
    int base, num;
    printf("Enter the base: ");
    scanf("%d", &base);
    printf("Enter the number: ");
    scanf("%d", &num);

    printf("\nThe decimal value of the number %d in base %d is %d\n", num, base, convertToBase(num, base));

    return 0;
}

int convertToBase(int num, int base){
    int digitNum = 1, modifiableNum, decimalValue = 0;
    modifiableNum = num;

    while(modifiableNum > 0){
        modifiableNum /= 10;
        digitNum++;
    }

    for(int i = 1, p = 0; i <= digitNum; i++, p++){
        decimalValue += num % 10 * pow(base, p);
        num /= 10;
    }

    return decimalValue;
}