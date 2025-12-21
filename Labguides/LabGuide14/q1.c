#include <stdio.h>

int main(){

	FILE *inp;
	inp = fopen("movies.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		int contentID[10], ageGroup[10], status, i = 0;
		char contentType[10];

		status = fscanf(inp, "%d %c %d", &contentID[i], &contentType[i], &ageGroup[i] );
		while(status != EOF){
			i++;
			status = fscanf(inp, "%d %c %d", &contentID[i], &contentType[i], &ageGroup[i] );
		}
		printf("FILMS FOR AGES 10+\n");
		for(int p = 0; p < i; p++){
			if(ageGroup[p] > 10 && contentType[p] == 'F')
				printf("%d\n", contentID[p]);
		}
		fclose(inp);
	}

	return 0;
}
