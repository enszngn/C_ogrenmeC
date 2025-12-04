#include <stdio.h>

int main(){

	FILE *inp;
	inp = fopen("grades.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		FILE *outp;
		outp = fopen("average.txt", "w");
		double grades[6][10];
		double average = 0;
		for(int i = 0; i < 10; i++){
			for(int p = 0; p < 6; p++)
				fscanf(inp, "%lf", &grades[p][i]);
		}
		printf("Quiz Number    Average\n");
		for(int i = 1; i < 6; i++){
			printf("    %d            ", i);
			for(int p = 0; p < 10; p++){
				average += grades[i][p];
			}
			average /= 10;
			printf("%4.2f\n", average);
			average = 0;
		}
		for(int i = 0; i < 10; i++){
			fprintf(outp, "%.0f  ", grades[0][i]);
			for(int p = 1; p < 6; p++){
				average += grades[p][i];
			}
			average /= 5;
			fprintf(outp, "%.1f\n", average);
			average = 0;
		}
	}

	return 0;
}
