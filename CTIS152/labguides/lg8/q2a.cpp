#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int findFirst(char sentence[], char searched[]);

void deleteFirst(char sentence[], char searched[], int firstIndex);

int main() {

	char sentence[100];
	printf("Enter a sentence: ");
	scanf("%[^\n]", sentence);
	char searched[20];
	printf("Enter a string to search: ");
	scanf("%s", searched);
	int firstIndex = findFirst(sentence, searched);
	if (firstIndex == -1)
		printf("\nThe sentence does not contain the string <%s>\n", searched);
	else {
		printf("The new form of the sentence after deletion:\n");
		deleteFirst(sentence, searched, firstIndex);
		printf("%s\n", sentence);
	}

	return 0;
}

int findFirst(char sentence[], char searched[]) {
	int searchedLen = strlen(searched);
	int sentLen = strlen(sentence);
	for (int i = 0; i < sentLen - searchedLen; i++) {
		if (strncmp(sentence + i, searched, searchedLen) == 0)
			return i;
	}
	return -1;
}

void deleteFirst(char sentence[], char searched[], int firstIndex) {
	int searchedLen = strlen(searched);
	strcpy(sentence + firstIndex, sentence + firstIndex + searchedLen);
}
