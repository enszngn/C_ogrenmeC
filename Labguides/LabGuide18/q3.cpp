#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char isAbrreviated(char word[], int size);

int main() {

	FILE *inp;
	inp = fopen("text.txt", "r");
	if (inp == NULL)
		printf("Error\n");
	else {
		FILE *outp;
		outp = fopen("abbreviation.txt", "w");
		char word[20];
		int i = 0, status;
		status = fscanf(inp, "%c", &word[i]);
		while (status != EOF) {
			while ((word[i] != ' ' && word[i] != '\n') && status != EOF) {
				i++;
				status = fscanf(inp, "%c", &word[i]);
			}
			fprintf(outp, "%c", isAbrreviated(word, i));
			if (word[i] == '\n')
				fprintf(outp, "\n");
			i = 0;
			status = fscanf(inp, "%c", &word[i]);
		}
	}

	return 0;
}

char isAbrreviated(char word[], int size) {
	for (int i = 0; i < size; i++)
		if (word[i] >= 'A' && word[i] <= 'Z')
			return word[i];
}
