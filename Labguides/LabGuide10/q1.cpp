#include <stdio.h>

int isPrime(int num);

int main(){

    int num = 1;

    while(num > 0){
        printf("Enter a number: ");
        scanf("%d", &num);
        if(num > 0){
            if(isPrime(num) == 1)
                printf("The number %d is a prime number.\n", num);
            else
                printf("The number %d is not a prime number.\n", num);
            }
        else
            printf("Goodbye!\n");
    }

    return 0;
}

int isPrime(int num){
    int count = 0;
    for(int i = 2; i <= num / 2; i++){
        if(num % i == 0)
            count += 1;
    }
    if(count == 0)
        return 1;
    else
        return 0;
}