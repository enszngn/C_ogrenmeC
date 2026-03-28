#include <stdio.h>
#include <string.h>

int findFirst(char sentence[], char string[]);

int main(){

	char sentence[100];
	printf("Enter a sentence: ");
	scanf("%[^\n]", sentence);
	char string[20];
	printf("\nEnter a string: ");
	scanf("%s", string);
	int first = findFirst(sentence, string);
	if(first == -1)
		printf("The sentence does NOT contain the string <%s>\n", string);
	else
		printf("The first occurance of the string <%s> is %d\n", string, first);

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
