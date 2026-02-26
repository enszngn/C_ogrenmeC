#include <stdio.h>
#include <math.h>
//#define _CRT_SECURE_NO_WARNINGS
//i don't get that error on my computer so not needed in my case

int main(){

    char letter;

    printf("Enter a character: ");
    scanf("%c", &letter);

    if(!(letter <= 'z' && 'a' <= letter || letter <= 'Z' && 'A' <= letter))
        printf("It is NOT a letter");
    else
        if(letter <= 'z' && 'a' <= letter){
            printf("The letter '%c' is a lowercase letter\n", letter);
            letter -= 32;
            printf("The UPPERCASE form of the letter is '%c'", letter);
        }
        else{
            printf("The letter '%c' is a UPPERCASE letter\n", letter);
            letter += 32;
            printf("The lowercase form of the letter is '%c'", letter);
        }

    return 0;
}