#include <stdio.h>

void findRowSums(int matrix[][10], int size, int rowSums[]);

int findColSums(int matrix[][10], int size, int columnSums[]);

void display(int arr[], int size);

void rowDominants(int rowSums[], int maxColumnSum, int size);

int main(){

	int n;
	int rowSums[10], columnSums[10];
	int maxColumnSum;
	printf("Enter n: ");
	scanf("%d", &n);
	while(n < 1 || n > 10){
		printf("Invalid value for n.\n");
		printf("\nEnter n: ");
		scanf("%d", &n);
	}
	int matrix[10][10];
	printf("Enter the elements of the %dx%d matrix: ", n, n);
	for(int i = 0; i < n; i++){
		for(int p = 0; p < n; p++)
			scanf("%d", &matrix[i][p]);
	}
	findRowSums(matrix, n, rowSums);
	maxColumnSum = findColSums(matrix, n, columnSums);
	printf("Row sums    : [  ");
	display(rowSums, n);
	printf("]\n");
	printf("Column sums : [  ");
	display(columnSums, n);
	printf("]\n\n");
	rowDominants(rowSums, maxColumnSum, n);

	return 0;
}

void findRowSums(int matrix[][10], int size, int rowSums[]){
	int sum = 0;
	for(int i = 0; i < size; i++){
		for(int p = 0; p < size; p++){
			sum += matrix[i][p];
		}
		rowSums[i] = sum;
		sum = 0;
	}
}

int findColSums(int matrix[][10], int size, int columnSums[]){
	int sum = 0, max = 0;
	for(int i = 0; i < size; i++){
		for(int p = 0; p < size; p++){
			sum += matrix[p][i];
		}
		if(sum > max)
			max = sum;
		columnSums[i] = sum;
		sum = 0;
	}
	return max;
}

void display(int arr[], int size){
	for(int i = 0; i < size; i++){
		printf("%2d   ", arr[i]);
	}
}

void rowDominants(int rowSums[], int maxColumnSum, int size){
	for(int i = 0; i < size; i++){
		if(rowSums[i] > maxColumnSum){
		printf("Row %d is row-dominant (sum = %d)\n", i + 1, rowSums[i]);
		}
	}
}
