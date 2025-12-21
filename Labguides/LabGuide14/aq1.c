#include <stdio.h>
#define SIZE 20

int main(){

	FILE *inp;
	inp = fopen("numbers.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		int nums[SIZE], status, i = 0, index;
		status = fscanf(inp, "%d", &nums[i]);
		while(status != EOF){
			i++;
			status = fscanf(inp, "%d", &nums[i]);
		}
		printf("Array content BEFORE Delete operation:\n");
		printf("There are %d numbers in the array!\n\n", i);
		for(int p = 0; p < i; p++)
			printf("[%2d]  %2d\n", p, nums[p]);
		do{
			printf("Enter the index of element to be deleted (0-11): ");
			scanf("%d", &index);
			printf("The value %d which is on the index %d will be deleted\n\n", nums[index], index);
			printf("Array content AFTER delete operation\n");
			for(int p = index; p < i; p++){
				nums[p] = nums[p + 1];
			}
			i--;
			printf("There are %d numbers in the array!\n\n", i);
			for(int p = 0; p < i; p++)
				printf("[%2d]  %2d\n", p, nums[p]);
		} while(index >= 0 && index <= i);
	}

	return 0;
}
