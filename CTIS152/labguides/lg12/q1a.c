#include <stdio.h>

int main(){

	FILE *inp;
	inp = fopen("nums.bin", "rb");
	if(inp == NULL)
		printf("ERROR\n");
	else{
		int num;
		int count = 0;
		count += fread(&num, sizeof(int), 1, inp);
		while(!feof(inp)){
			printf("%d  ", num);
			count += fread(&num, sizeof(int), 1, inp);
		}
		printf("\n\nThere are %d numbers in the file\n", count - 1);

		fclose(inp);
	}

	return 0;
}
