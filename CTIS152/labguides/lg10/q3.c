#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct publication_data{
	char title[40];
	char name[40];
	int citation_count;
} publication_data_t;

void readFromFile(FILE *inp, publication_data_t *publications, int num_of_publications);

void swap(int *num1, int *num2);

void bubbleSort(publication_data_t *publications, int num_of_publications);

void display(publication_data_t *publications, int num_of_publications);

int main(){

	FILE *inp;
	inp = fopen("publications.txt", "r");
	if(inp == NULL)
		printf("ERROR\n");
	else{
		int num_of_publications;
		fscanf(inp, "%d", &num_of_publications);
		publication_data_t *publications;
		publications = (publication_data_t *)malloc(sizeof(publication_data_t) * num_of_publications);
		readFromFile(inp, publications, num_of_publications);
		bubbleSort(publications, num_of_publications);
		display(publications, num_of_publications);
	}

	return 0;
}

void readFromFile(FILE *inp, publication_data_t *publications, int num_of_publications){
	for(int i = 0; i < num_of_publications; i++){
		fscanf(inp, " %[^,], %[^,],", (publications + i)->title, (publications + i)->name);
		fscanf(inp, "%d", &(publications + i)->citation_count);
	}
}

void swap(int *num1, int *num2){
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void swap_strings(char word1[], char word2[]){
	char temp[40];
	strcpy(temp, word1);
	strcpy(word1, word2);
	strcpy(word2, temp);
}

void bubbleSort(publication_data_t *publications, int num_of_publications){
	for(int i = 1; i < num_of_publications; i++){
		for(int p = 0; p < num_of_publications - i; p++)
			if((publications + p)->citation_count < (publications + p + 1)->citation_count){
				swap(&(publications + p)->citation_count, &(publications + p + 1)->citation_count);
				swap_strings((publications + p)->name, (publications + p + 1)->name);
				swap_strings((publications + p)->title, (publications + p + 1)->title);
			}
	}
}

void display(publication_data_t *publications, int num_of_publications){
	printf("%-40s %-40s %-8s\n", "Paper Title", "Journal Name", "Citation");
	printf("*************************************************************************************************\n");
	for(int i = 0; i < num_of_publications; i++){
		printf("%-40s %-40s %3d\n", (publications + i)->title, (publications + i)->name, (publications + i)->citation_count);
	}
}
