#include <stdio.h>

int readFromFile(FILE *inp, int teamID[], int gameScores[][4]);

void findTeamAverage(int gameScores[][4], int numberOfTeams, double averageOfEach[10]);

void findGameAverage(int gameScores[][4], int numberOfTeams, double averageOfGame[10]);

void displayGameAvg(double averageOfGame[]);

int main(){

	FILE *pInp;
	pInp = fopen("dart.txt", "r");
	if(pInp == NULL)
		printf("ERROR");
	else{
		int teamID[10], gameScores[10][4], numberOfTeams;
		double averageOfEach[10], averageOfGame[4];
		numberOfTeams = readFromFile(pInp, teamID, gameScores);
		for(int i = 0; i < 10; i++){
			printf("%d  ", teamID[i]);
			for(int p = 0; p < 4; p++)
				printf("%d  ", gameScores[i][p]);
			printf("\n");
		}
		findTeamAverage(gameScores, numberOfTeams, averageOfEach);
		printf("Team Number   Average\n");
		printf("***********   *******\n");
		for(int i = 0; i < numberOfTeams; i++){
			printf(" %2d           %6.2f\n", teamID[i], averageOfEach[i]);
		}
		findGameAverage(gameScores, numberOfTeams, averageOfGame);
		displayGameAvg(averageOfGame);
	}

	return 0;
}

int readFromFile(FILE *inp, int teamID[], int gameScores[][4]){
	int i;
	for(i = 0; i < 10; i++){
		fscanf(inp, "%d", &teamID[i]);
		for(int p = 0; p < 4; p++)
			fscanf(inp, "%d", &gameScores[i][p]);
	}
	return i;
}

void findTeamAverage(int gameScores[][4], int numberOfTeams, double averageOfEach[10]){
	double average = 0;
	for(int i = 0; i < numberOfTeams; i++){
		for(int p = 0; p < 4; p++){
			average += gameScores[i][p];
		}
		average /= 4;
		averageOfEach[i] = average;
		average = 0;
	}
}

void findGameAverage(int gameScores[][4], int numberOfTeams, double averageOfGame[10]){
	double average = 0;
	for(int i = 0; i < 4; i++){
		for(int p = 0; p < numberOfTeams; p++){
			average += gameScores[p][i];
		}
		average /= 10;
		averageOfGame[i] = average;
		average = 0;
	}
}

void displayGameAvg(double averageOfGame[]){
	printf("\nGame Number   Average\n");
	printf("***********   *******\n");
	for(int i = 0; i < 4; i++){
		printf(" %d            %5.1f\n", i + 1, averageOfGame[i]);
	}
}
