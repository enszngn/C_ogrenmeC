#include <stdio.h>
#define currentYear 2025

int main(){

    int eYear;
    int lSalary;
    int comp;

    printf("Enter your entrance year:  \n");
    scanf("%d", &eYear);
    printf("Enter year last salary:  \n");
    scanf("%d", &lSalary);

    comp = (currentYear - eYear) * lSalary;

    printf("Your compensation is %dTL.\n", comp);

    return 0;
}