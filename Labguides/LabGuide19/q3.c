#include <stdio.h>

void display(int matrix[][4]);

int check_dia(int matrix[][4]);

int isSymmetric(int matrix[][4]);

int main(){

	FILE *inp;
	inp = fopen("relation.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		int matrix[4][4] = {0};
		int status, i = 0;
		int x, y;
		status = fscanf(inp, "%d %d", &x, &y);
		matrix[x - 1][y - 1] = 1;
		while(status != EOF){
			status = fscanf(inp, "%d %d", &x, &y);
			matrix[x - 1][y - 1] = 1;
		}
		display(matrix);
		if(check_dia(matrix) == 1)
			printf("\nRelation is reflexive\n");
		else
			printf("\nRelation is NOT reflexive\n");
		if(isSymmetric(matrix) == 1)
			printf("Relation is symmetric\n");
		else
			printf("Relation is NOT symmetric\n");
	}
	
	return 0;
}

void display(int matrix[][4]){
	printf("\nMatrix of the relation\n\n");
	for(int i = 0; i < 4; i++){
		for(int p = 0; p < 4; p++)
			printf("  %d", matrix[i][p]);
		printf("\n");
	}
}

int isSymmetric(int matrix[][4]){
	for(int i = 0; i < 4; i++){
		for(int p = 0; p < 4; p++){
			if((i != p) && (matrix[i][p] != matrix[p][i]))
				return 0;
		}
	}
	return 1;
}

int check_dia(int matrix[][4]){
	for(int i = 0; i < 4; i++){
		if(matrix[i][i] != 1)
			return 0;
	}
	return 1;
}
