#include <stdio.h>

#define priceItem 15.5

int main(){

    int totalItem;
    double sumPrice = 0;
    
    printf("Enter the amount of items: ");
    scanf("%d", &totalItem);

    for(int i = 1; i <= totalItem; i++ ){

        int bookPrice = priceItem;
        
        if(i > 10)
            sumPrice += bookPrice * 0.85;
        else if(i <= 5)
                sumPrice += bookPrice;
            else
                sumPrice += bookPrice * 0.9;
    }

    printf("Please pay: %.2f\n", sumPrice);

    return 0;
}