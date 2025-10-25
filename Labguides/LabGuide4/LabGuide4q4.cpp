#include <stdio.h>
#include <math.h>

int main(){
    int amount;
    printf("Enter total purchase amount: ");
    scanf("%d", &amount);
    if(amount<500)
        printf("Sorry! No discount applied :(\n");
    else{
        printf("You earned a discount :)\n");
        amount = amount * 9 / 10;
    }
    printf("Please pay %d.\n", amount);
    return 0;
}