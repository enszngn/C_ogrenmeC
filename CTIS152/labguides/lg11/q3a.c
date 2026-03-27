#include <stdio.h>

void printNumbers(int n){
	if(n != 1)
		printNumbers(n - 1);
	printf("%d ", n);
}

void printLines(int n){
	if(n != 1)
		printLines(n - 1);
	printNumbers(n);
	printf("\n");
}

int main(){

	int n;
	printf("Enter the number of lines: ");
	scanf("%d", &n);
	printLines(n);

	return 0;
}
