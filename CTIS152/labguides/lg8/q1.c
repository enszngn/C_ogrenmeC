#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_first(char sentence[], char word[]);

int main(){

	char sentence[100];
	char word[20];

	return 0;
}

int find_first(char sentence[], char word[]){
	int i = 0;
	while(sentence[i] != '\0')
		if(strncmp((sentence + i), word, strlen(word)) == 0)
			return i;
	return -1;
}
