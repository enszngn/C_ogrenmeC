#include <stdio.h>
#include <math.h>
//#define _CRT_SECURE_NO_WARNINGS
//i don't get that error on my computer so not needed in my case

int main(){

    char companyType;
    double sales, income;

    printf("Enter the company type (C/c) Catering (M/m) Medical: ");
    scanf("%c", &companyType);
    printf("Enter the sales of the company: ");
    scanf(" %lf", &sales);

    if(companyType == 'c' || companyType == 'C'){
        if(sales >= 40000)
            income = 375 + sales * 0.16;
        else
            income = 350 + sales * 0.14;
    }
    else{
        if(sales >= 25000)
            income = 325 + sales * 0.12;
        else
            income = 300 + sales * 0.09;
    }

    printf("\nIncome of the company: %.2f TL", income);

    return 0;
}