#include <stdio.h>

int main(){

	int matrix[4][4] = {0};
	for(int i = 0; i < 4; i++)
		matrix[i][i] = 1;
	printf("MAJOR DIAGONAL\n");
	printf("**************\n  ");
	for(int i = 0; i < 4; i++){
		for(int p = 0; p < 4; p++)
			printf("%d  ", matrix[i][p]);
		printf("\n  ");
	}
	for(int i = 0; i < 4; i++)
		matrix[3 - i][i] = 1;
	printf("\n\nMAJOR AND MINOR DIAGONAL\n");
	printf("************************\n  ");
	for(int i = 0; i < 4; i++){
		for(int p = 0; p < 4; p++)
			printf("%d  ", matrix[i][p]);
		printf("\n  ");
	}

	return 0;
}
