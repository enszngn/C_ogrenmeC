#include <stdio.h>

void printNumbers(int n){
	if(n == 1)
		printf("%d ", n);
	else{
		printNumbers(n - 1);
		printf("%d ", n);
	}
}

void printLines(int n){
	printNumbers(n);
	if(n != 1){
		printf("\n");
		printLines(n - 1);
	}
}

int main(){

	int lines;
	printf("Enter the number of lines: ");
	scanf("%d", &lines);
	printLines(lines);

	return 0;
}
