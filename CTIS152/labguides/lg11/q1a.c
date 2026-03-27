#include <stdio.h>

void printDigits(int num){
	if(num < 10)
		printf("\t%d", num);
	else{
		printf("\t%d", num % 10);
		printDigits(num / 10);
	}
}

int main(){

	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	printf("Digits of the number %d are: \n", num);
	printDigits(num);

	return 0;
}
