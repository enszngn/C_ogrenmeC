#include <stdio.h>

void drawStairs(int numberOfSteps, int stepLenght);

int main(){

	int numberOfSteps, stepLenght;
	do{
		printf("Enter the number of steps (2 - 10): ");
		scanf("%d", &numberOfSteps);
	} while(numberOfSteps < 2 || numberOfSteps > 10);
	do{
		printf("Ebter the step lenght (3 - 10): ");
		scanf("%d", &stepLenght);
	} while(stepLenght < 3 || stepLenght > 10);

	drawStairs(numberOfSteps, stepLenght);

	return 0;
}

void drawStairs(int numberOfSteps, int stepLenght){
	int i;
	for(i = 0; i < numberOfSteps; i++){
		for(int p = 0; p < i * (stepLenght - 1); p++){
			printf(" ");
		}
		for(int p = 0; p < stepLenght; p++){
			printf("*");
		}
		printf("\n");
		for(int p = 0; p < (i + 1) * (stepLenght - 1); p++){
			printf(" ");
		}
		printf("*\n");
	}
	for(int p = 0; p < i * (stepLenght - 1); p++){
		printf(" ");
	}
	printf("*\n");

}
