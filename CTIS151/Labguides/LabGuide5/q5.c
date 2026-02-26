#include <stdio.h>
#include <math.h>
//#define _CRT_SECURE_NO_WARNINGS
//i don't get that error on my computer so not needed in my case

int main(){

    int hours;
    double salary = 10000;

    printf("Enter total hours worked by the employee: ");
    scanf("%d", &hours);

    if(hours > 40 && hours <= 55)
        salary += (hours - 40) * 385;
    if(hours > 55)
        salary += (15 * 385 + (hours - 55) * 500);

    printf("Total salary: %.2f TL", salary);

    return 0;
}