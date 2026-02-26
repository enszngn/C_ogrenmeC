#include <stdio.h>

int main(){

	FILE *inp;
	inp = fopen("gamers.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		int players[5][5];
		int points[5] = {0};
		for(int i = 0; i < 5; i++){
			for(int p = 0; p < 5; p++){
				fscanf(inp, "%d", &players[p][i]);
				points[i] += players[p][i];
				if(p == 2 && players[p][i] >= 8)
					points[i] += 5;
			}
		}
		for(int i = 0; i < 5; i++)
			printf("%d. player score: %d\n", i + 1, points[i]);
		fclose(inp);
	}
	
	return 0;
}
