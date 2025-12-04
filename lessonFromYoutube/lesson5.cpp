#include <stdio.h>

int main(){

    char isim[50];
    int yas;
    char soyisim[50];
    printf("What is your name and surname:  ");
    scanf("%s %s", &isim, &soyisim);
    printf("How old are you:  ");
    scanf(" %d", &yas);
    printf("You are the youngest person ever %s %s!\n", isim, soyisim);
    printf("Write a sentence: ");
    getchar();
    fgets(isim, sizeof(isim), stdin);
    printf("that sentence is horrible!");
    

    return 0;
}