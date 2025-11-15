#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    char sym;
    int sideLength;
    printf("Enter a character(! to stop) : ");
    scanf(" %c", &sym);
    while(sym != '!'){
        do{
            printf("Enter the side lenght: ");
            scanf("%d", &sideLength);
        } while(sideLength < 4 || sideLength > 10);

        for(int i = 1; i <= sideLength; i++){
            for(int p = 1; p <= sideLength - i; p++)
                printf("%c", ' ');
            for(int m = 1; m <= 2 * i - 1; m++)
                printf("%c", sym);
            printf("\n");
        }
        for(int i = 1; i <= sideLength - 1; i++){
            for(int p = 1; p <= i; p++)
                printf("%c", ' ');
            for(int m = 1; m <= 2 * sideLength - 2 * i - 1; m++)
                printf("%c", sym);
            printf("\n");
        }

        printf("Enter a character(! to stop): ");
        scanf(" %c", &sym);
    }

    return 0;
}
