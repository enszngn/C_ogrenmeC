#include <stdio.h>

int main(){

	FILE *inp;
	inp = fopen("mytext1.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		FILE *outp;
		outp = fopen("final.txt", "w");
		int status, numOfChar;
		char ch;
   		status = fscanf(inp, "%c %d", &ch, &numOfChar);
		while(status != EOF){
			for(int i = 0; i < numOfChar; i++)
				fprintf(outp, "%c", ch);
			fprintf(outp, "\n");
			status = fscanf(inp, "%c", &ch);
			status = fscanf(inp, "%d", &numOfChar);

		}
		fclose(inp);
		fclose(outp);
	} 

	return 0;
}
