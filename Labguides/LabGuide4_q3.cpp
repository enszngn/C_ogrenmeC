#include <stdio.h>
#include <math.h>

int main(){

    int side1, side2;
    printf("Enter first side of rectangle: ");
    scanf("%d", &side1);
    printf("Enter second side of rectangle: ");
    scanf(" %d", &side2);

    if(side1 == side2)
        printf("It is a square!");
    else
        printf("It is a rectangle!");
        
    return 0;
}