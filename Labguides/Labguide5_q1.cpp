#include <stdio.h>
#include <math.h>
//#define _CRT_SECURE_NO_WARNINGS
//i don't get that error on my computer so not needed in my case

int main(){

    double fee = 500, discount1 = 0.1, discount2 = 0.05, tDiscount = 0;
    char ifStudent;
    int birthday;

    printf("Base membership fee: %.2f TL\n", fee);
    printf("Are you a student (y/n): ");
    scanf("%c", &ifStudent);
    printf("Enter the day of birth: ");
    scanf(" %d", &birthday);

    if(ifStudent == 'y'){
        tDiscount += discount1;
        printf("\n%.2f TL Student discount applied! New payment amount: %.2f TL\n",fee * discount1, fee - fee * tDiscount);
    }

    if(birthday == 1 || birthday == 10 || birthday == 20){
        tDiscount += discount2;
        printf("\n%.2f TL birthday discount applied! New payment amount: %.2f TL\n\n",fee * discount2, fee - fee * tDiscount);
    }

    printf("Total discount applied: %.2f\n", fee * tDiscount);
    fee -= fee * tDiscount;
    printf("Final payment: %.2fTL", fee);

    return 0;
}