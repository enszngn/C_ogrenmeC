#include <stdio.h>
#include <stdlib.h>

void display(int matrix[][5], int rowNumber);

int sumOfRow(int matrix[][5], int row);

int sumOfMinor(int matrix[][5], int rowNumber);

int main(){

	FILE *inp;
	inp = fopen("input1.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		int numbers[30][5];
		int status = 1, i = 0;
		int r;
		int sumRow, sumMinor;
		for(r = 0; status != EOF; r++){
			for(int c = 0; c < 5; c++){
				status = fscanf(inp, "%d", &numbers[r][c]);
			}
		}
		display(numbers, r - 1);
		int wantedRow;
		printf("What row you want to add: ");
		scanf("%d", &wantedRow);
		sumRow = sumOfRow(numbers, wantedRow);
		sumMinor = sumOfMinor(numbers, r - 1);
		printf("\n%d  %d\n", sumMinor, sumRow);
	}

	return 0;
}

void display(int matrix[][5], int rowNumber){
	for(int r = 0; r < rowNumber; r++){
		for(int c = 0; c < 5; c++)
			printf("%2d  ", matrix[r][c]);
		printf("\n");
	}
}

int sumOfRow(int matrix[][5], int row){
	int sum = 0;
	for(int c = 0; c < 5; c++){
		sum += matrix[row][c];
	}
	return sum;
}

int sumOfMinor(int matrix[][5], int rowNumber){
	int sum = 0;
	for(int r = 0; r < rowNumber; r++){
		sum += matrix[r][4 - r];
	}
	return sum;
}
