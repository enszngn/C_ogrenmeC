#include <stdio.h>
#define SIZE 100

int readFromFile(FILE *inp, int bandIds[], int setScores[][4]);

void findTeamAvg(int setScores[][4], int numberOfBands, double averageOfTeams[]);

void findGameAvg(int setScores[][4], int numberOfBands, double averageOfSets[]);

void displayAverages(double averageOfTeams[], double averageOfSets[], int numberOfBands, int bandIds[]);

int main(){

	FILE *inp;
	inp = fopen("rock.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		int bandIds[SIZE];
		int setScores[SIZE][4];
		int numberOfBands;
		numberOfBands = readFromFile(inp, bandIds, setScores);
		double averageOfTeams[numberOfBands];
		/*for(int r = 0; r < numberOfBands; r++){
			for(int c = 0; c < 4; c++)
				printf("%d  ", setScores[r][c]);
			printf("\n");
		}*/
		double averageOfSets[4];
		findTeamAvg(setScores, numberOfBands, averageOfTeams);
		findGameAvg(setScores, numberOfBands, averageOfSets);
		displayAverages(averageOfTeams, averageOfSets, numberOfBands, bandIds);
	}

	return 0;
}

int readFromFile(FILE *inp, int bandIds[], int setScores[][4]){
	int status = 1;
	int row;
	for(row = 0; status != EOF; row++){
		status = fscanf(inp, "%d", &bandIds[row]);
		for(int i = 0; i < 4 && status != EOF; i++)
			status = fscanf(inp, "%d", &setScores[row][i]);
	}
	return row - 1;
}

void findTeamAvg(int setScores[][4], int numberOfBands, double averageOfTeams[]){
	double average = 0;
	for(int r = 0; r < numberOfBands; r++){
		for(int c = 0; c < 4; c++)
			average += setScores[r][c];
		average /= 4;
		averageOfTeams[r] = average;
		average = 0;
	}
}

void findGameAvg(int setScores[][4], int numberOfBands, double averageOfSets[]){
	double average = 0;
	for(int c = 0; c < 4; c++){
		for(int r = 0; r < numberOfBands; r++)
			average += setScores[r][c];
		average /= numberOfBands;
		averageOfSets[c] = average;
		average = 0;
	}
}

void displayAverages(double averageOfTeams[], double averageOfSets[], int numberOfBands, int bandIds[]){
	printf("Band Number  Average\n");
	printf("***********  *******\n");
	for(int r = 0; r < numberOfBands; r++){
		printf(" %d           ", bandIds[r]);
		printf("%6.2f\n", averageOfTeams[r]);
	}
	printf("\n\n");
	printf("Set Number  Average\n");
	printf("**********  *******\n");
	for(int c = 0; c < 4; c++)
		printf(" %-10d  %6.2f\n", c + 1, averageOfSets[c]);
}
