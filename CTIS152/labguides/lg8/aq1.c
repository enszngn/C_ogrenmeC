#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int findLastOccurance(char sentence[], char string[]);

int main() {

	char sentence[100];
	char string[20];
	printf("Enter a sentence: ");
	scanf("%[^\n]", sentence);
	printf("Enter a key string: ");
	scanf("%s", string);
	int lastOccurance = findLastOccurance(sentence, string);
	printf("%d", lastOccurance);
	if (lastOccurance == 0)
		printf("Result: That's an empty string, sorry.\n");
	else {
		printf("Result: ");
		for (int i = 0; i < lastOccurance; i++)
			printf("%c", sentence[i]);
	}

	return 0;
}

int findLastOccurance(char sentence[], char string[]) {
	int sentLen = strlen(sentence);
	int strLen = strlen(string);
	for (int i = sentLen - strLen; i >= 0; i--)
		if (strncmp(sentence + i, string, strLen) == 0)
			return i;
	return -1;
}
