#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int findFirstOccurance(char sentence[], char string[]);

void deleteAllOccurances(char sentence[], char string[]);

int main() {

	char sentence[300];
	char string[20];
	printf("Enter a sentence: ");
	scanf(" %[^\n]", sentence);
	printf("Enter a word: ");
	scanf("%s", string);
	deleteAllOccurances(sentence, string);
	printf("\nFinal format of the sentence: %s\n", sentence);

	return 0;
}

int findFirstOccurance(char sentence[], char string[]) {
	int sentenceLen = strlen(sentence);
	int stringLen = strlen(string);
	for (int i = 0; i < sentenceLen - stringLen; i++)
		if (strncmp(sentence + i, string, stringLen) == 0)
			return i;
	return -1;
}

void deleteAllOccurances(char sentence[], char string[]) {
	int occuranceIndex;
	int stringLen = strlen(string);
	occuranceIndex = findFirstOccurance(sentence, string);
	while (occuranceIndex != -1) {
		strcpy(sentence + occuranceIndex, sentence + occuranceIndex + stringLen);
		occuranceIndex = findFirstOccurance(sentence, string);
	}
}
