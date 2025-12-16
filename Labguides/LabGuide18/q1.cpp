#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 9

void fillpattern(int arr[][SIZE], int dimension);

void display(int arr[][SIZE]);

int main(){

	srand(time(NULL));
	int dimension;
	do{
		dimension = rand() % 9 + 1;
		printf("Generated random dimension : %d\n", dimension);
	} while (dimension % 2 == 0);
	printf("\n");
	int arr[SIZE][SIZE] = {0};
	fillpattern(arr, dimension);
	display(arr);

	return 0;
}

void fillpattern(int arr[][SIZE], int dimension){
	for(int i = 0; i < dimension / 2 + 1; i++){
		for(int p = dimension / 2 - i; p < dimension / 2 + i + 1; p++)
			arr[i][p] = 1;
	}
}

void display(int arr[][SIZE]){
	for(int i = 0; i < SIZE; i++){
		for(int p = 0; p < SIZE; p++)
			printf("%d  ", arr[i][p]); 
		printf("\n");
	}
}
