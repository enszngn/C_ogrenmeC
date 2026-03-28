#include <stdio.h>
#include <string.h>

int findFirst(char sentence[], char string[]);

void replaceFirstOccurance(char sentence[], char string[], char replace[], int firstOccurance);

int main(){

	char sentence[100];
	printf("Enter a sentence: ");
	scanf("%[^\n]", sentence);
	char string[20];
	printf("Enter a string to search: ");
	scanf("%s", string);
	int first = findFirst(sentence, string);
	if(first == -1)
		printf("The sentence does NOT contain the string <%s>\n", string);
	else{
		char replace[20];
		printf("Enter a string to replace: ");
		scanf("%s", replace);
		printf("\nNew form of the sentence:\n");
		replaceFirstOccurance(sentence, string, replace, first);
		printf("%s\n", sentence);
	}

	return 0;
}

int findFirst(char sentence[], char string[]){
	int sentLen = strlen(sentence);
	int strLen = strlen(string);
	for(int i = 0; i < sentLen - strLen; i++)
		if(strncmp(sentence + i, string, strLen) == 0)
			return i;
	return -1;
}

void replaceFirstOccurance(char sentence[], char string[], char replace[], int firstOccurance){
	int strLen = strlen(string);
	char temp[100];
	strcpy(temp, replace);
	strcat(temp, sentence + firstOccurance + strLen);
	strcpy(sentence + firstOccurance, temp);
}
