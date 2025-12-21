#include <stdio.h>
#include <math.h>
//#define _CRT_SECURE_NO_WARNINGS
//i don't get that error on my computer so not needed in my case

int main(){

    int ticketNumber;
    char is3d, isOnline;
    double tDiscount, pPerPerson, tAmount;

    printf("Enter the number of tickets: ");
    scanf("%d", &ticketNumber);
    printf("Is 3d movie (y/n): ");
    scanf(" %c", &is3d);
    printf("Is reserved online (y/n): ");
    scanf(" %c", &isOnline);

    if(is3d == 'y'){
        pPerPerson = 310;
        printf("\nTicket price per person: %.0f\n\n", pPerPerson);
    }
    else{
        pPerPerson = 150;
        printf("\nTicket price per person: %.0f\n\n", pPerPerson);
    }

    if(isOnline == 'y')
        tDiscount += 0.15;
    
    tAmount = pPerPerson * ticketNumber;
    printf("Total amount: %.2f TL\n", tAmount);
    printf("Discount: %.2f TL\n", tAmount * tDiscount);
    tAmount -= tAmount * tDiscount;
    printf("Please pay: %.2f TL", tAmount);

    return 0;
}