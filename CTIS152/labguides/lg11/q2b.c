#include <stdio.h>
#include <string.h>

int findString(char string[], char word[], int wordlen){
	if(*(string + wordlen) == '\0')
		return 0;
	else if(strncmp(string, word, wordlen) == 0)
		return 1 + findString(string + 1, word, wordlen);
	return findString(string + 1, word, wordlen);
}

int main(){

	char string[100];
	printf("Enter a sentence: ");
	scanf("%[^\n]", string);
	printf("Enter a string to search in the sentence: ");
	char word[20];
	scanf("%s", word);
	int count = findString(string, word, strlen(word));
	printf("%d\n", count);

	return 0;
}
