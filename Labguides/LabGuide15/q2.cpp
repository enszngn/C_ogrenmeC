#include <stdio.h>
#include <math.h>

int readFromFile(FILE *inp, int nums[]);

double findAverage(int nums[], int size);

int main(){

	FILE *inp;
	inp = fopen("numbers.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		int nums[50], sizeOfArray;
		double average;
		sizeOfArray = readFromFile(inp, nums);
		average = findAverage(nums, sizeOfArray);
		printf("There are %d numbers in the file.\n\n", sizeOfArray);
		printf("Average is %.2f\n\n", average);
		printf("Number    Deviation\n");
		printf("******    *********\n");
		for(int k = 0; k < sizeOfArray; k++)
			printf("%6d    %9.2f\n", nums[k], fabs(nums[k] - average));
		fclose(inp);
	}

	return 0;
}

int readFromFile(FILE *inp, int nums[]){
	int status, i = 0;
	status = fscanf(inp, "%d", &nums[i]);
	while(status != EOF){
		i++;
		status = fscanf(inp, "%d", &nums[i]);
	}
	return i;
}

double findAverage(int nums[], int size){
	int sum = 0, i;
	for(i = 0; i < size; i++)
		sum += nums[i];
	return 1.0 * sum / size;
}
