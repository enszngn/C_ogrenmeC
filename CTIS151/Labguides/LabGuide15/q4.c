#include <stdio.h>

int readFromFile(FILE *inp, int filmId[], double filmRating[], char filmType[]);

void displayFilm(int filmId, double filmRating, char filmType, int filmNumber);

void display(int filmId[], double filmRating[], char filmType[], int filmNumber);

int searchFilm(int filmId[], int filmNumber, int searchedFilmId);

int main(){

	FILE *inp;
	inp = fopen("films.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		int filmId[30], filmNumber, searchedFilmId, index;
		double filmRating[30];
		char filmType[30];
		filmNumber = readFromFile(inp, filmId, filmRating, filmType);
		display(filmId, filmRating, filmType, filmNumber);
		printf("\nEnter a film id to search (negative id to stop): ");
		scanf("%d", &searchedFilmId);
		while(searchedFilmId >= 0){
			index = searchFilm(filmId, filmNumber, searchedFilmId);
			if(index == -1)
				printf("Searched film id %d is not found\n", searchedFilmId);
			else
				displayFilm(filmId[index], filmRating[index], filmType[index], filmNumber);
			printf("\nEnter a film id to search (negative id to stop): ");
			scanf("%d", &searchedFilmId);
		}
		fclose(inp);
	}

	return 0;
}

int readFromFile(FILE *inp, int filmId[], double filmRating[], char filmType[]){
	int status, filmNumber = 0;
	status = fscanf(inp, "%d %lf %c", &filmId[filmNumber], &filmRating[filmNumber], &filmType[filmNumber]);
	while(status != EOF){
		filmNumber++;
		status = fscanf(inp, "%d %lf %c", &filmId[filmNumber], &filmRating[filmNumber], &filmType[filmNumber]);
	}
	return filmNumber;
}

void displayFilm(int filmId, double filmRating, char filmType, int filmNumber){
	printf("%7d  %4.1f  ", filmId, filmRating);
	switch(filmType){
		case 'C': printf("Comedy\n");
		break;
		case 'H': printf("Horror\n");
		break;
		case 'D': printf("Drama\n");
	}
}

void display(int filmId[], double filmRating[], char filmType[], int filmNumber){
	printf("Film ID  Rate  Type\n");
	printf("*******  ****  ******\n");
	for(int i = 0; i < filmNumber; i++){
		displayFilm(filmId[i], filmRating[i], filmType[i], filmNumber);
	}
}

int searchFilm(int filmId[], int filmNumber, int searchedFilmId){
	int i;
	for(i = 0; i < filmNumber; i++)
		if(filmId[i] == searchedFilmId)
			return i;
	return -1;
}
