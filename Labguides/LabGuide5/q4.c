#include <stdio.h>
#include <math.h>
//#define _CRT_SECURE_NO_WARNINGS
//i don't get that error on my computer so not needed in my case

int main(){

    double carPrice, Discount, insurancePrice, noCrashDisc = 0;
    char gender, accident;
    int licenceYear;

    printf("Enter the information of the driver;\nCar price: ");
    scanf("%lf", &carPrice);
    printf("Gender (m/f): ");
    scanf(" %c", &gender);
    printf("Years: ");
    scanf(" %d", &licenceYear);
    printf("Do you have any accident (Y/y-N/n): ");
    scanf(" %c", &accident);

    insurancePrice = 0.1 * carPrice;

    if(gender == 'm')
        if(licenceYear <= 20)
        Discount += 0.04;
        else
        Discount += 0.06;
    else
        if(licenceYear <= 10)
        Discount += 0.05;
        else
        Discount += 0.07;
    if(accident == 'n' || accident == 'N')
        noCrashDisc = 0.1;

    insurancePrice -= insurancePrice * Discount;
    insurancePrice -= insurancePrice * noCrashDisc;
    printf("The cost of the insurance is: $ %.1f", insurancePrice);

    return 0;
}