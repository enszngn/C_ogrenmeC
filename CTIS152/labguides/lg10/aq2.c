#include <stdio.h>
#include <stdlib.h>

int readFromFile(FILE *inp, char flowers[][40]);

void display(char flowers[][40], int numberOfFlowers);

int main(){
	FILE *inp;
	inp = fopen("flowers.txt", "r");
	if(inp == NULL)
		printf("ERROR\n");
	else{
		char flowers[30][40];
		int numberOfFlowers = readFromFile(inp, flowers) + 1;
		display(flowers, numberOfFlowers);
		fclose(inp);
	}
	return 0;
}

int readFromFile(FILE *inp, char flowers[][40]){
	int i = 0, status;
	status = fscanf(inp, "%[^\n] ", flowers[i]);
	while(status != EOF){
		i++;
		status = fscanf(inp, " %[^\n]", flowers[i]);
	}
	return i;
}

void display(char flowers[][40], int numberOfFlowers){
	for(int i = 0; i < numberOfFlowers; i++)
		printf("%-40s\n", flowers[i]);
}
