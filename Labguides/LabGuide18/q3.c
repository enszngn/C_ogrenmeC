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
		char word[20], abbreviated[100];
		int i = 0, status, abbreviatedSize = 0;
		status = fscanf(inp, "%c", &word[i]);
		while (status != EOF) {
			while ((word[i] != ' ' && word[i] != '\n') && status != EOF) {
				i++;
				status = fscanf(inp, "%c", &word[i]);
			}
			isAbrreviated(word, i + 1, abbreviated, &abbreviatedSize);
			i = 0;
			status = fscanf(inp, "%c", &word[i]);
		}
		for(int p = 0; p < abbreviatedSize - 1; p++){
			fprintf(outp, "%c", abbreviated[p]);
		}
		fclose(outp);
		fclose(inp);
	}

	return 0;
}

void isAbrreviated(char word[], int size, char abbreviated[], int *abbreviatedSize) {
	for (int i = 0; i < size; i++){
		if((word[i] >= 'A' && word[i] <= 'Z') || word[i] == '\n'){
			abbreviated[*abbreviatedSize] = word[i];
			(*abbreviatedSize)++;
		}
	}

}