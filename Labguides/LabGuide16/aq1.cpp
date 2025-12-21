#include <stdio.h>

int main(){

	FILE *inp;
	inp = fopen("calories.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		double calories[6][5];
		double average[5] = {0};
		for(int i = 0; i < 5; i++){
			for(int p = 0; p < 6; p++){
				fscanf(inp, "%lf", &calories[p][i]);
				if(p > 0){
					average[i] += calories[p][i];
				}
			}
			average[i] /= 5;
		}
		FILE *outp;
		outp = fopen("output.txt", "w");
		fprintf(outp, "ID    AVERAGE   LOSE WEIGHT\n");
		fprintf(outp, "***************************\n");
		for(int i = 0; i < 5; i++){
			fprintf(outp, "%d%d%d   %-7.1f", i + 1, i + 1, i + 1, average[i]);
			if(average[i] > 2200)
				fprintf(outp, "       %c\n", 'Y');
			else
				fprintf(outp, "       %c\n", 'N');
		}
		fclose(inp);
		fclose(outp);
	}

	return 0;
}
