#include <stdio.h>

int main(){

    int num, basamak, i, sum = 0, mult = 1, p;

    printf("Enter a number: ");
    scanf("%d", &num);

    i = num;
    p = num;

    while(i > 0){
        sum += i % 10;
        mult *= i % 10;
        i /= 10;
        
    }
    
    printf("Given num: %d, Sum: %d, Product: %d\n", num, sum, mult);

    if(sum == mult)
        printf("%d is a spy number :)\n", num);
    else
        printf("%d is not a spy number :(\n", num);
    
    return 0;
}