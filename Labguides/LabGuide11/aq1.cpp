#include <stdio.h>

void withdrawn(int amountWithdrawn, int *money200, int *money100, int *money50, int *money20, int *money10);

int main(){

	int amountWithdrawn;
	int money200, money100, money50, money20, money10;

	printf("Enter the amount to be withdrawn: ");
	scanf("%d", &amountWithdrawn);
	while(amountWithdrawn % 10 != 0){
		printf("Money amount should be multiple of 10 TL.\n\n");
		printf("Enter the amount to be withdrawn: ");
		scanf("%d", &amountWithdrawn);
	}

	withdrawn(amountWithdrawn, &money200, &money100, &money50, &money20, &money10);	

	printf("\nFor %d TL, the ATM will give the following banknotes:\n", amountWithdrawn);
	printf("%d unit(s) of 200TL\n", money200);
	printf("%d unit(s) of 100TL\n", money100);
	printf("%d unit(s) of 50TL\n", money50);
	printf("%d unit(s) of 20TL\n", money20);
	printf("%d unit(s) of 10TL\n", money10);

	return 0;
}


void withdrawn(int amountWithdrawn, int *money200, int *money100, int *money50, int *money20, int *money10){
	
	*money200 = amountWithdrawn / 200;
	amountWithdrawn %= 200;
	*money100 = amountWithdrawn / 100;
	amountWithdrawn %= 100;
	*money50 = amountWithdrawn / 50;
	amountWithdrawn %= 50;
	*money20 = amountWithdrawn / 20;
	amountWithdrawn %= 20;
	*money10 = amountWithdrawn / 10;

}
