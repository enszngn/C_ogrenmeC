#include <stdio.h>


int main(){

	FILE *reader;

	reader = fopen("data.txt", "r");

	if(reader == NULL)
		printf("Error");
	else{
		int number, status;
		
		status = fscanf(reader, "%d", &number);
		while(status != EOF) {
			printf("%d ", number);
			status = fscanf(reader, "%d", &number);	
		}
		fclose(reader);
	}


	return 0;
}
