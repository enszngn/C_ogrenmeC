#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char word1[], char word2[]);

void bubble_sort(char words[][40], int num_of_words);

int main(){

	char words[20][40];
	int i = 0;
	printf("Enter a street name (finish to stop): ");
	scanf(" %[^\n]", words[i]);
	while(strcmp(words[i], "finish") != 0){
		i++;
		printf("Enter a street name (finish to stop): ");
		scanf(" %[^\n]", words[i]);
	} //finish is also stored as a value
	bubble_sort(words, i);
	for(int p = 0; p < i; p++)
		printf("%d) %s\n", p + 1, words[p]);

	return 0;
}

void swap(char word1[], char word2[]){
	char temp[40];
	strcpy(temp, word1);
	strcpy(word1, word2);
	strcpy(word2, temp);
}

void bubble_sort(char words[][40], int num_of_words){
	for(int i = 1; i < num_of_words; i++)
		for(int p = 0; p < num_of_words - i; p++)
			if(strcmp(words[p], words[p + 1]) < 0)
				swap(words[p], words[p + 1]);
}
