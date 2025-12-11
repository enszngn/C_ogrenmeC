#include <stdio.h>

void readFromFile(FILE *inp, double matrix[][5]);

void display(double matrix[][5]);

void swapRows(double arr1[], double arr2[]);

int main(){

	FILE *inp;
	inp = fopen("matrix.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		double matrix[6][5];
		int Row, roW;
		readFromFile(inp, matrix);
		printf("The contents of the array is: \n");
		display(matrix);
		do{
		printf("\nEnter two row indices to swap: ");
		scanf("%d %d", &Row, &roW);
		} while ((Row < 1 || Row > 6) || (roW < 1 || roW > 6));
		double row1[5], row2[5];
		for(int i = 0; i < 5; i++){
			row1[i] = matrix[Row - 1][i];
			row2[i] = matrix[roW - 1][i];
		}
		swapRows(row1, row2);
		for(int i = 0; i < 5; i++){
			matrix[Row - 1][i] = row1[i];  
			matrix[roW - 1][i] = row2[i];
		}
		display(matrix);
		fclose(inp);
	}

	return 0;
}

void readFromFile(FILE *inp, double matrix[][5]){
	for(int i = 0; i < 6; i++){
		for(int p = 0; p < 5; p++)
			fscanf(inp, "%lf", &matrix[i][p]);
	}
}

void display(double matrix[][5]){
	for(int i = 0; i < 6; i++){
		for(int p = 0; p < 5; p++)
			printf("%4.1lf   ", matrix[i][p]);
		printf("\n");
	}
}

void swapRows(double arr1[], double arr2[]){
	double temp;
	for(int i = 0; i < 5; i++){
		temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
}
