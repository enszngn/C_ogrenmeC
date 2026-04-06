#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void convertToUpper(char string[]);

int main() {

	char word[20];
	char final[250] = {};
	int count = 0;
	printf("Enter a word (or END to stop): ");
	scanf("%s", word);
	while (strcmp(word, "END") != 0) {
		count++;
		convertToUpper(word);
		strcat(final, word);
		strcat(final, " ");
		printf("Enter a word (or END to stop): ");
		scanf("%s", word);
	}
	printf("You have entered %d words\n", count);
	printf("\nThe sentence form in uppercase of the given words:\n");
	printf("%s\n", final);

	return 0;
}

void convertToUpper(char string[]) {
	for (int i = 0; string[i] != '\0'; i++)
		if (string[i] > 'Z')
			string[i] -= ('a' - 'A');
}
