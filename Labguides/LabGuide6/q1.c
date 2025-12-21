#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int num, seed, guess;

    printf("Enter a seed number: ");
    scanf("%d", &seed);

    srand(seed);

    num = rand()%10 + 1;

    printf("Please guess, the randomly generated number (1-10): ");
    scanf(" %d", &guess);

    if(guess == num)
        printf("Congratulations! You have guessed the number correctly :)\n");
    else
        printf("You couldn't guess correctly! The number was %d, see you again next time.\n", num);

    return 0;
}