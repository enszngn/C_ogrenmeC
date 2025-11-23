#include <stdio.h>

int main(){

	FILE *inp;
	inp = fopen("mytext2.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		FILE *outp;
		outp = fopen("compressed.txt", "w");
		int status, numOfChar = 0;
		char ch;
		status = fscanf(inp, "%c", &ch);
		while(status != EOF){
			char temp = ch;
			while(status != EOF && temp == ch){
				numOfChar++;
				status = fscanf(inp, "%c", &ch);
			}
			if(numOfChar > 1)
				fprintf(outp, "%c%d", temp, numOfChar);
			else
				fprintf(outp, "%c", temp);
			numOfChar = 0;
		}
		fclose(inp);
		fclose(outp);
	}

	return 0;
}
