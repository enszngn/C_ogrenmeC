#include <stdio.h>

int findNumOfDigits(int num);

int countDigitsEqualTo(int num, int digitNum);

int main(){

    int num;

    do{
        printf("Enter a positive integer (0 to stop): ");
        scanf("%d", &num);
        if(num > 0){
            
            printf("Digit count = %d\n", findNumOfDigits(num));
            printf("Num of digits equal to digit count = %d\n", countDigitsEqualTo(num, findNumOfDigits(num)));
        }
        else if(num != 0)
                printf("Error! Number must be positive.\n");
    } while(num < 0);
    printf("Program ended.");

    return 0;
}

int findNumOfDigits(int num){
    int count = 0;

    while(num > 0){
        num /= 10;
        count++;
    }
    return count;
}

int countDigitsEqualTo(int num, int digitNum){
    int equal = 0, digit;

    while(num > 0){
        if(num % 10 == digitNum)
            equal++;
        num /= 10;
    }
    return equal;
}
