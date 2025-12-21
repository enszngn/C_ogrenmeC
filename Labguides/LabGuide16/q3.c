#include <stdio.h>

int main(){

	FILE *inp;
	inp = fopen("words.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		char ch, status, words[6][6];
		for(int i = 0; i < 6; i++){
			for(int p = 0; p < 6; p++)
				status = fscanf(inp, "%c ", &words[i][p]);
		}
		int choice;
		printf("Which word you want to display? ");
		scanf("%d", &choice);
		printf("\nThe word -> ");
		for(int i = 0; i < 6; i++)
			printf("%c", words[i][choice - 1]);
		fclose(inp);
	}

	return 0;
}
