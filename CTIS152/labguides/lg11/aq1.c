#include <stdio.h>
#include <string.h>

void swap(char *ch1, char *ch2);

void reverseString(char string[], int left, int right);

int main(){

	char string[100];
	printf("Enter a string: ");
	scanf("%[^\n]", string);
	int len = strlen(string);
	reverseString(string, 0, len - 1);
	printf("Reversed string: %s", string);

	return 0;
}

void swap(char *ch1, char *ch2){
	char temp = *ch1;
	*ch1 = *ch2;
	*ch2 = temp;
}

void reverseString(char string[], int left, int right){
	if(left < right){
		swap(string + left, string + right);
		reverseString(string, left + 1, right - 1);
	}
}
