#include <stdio.h>
#include <stdlib.h>

void swap(int *num1, int *num2);

void bubble_sort(int *visitors, int number_of_visitors);

int main(){

	FILE *inp;
	inp = fopen("visitors.txt", "r");
	if(inp == NULL)
		printf("ERROR\n");
	else{
		int *visitors;
		visitors = (int *)malloc(sizeof(int) * 15);
		int status = 1, i;
		for(i = 0; status != EOF; i++){
			status = fscanf(inp, "%d", visitors + i);
		} //last value is garbage
		bubble_sort(visitors, i - 1);
		printf("\n#of visitors\n");
		printf("************\n");
		for(int p = 0; p < i - 1; p++)
			printf("    %d\n", *(visitors + p));


		fclose(inp);
		free(visitors);
	}

	return 0;
}

void swap(int *num1, int *num2){
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void bubble_sort(int *visitors, int number_of_visitors){
	for(int p = 1; p < number_of_visitors; p++){
		for(int i = 0; i < number_of_visitors - p; i++){
			if(*(visitors + i) > *(visitors + i + 1))
				swap((visitors + i), (visitors + i + 1));
		}
	}
}
