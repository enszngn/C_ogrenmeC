#include <stdio.h>

int main(){

    int age;
    char disability, error;
    double tPrice = 1000,bWeight;

    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Disability? (y/n): ");
    scanf(" %c", &disability);

    switch(disability){
    case 'y': tPrice *= 0.6;
            break;
    case 'n': if(age > 65)
        tPrice *= 0.85;
    else if(age <= 12)
            tPrice *= 0.67;
            break;
    default: error = 'y';
}

    if(error == 'y')
        printf("Invalid answer!!");
    else{
        printf("Ticket payment: %.2f\n\n", tPrice);
        printf("Enter baggage weight: ");
        scanf(" %lf", &bWeight);
        if(bWeight > 15)
            printf("Your baggage weight exceeds the limit with %.2f kg, please pay %.2f TL\n", bWeight - 15, (bWeight - 15) * 190);
        else
            printf("Your baggage weight is within the allowed limit.\n");
    }

    return 0;
}