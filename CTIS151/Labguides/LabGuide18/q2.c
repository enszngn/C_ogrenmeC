#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void displayWord(char word1[]);

int isEqual(char word1[], int size1, char word2[], int size2);

int main() {

	char word1[20], word2[20], size1 = 0, size2 = 0;;
	printf("Enter first word: ");
	scanf("%c", &word1[size1]);
	while (word1[size1] != '\n') {
		size1++;
		scanf("%c", &word1[size1]);
	}
	printf("Enter second word: ");
	scanf("%c", &word2[size2]);
	while (word2[size2] != '\n') {
		size2++;
		scanf("%c", &word2[size2]);
	}
	int isSame = isEqual(word1, size1, word2, size2);
	printf("\n");
	if (isSame != -2) {
		displayWord(word1);
		printf(" and ");
		displayWord(word2);
		printf(" are NOT the same words.\n");
		printf("First different character in between was after the character #%d.\n", isSame);
	}
	else {
		displayWord(word1);
		printf(" and ");
		displayWord(word2);
		printf(" are the same words.\n");
	}

	return 0;
}


void displayWord(char word[]) {
	int i = 0;
	printf("%c", word[i++]);
	while (word[i] != '\n') {
		printf("%c", word[i]);
		i++;
	}
}

int isEqual(char word1[], int size1, char word2[], int size2) {
	if (size1 < size2)
		size1 = size2;
	for (int i = 0; i < size1; i++)
		if (word1[i] != word2[i])
			return i;
	return -2;
}
