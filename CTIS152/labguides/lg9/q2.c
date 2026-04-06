#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int findAllOccurances(char sentence[], char string[], int allOccurances[]);

int main() {

	char sentence[100];
	char string[20];
	int allOccurances[5];
	printf("Enter a sentence: ");
	scanf("%[^\n]", sentence);
	printf("\nEnter a word: ");
	scanf("%s", string);
	int count = findAllOccurances(sentence, string, allOccurances);
	if (count == 0)
		printf("The word <%s> does not exist in sentence\n", string);
	else {
		printf("All occurances of the word <%s>:\n", string);
		for (int i = 0; i < count; i++)
			printf(" %d", allOccurances[i]);
		printf("\n");
	}

	return 0;
}

int findAllOccurances(char sentence[], char string[], int allOccurances[]) {
	int sentLen = strlen(sentence);
	int stringLen = strlen(string);
	int count = 0;
	for (int i = 0; i < sentLen - stringLen; i++)
		if (strncmp(sentence + i, string, stringLen) == 0) {
			allOccurances[count] = i;
			count++;
		}
	return count;
}
