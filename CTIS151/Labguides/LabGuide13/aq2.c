#include <stdio.h>

int main(){
	char lastLetter = 'a', totalLetter[15];
	int playerNumber = 1, i = 0;
	printf("Player-%d, enter a word: ", playerNumber);	
	scanf("%c", &totalLetter[i]);
	while(totalLetter[i] != '.'){
		i++;
		scanf("%c", &totalLetter[i]);
	}
	playerNumber++;
	while(totalLetter[0] == lastLetter){
		lastLetter = totalLetter[i - 1];
		printf("Player-%d, enter a word: ", playerNumber);	
		i = 0;
		scanf(" %c", &totalLetter[i]);
		while(totalLetter[i] != '.'){
			i++;
			scanf("%c", &totalLetter[i]);
		}
		if(playerNumber == 1)
			playerNumber = 2;
		else
			playerNumber = 1;
	}
	printf("\n");
	for(int k = 0; k < i; k++)
		printf("%c", totalLetter[k]);
	printf(" does not start with %c!\n", lastLetter);
	printf("Game over: Player-%d wins.\n", playerNumber);
	return 0;
}
