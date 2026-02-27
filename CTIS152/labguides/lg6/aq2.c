#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int menu();

void fill_array(int **array, int n);

void display_array(int **array, int n);

int search_value(int **array, int n, int searched_number);

int main(){

	int n;
	printf("Enter enter the dimension: ");
	scanf("%d", &n);
	int **array;
	array = (int **)malloc(sizeof(int *) * n);
	for(int i = 0; i < n; i++){
		*(array + i) = (int *)malloc(sizeof(int) * n);
	}
	int choice = menu();
	int value;
	while(choice != 4){
		switch(choice){
			case 1: printf("Array filled with random numbers (20-199)\n\n");
				fill_array(array, n);
				break;
			case 2: printf("\n\n");
				display_array(array, n);
				break;
			case 3: printf("Enter the value to search: ");
				scanf("%d", &value);
				printf("The number of occurances: %d\n\n", search_value(array, n, value));
		}
		choice = menu();
	}

	free(array);

	return 0;
}

int menu(){
	printf("    MENU\n");
	printf("1. Fill the array with random numbers\n");
	printf("2. Display array elements\n");
	printf("3. Display #of occurrances of a value\n");
	printf("4. Exit\n");
	printf("\nEnter your choice: ");
	int choice;
	scanf("%d", &choice);
	return choice;
}


void fill_array(int **array, int n){
	srand(time(NULL));
	for(int r = 0; r < n; r++){
		for(int c = 0; c < n; c++)
			*(*(array + r) + c) = rand() % 180 + 20;
	}
}


void display_array(int **array, int n){
	for(int r = 0; r < n; r++){
		for(int c = 0; c < n; c++)
			printf("%3d  ", *(*(array + r) + c));
		printf("\n");
	}
}

int search_value(int **array, int n, int searched_number){
	int count = 0;
	for(int r = 0; r < n; r++){
		for(int c = 0; c < n; c++)
			if(*(*(array + r) + c) == searched_number)
				count++;
	}
	return count;
}
