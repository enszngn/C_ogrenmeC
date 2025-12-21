#include <stdio.h>
#include <math.h>

int isFourDigit(int num);

void separate(int num, int *sep1, int *sep2);

int main(){
	FILE *inp;
	inp = fopen("nums.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		printf("Numbers providing the equation are\n-------------------------------\n");
		int sep1, sep2, num, status;
		FILE *outp;
		outp = fopen("fourdigit.txt", "w");
		status = fscanf(inp, "%d", &num);
		while(status != EOF){
			if(isFourDigit(num)){
				separate(num, &sep1, &sep2);
				fprintf(outp, "%d ", num);
				fprintf(outp, "%d ", sep1);
				fprintf(outp, "%d ", sep2);
				if(num == pow(sep1 + sep2, 2)){
					fprintf(outp, "*");
					printf("%d\n", num);
				}
				fprintf(outp, "\n");
			}
			status = fscanf(inp, "%d", &num);
		}
		fclose(inp);
		fclose(outp);
	}

	return 0;
}

void separate(int num, int *sep1, int *sep2){
	*sep1 = num / 100;
	*sep2 = num % 100;
}

int isFourDigit(int num){
	if(num / 1000 >= 1 && num / 1000 <= 9)
		return 1;
	return 0;
}
