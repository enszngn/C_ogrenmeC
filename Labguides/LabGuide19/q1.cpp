#include <stdio.h>

int readFromFile(FILE *inp, int arr1[], int arr2[]);

int isRelPrime(int num1, int num2);

int findRelPrimes(int arr1[], int arr2[], int size, int lastArray[]);

int main() {

	printf("%d", isRelPrime(7, 14));
	FILE *inp;
	inp = fopen("nums1.txt", "r");
	if (inp == NULL)
		printf("ERROR");
	else {
		int nums1[6], nums2[6], lastArray[100], numOfRelativelyPrimes;;
		int size = readFromFile(inp, nums1, nums2);
		numOfRelativelyPrimes = findRelPrimes(nums1, nums2, size, lastArray);
		if (numOfRelativelyPrimes == 0)
			printf("There are no relatively primes in the arrays!\n");
		else {
			printf("there are %d relatively primes in the arrays\n\n", numOfRelativelyPrimes);
			for (int i = 0; i < numOfRelativelyPrimes; i += 2) {
				printf("   %2d   %2d\n", nums1[lastArray[i]], nums2[lastArray[i + 1]]);
			}
		}
		fclose(inp);
	}

	return 0;
}

int readFromFile(FILE *inp, int arr1[], int arr2[]) {
	int status, i = 0;
	status = fscanf(inp, "%d %d", &arr1[i], &arr2[i]);
	while (status != EOF) {
		i++;
		status = fscanf(inp, "%d %d", &arr1[i], &arr2[i]);
	}
	return i;
}

int isRelPrime(int num1, int num2) {
	int max;
	if (num1 > num2)
		max = num1;
	else
		max = num2;
	for (int i = 2; i <= max / 2; i++) {
		if ((num1 % i == 0) && (num2 % i == 0))
			return 0;
	}
	return 1;
}

int findRelPrimes(int arr1[], int arr2[], int size, int lastArray[]) {
	int numOfRelativelyPrimes = 0;
	int a = 0;
	for (int i = 0; i < size; i++) {
		for (int p = 0; p < size; p++) {
			if (isRelPrime(arr1[i], arr2[p])) {
				lastArray[a] = i;
				a++;
				lastArray[a] = p;
				a++;
				numOfRelativelyPrimes++;
			}
		}
	}
	return numOfRelativelyPrimes;
}
