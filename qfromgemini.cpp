#include <stdio.h>
#include <math.h>

int main(){

int start, end, sum = 0;

    printf("Enter the starting decimal: ");
    scanf("%d", &start);
    printf("Enter the ending decimal: ");
    scanf(" %d", &end);

    for(int i = start; i <= end; i++){
        sum += i;
    }

    printf("Sum of the numbers is %d", sum);
    
    return 0;
}