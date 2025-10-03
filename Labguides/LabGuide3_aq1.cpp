#include <stdio.h>

int main(){

    double oClothes, pNewClothes, discount, save;

    oClothes = 0;
    pNewClothes = 0;

    printf("Enter the number of old clothes: ");
    scanf("%lf", &oClothes);
    printf("Enter the price of new clothes: ");
    scanf(" %lf", &pNewClothes);

    discount = pNewClothes / 5;
    save = oClothes * 50;

    printf("The store saved %.2lf TL from recycling.\n\n", save);
    printf("You win %.2lf TL discount :)\n", discount);
    printf("Please pay %.2lf", pNewClothes - discount);



    return 0;
}