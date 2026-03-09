#include <stdio.h>

int read(FILE *inp, int numbers[]);

int binary_search(int numbers[], int number_amount, int searched_number, int *comparison_count);

int main(){

	FILE *inp;
	inp = fopen("steps.txt", "r");
	if(inp == NULL)
		printf("ERROR\n");
	else{
		int steps[20];
		int number_amount = read(inp, steps) - 1;
		int comparison_count = 1;
		int searched_value;
		printf("Enter a value to find: ");
		scanf("%d", &searched_value);
		int searched_index = binary_search(steps, number_amount, searched_value, &comparison_count);
		if(searched_index != -1)
			printf("%d found at %d. line\n", steps[searched_index], searched_index + 1);
		else
			printf("The number is not found at steps.txt\n");
		printf("%d comparisons.\n", comparison_count);
	}

	return 0;
}

int binary_search(int numbers[], int number_amount, int searched_number, int *comparison_count){
	int top = 0;
	int bottom = number_amount;
	int middle;
	while(top < bottom){
		middle = (bottom + top) / 2;
		if(searched_number == numbers[middle])
			return middle;
		else if(numbers[middle] > searched_number)
			bottom = middle - 1;
		else
			top = middle + 1;
		(*comparison_count)++;
	}
	return -1;
}

int read(FILE *inp, int numbers[]){
	int number_amount = 0;
	int status = 1;
	do{
		status = fscanf(inp, "%d", &numbers[number_amount]);
		number_amount++;
	} while (status != EOF);
	// because after EOF it still increments number_amount, the value of it is 1 higher then it is supposed to be.
	// i am leaving it because of easier for loops.
	return number_amount;
}
