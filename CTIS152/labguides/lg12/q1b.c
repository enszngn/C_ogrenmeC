#include <stdio.h>
#include <stdlib.h>

int main(){

	FILE *inp;
	inp = fopen("nums.bin", "rb");
	if(inp == NULL)
		printf("ERROR\n");
	else{
		int *nums;
		int count = 0;
		fseek(inp, 0, SEEK_END);
		count = ftell(inp) / sizeof(int);
		fseek(inp, 0, SEEK_SET);
		nums = (int *)malloc(sizeof(int) * count);
		fread(nums, sizeof(int), count, inp);
		printf("There are %d numbers in the file\n\n", count);
		for(int i = 0; i < count; i++)
			printf("%d  ", *(nums + i));
		printf("\n");

		fclose(inp);
		free(nums);
	}

	return 0;
}
