#include <stdio.h>

int main(void){

    char first, second;

    printf("Enter the lowercase of any letter:  ");
    scanf("%c", &first);
    printf("Enter the UPPERCASE of any letter:  ");
    scanf(" %c", &second);

    printf("ASCII code of lowercase form %d\n", first);
    printf("ASCII code of UPPERCASE form%d \n", second);
    printf("Difference between the codes is %d\n", first - second);

    return 0;
}