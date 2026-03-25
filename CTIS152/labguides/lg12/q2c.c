#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createBinaryFile(FILE *outp);

int main(){

	FILE *outp;
	createBinaryFile(outp);
	FILE *inp;
	inp = fopen("numbers.bin", "rb");
	if(inp == NULL)
		printf("ERROR\n");
	else{
		int num;
		int order;
		printf("Please enter the order of items to be read: ");
		scanf("%d", &order);
		while(order > 250 || order <= 0){
			printf("Please enter the order of item to be read: ");
			scanf("%d", &order);
		}
		fseek(inp, order * sizeof(int), SEEK_SET);
		fread(&num, sizeof(int), 1, inp);
		printf("%d. %d", order, num);
		fclose(inp);
	}

	return 0;
}

void createBinaryFile(FILE *outp){
	outp = fopen("numbers.bin", "wb");
	srand(time(NULL));
	int num;
	int *numbers;
	numbers = (int *)malloc(sizeof(int) * 250);
	for(int i = 0; i < 250; i++){
		num = rand() % 5000 + 1;
		*(numbers + i) = num;
	}
	fwrite(numbers, sizeof(int), 250, outp);
	free(numbers);
	fclose(outp);
}
