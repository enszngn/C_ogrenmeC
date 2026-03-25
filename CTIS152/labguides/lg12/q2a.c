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
		int *nums;
		nums = (int *)malloc(sizeof(int) * 250);
		int amount;
		printf("Please Enter the number of items to be read: ");
		scanf("%d", &amount);
		for(int i = 0; i < amount; i++){
			fread(nums + i, sizeof(int), 1, inp);
			printf("%d. %d\n", i + 1, *(nums + i));
		}
		fclose(inp);
		free(nums);
	}

	return 0;
}

void createBinaryFile(FILE *outp){
	outp = fopen("numbers.bin", "wb");
	srand(time(NULL));
	int num;
	for(int i = 0; i < 250; i++){
		num = rand() % 5000 + 1;
		fwrite(&num, sizeof(int), 1, outp);
	}
	fclose(outp);
}
