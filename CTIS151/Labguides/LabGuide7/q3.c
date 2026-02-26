#include <stdio.h>

int main(){

    int num, sumperf = 0, i;

    printf("Enter an integer: ");
    scanf("%d", &num);

    for(i = 1; i < num; i++){

        if(num %i == 0)
            sumperf += i;
    }
    
    if(sumperf == num)
        printf("The number %d is a perfect number\n", num);
    else
        printf("The number %d is not a perfect number\n", num);

    return 0;   
}