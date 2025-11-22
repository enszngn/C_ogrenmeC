#include <stdio.h>

int main(){
	int term = 1;
	int lenght = 5;
	for(int i = 0; i < lenght; i++){
		for(int j = 1; j <= lenght - i; j++)
			printf("  ");
		for(int p = 0; p <= i; p++){
			if(p == 0 || i == 0)
				term = 1;
			else
				term = term * (i - p + 1) / p;
			printf("%4c", 'B' + term);
		}
		printf("\n");
	}
}
