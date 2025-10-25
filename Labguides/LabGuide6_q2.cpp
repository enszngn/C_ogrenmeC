#include <stdio.h>

int main(){

    char taxgroup;
    double price ,taxrate;

    printf("Enter tax group code...: ");
    scanf("%c", &taxgroup);

    printf("Enter the price of the item: ");
    scanf(" %lf", &price);

    switch(taxgroup){

        case 'T': 
        case 't': taxrate = 0.15;
                break;

        case 'L':
        case 'l': taxrate = 0.2;
                break;

        case 'C':
        case 'c': taxrate = 0.18;
                break;
        
        case 'A':
        case 'a': taxrate = 0.22;
            
        default: taxrate = 0.1;
    
    }

    if(taxrate == 0.1)
        printf("WARNING!! Unknown category! Tax rate is %10   ");

    printf("\n\nVAT amount: %.2f\n", price * taxrate);
    price += price * taxrate;
    printf("Total price: %.2f\n", price);

    return 0;
}