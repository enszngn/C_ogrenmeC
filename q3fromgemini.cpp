#include <stdio.h>

int main(){

    int water, month;
    double price = 0;

    printf("Enter amount of water used in m3: ");
    scanf("%d", &water);
    printf("Enter the current month as an integer: ");
    scanf(" %d", &month);

    for(int i = 1; i <= water; i++){

        if(i <= 50)
            price += 1.5;
        else if(i > 150)
                price += 3.;
            else
                price += 2.25;
        }

    printf("The base cost is %.2f TL\n", price);
    
    if(month == 6 || month == 7 || month == 8)
        if(water > 100){
            printf("Surcharge amount is %.2f TL\n", price * 0.05);
            price += price * 0.05;
        }

    printf("Final amount: %.2f TL\n", price);

    return 0;
}