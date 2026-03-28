#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int findAllOccurances(char sentence[], char string[], int allOccurances[]);

int main() {

	char sentence[200];
	char string[20];
	int allOccurances[10];
	int count;
	printf("Enter a sentence: ");
	scanf("%[^\n]", sentence);
	printf("\nEnter a string: ");
	scanf("%s", string);
    count = findAllOccurances(sentence, string, allOccurances);
	if (count == 0)
		printf("The sentence does NOT contain the string <%s>\n", string);
	else {
		printf("All occurances of the str <%s>:", string);
		for (int i = 0; i < count; i++)
			printf("  %d", allOccurances[i]);
		printf("\n");
	}

	return 0;
}

int findAllOccurances(char sentence[], char string[], int allOccurances[]) {
	int count = 0;
	int stringLen = strlen(string);
	int sentLen = strlen(sentence);
	for (int i = 0; i < sentLen - stringLen; i++)
		if (strncmp(sentence + i, string, stringLen) == 0) {
			allOccurances[count] = i;
			count++;
		}
	return count;
}
