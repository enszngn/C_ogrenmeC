#include <stdio.h>

int main(){

    double oClothes, pNewClothes;

    oClothes = 0;
    pNewClothes = 0;

    printf("Enter the number of old clothes: ");
    scanf("%lf", &oClothes);
    printf("Enter the price of new clothes: ");
    scanf(" %lf", &pNewClothes);
    
    printf("The store saved %.2lf TL from recycling.\n\n", oClothes * 50);
    printf("You win %.2lf TL discount :)\n", pNewClothes / 5);
    printf("Please pay %.2lf", pNewClothes * 4 / 5);

    return 0;
}