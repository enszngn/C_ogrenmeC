#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int randnum, choice = 0, i, p, j;
    char bos = ' ';
    srand(time(NULL));
    
    while(choice != 3){
        randnum = rand() % 7 + 3;
    
        printf("           MENU\n");
        printf("--------------------------\n");
        printf("1 - Right Triangle\n");
        printf("2 - Isosceles Triangle\n");
        printf("3 - Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch(choice){
            case 1:
            printf("Random number is %d\n", randnum);
            for(i = 1; i <= randnum; i++){
                for(p = 1; p <= randnum - i; p++)
                    printf("%c", bos);
                for(p = 1; p <= i; p++)
                    printf("%d", p);
                printf("\n");
            }
                break;
            case 2:
            printf("Random number is %d\n", randnum);
            for(i = 1; i <= randnum; i++){
                for(p = 1; p <= randnum - i; p++)
                    printf("%c", bos);
                for(p = 1; p <= i; p++)
                    printf("%d", p);
                for(p = i - 1; p >= 1; p--)
                    printf("%d",p);
                printf("\n");
            }
        }
    }
    
    return 0;
}