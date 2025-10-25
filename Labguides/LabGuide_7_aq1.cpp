#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define priceofm2 112.50

int main(){

    int numofcus, i, random, carpetarea;
    double tPrice, discount = 0, generalsum = 0;
    srand(time(NULL));

    printf("Enter the number of waiting customers: ");
    scanf("%d", &numofcus);

    random = rand() % numofcus + 1;

    for(i = 1; i <= numofcus; i++){
        printf("\nEnter the area of your carpet: ");
        scanf(" %d", &carpetarea);
        if(i == random){
            discount += 0.65;
            printf("CONGRATULATIONS!! YOU WON AN EXTRA %%65 DISCOUNT!!\n");
        }
        else
            discount = 0;
        tPrice = carpetarea * priceofm2;
        tPrice -= tPrice * discount;
        generalsum += tPrice;
        printf("You should pay %.2f TL\n", tPrice);
    }

    printf("The company has earned %.2f TL from the opening day.\n", generalsum);

    return 0;
}