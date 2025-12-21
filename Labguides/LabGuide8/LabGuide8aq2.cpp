#include <stdio.h>

int main(){

    int juice, milk, coke, purchased;
    char type;

    printf("Enter case inventory for Fruit Juice: ");
    scanf("%d", &juice);
    printf("Enter case inventory for Milk: ");
    scanf("%d", &milk);
    printf("Enter case inventory for Coke: ");
    scanf("%d", &coke);

    while(juice > 0 && milk > 0 && coke > 0){
        printf("Enter the drink code (Fruit Juice(F/f), Milk(M/m), Coke(C/c) ): ");
        scanf(" %c", &type);
        printf("Enter the amount purchased (>0) / amount sold (<0): ");
        scanf(" %d", &purchased);
        switch(type){
            case 'F':
            case 'f': 
                if(juice + purchased >= 0)
                    {juice += purchased;
                    printf("Fruit Juice stock info: %d\n", juice);}
                else{
                    printf("SORRY! There is not enough product in the STOCK!\n");
                    printf("Fruit Juice stock info: %d\n", juice);
                }
                break;
            case 'M':
            case 'm':
                if(milk + purchased >= 0){
                    milk += purchased;
                    printf("Milk stock info: %d\n", milk);
                }
                else{
                    printf("SORRY! There is not enough product in the STOCK!\n");
                    printf("Milk stock info: %d\n", milk);
                }
                break;
            case 'C':
            case 'c':
                if(coke + purchased >= 0){
                    coke += purchased;
                    printf("Coke stock info: %d\n", coke);
                }
                else{
                    printf("SORRY! There is not enough product in the STOCK!\n");
                    printf("Coke stock info: %d\n", coke);
                }
                break;
            default: printf("Invalid drink\n");
        }

    }

    printf("Stock Information\n*****************\nFruit Juice   %3d\nMilk          %3d\nCoke          %3d\n", juice, milk, coke);

    return 0;
}