#include <stdio.h>

double factorial(int num);

double permutation(int num, int num2);

double combination(int num, int num2);

int main(){

	int num, num2;

	do{
		printf("Enter n value: ");
		scanf("%d", &num);
	} while(num <= 0);

	printf("\n");

	do{
		printf("Enter k value: ");
		scanf("%d", &num2);
	} while(num2 < 0 || num < num2);

	printf("P(%d, %d) = %.0f\n", num, num2, permutation(num, num2));
	printf("C(%d, %d) = %.0f\n", num, num2, combination(num, num2));

	return 0;
}

double factorial(int num){
	double factor = 1;
	for(int i = 1; i <= num; i++)
		factor *= i;
	return factor * 1.0;
}

double permutation(int num, int num2){
	double perm;
	perm = factorial(num) / factorial(num - num2);
	return perm;
}

double combination(int num, int num2){
	double comb;
	comb = permutation(num, num2) / factorial(num2);
	return comb;
}


