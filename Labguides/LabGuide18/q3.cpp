#include <stdio.h>

void isAbrreviated(char word[], int size, char abbreviated[], int *abbreviatedSize);

int main() {

	FILE *inp;
	inp = fopen("text.txt", "r");
	if (inp == NULL)
		printf("Error\n");
	else {
		FILE *outp;
		outp = fopen("abbreviation.txt", "w");
		char word[20], abbreviated[20];
		int i = 0, status, abbreviatedSize;
		status = fscanf(inp, "%c", &word[i]);
		while (status != EOF) {
			while ((word[i] != ' ' && word[i] != '\n') && status != EOF) {
				i++;
				status = fscanf(inp, "%c", &word[i]);
			}
			isAbrreviated(word, i, abbreviated, &abbreviatedSize);
			for(int p = 0; p < abbreviatedSize; p++)
				fprintf(outp, "%c", abbreviated[p]);
			if (word[i] == '\n')
				fprintf(outp, "\n");
			i = 0;
			status = fscanf(inp, "%c", &word[i]);
		}
		fclose(outp);
		fclose(inp);
	}

	return 0;
}

void isAbrreviated(char word[], int size, char abbreviated[], int *abbreviatedSize) {
	*abbreviatedSize = 0;
	for (int i = 0; i < size; i++)
		if (word[i] >= 'A' && word[i] <= 'Z'){
			abbreviated[*abbreviatedSize] = word[i];
			*abbreviatedSize++;
		}

}
