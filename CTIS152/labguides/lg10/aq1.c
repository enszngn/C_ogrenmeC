#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[20];
	char surname[20];
	int birth_year;
}people_t;

void swap(people_t *people, people_t *people2);

void bubble_sort_two_level(people_t people[], int num_of_people);

int main(){

	FILE *inp;
	inp = fopen("people.txt", "r");
	if(inp == NULL)
		printf("ERROR\n");
	else{
		FILE *outp;
		outp = fopen("sorted.txt", "w");
		people_t people[20];
		int status = 1, i = 0;
		do{
			status = fscanf(inp, "%s %s %d", (people + i)->name, (people + i)->surname, &(people + i)->birth_year); 
			i++;
		} while (status != EOF);
		// increments i one more time after status == EOF, hence the value people[i] is garbage

		bubble_sort_two_level(people, i - 1);
		for(int p = 0; p < i - 1; p++){
			printf("%-20s %-20s %4d\n", (people+p)->name, (people+p)->surname, (people+p)->birth_year);
		}

		fclose(inp);
		fclose(outp);
	}

	return 0;
}

void swap(people_t *people1, people_t *people2){
	people_t temp;
	strcpy(temp.surname, people1->surname);
	strcpy(people1->surname, people2->surname);
	strcpy(people2->surname, temp.surname);
	strcpy(temp.name, people1->name);
	strcpy(people1->name, people2->name);
	strcpy(people2->name, temp.name);
	temp.birth_year = people1->birth_year;
	people1->birth_year = people2->birth_year;
	people2->birth_year = temp.birth_year;
}

void bubble_sort_two_level(people_t people[], int num_of_people){
	int i, pass = 0, sorted;
	do{
		sorted = 1;
		for(i = 0; i < num_of_people - pass; i++){
			if(strcmp((people + i)->surname, (people + i + 1)->surname) > 0){
				swap(people + i, people + i + 1);
				sorted = 0;
			}
		}
		pass++;
	} while(!sorted);
	do{
		sorted = 1;
		for(i = 0; i < num_of_people; i++){
			if(strcmp((people + i)->surname, (people + i + 1)->surname) == 0 && strcmp((people + i)->name, (people + i + 1)->name) > 0){
				swap(people + i, people + i + 1);
				sorted = 0;
			}
		}
	} while(!sorted);
}

