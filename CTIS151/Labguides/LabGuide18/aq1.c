#include <stdio.h>

int findTotalVote(int votes[][20], char cities[], int rows, char givenCity, int partyVotesInGivenCity[5]);

double findPercentage(int votes, int totalVotes);

int main(){

	FILE *inp;
	inp = fopen("votes.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		int votes[2][20];
		char cities[20];
		int partyVotesAnkara[5] = {0}, totalAnkara = 0;
		int partyVotesIstanbul[5] = {0}, totalIstanbul = 0;
		int rows = 0, status;
		status = fscanf(inp, "%d %d %c", &votes[0][rows], &votes[1][rows], &cities[rows]);
		while(rows < 20 && status != EOF){
			status = fscanf(inp, "%d %d %c", &votes[0][rows], &votes[1][rows], &cities[rows]);
			rows++;
		}
		totalAnkara = findTotalVote(votes, cities, rows, 'A', partyVotesAnkara);
		totalIstanbul =  findTotalVote(votes, cities, rows, 'I', partyVotesIstanbul);
		printf("City Code       Ankara        Istanbul\n");
		printf("*********     **********     **********\n");
		printf("  Total        	 %d           %d   \n", totalAnkara, totalIstanbul);
		printf("*********     **********     **********\n");
		for(int p = 0; p < 5; p++){
			printf("    %-5d     %3d  %4.1f%%     %d  %4.1f\n", p + 1, partyVotesAnkara[p], findPercentage(partyVotesAnkara[p], totalAnkara), partyVotesIstanbul[p], findPercentage(partyVotesIstanbul[p], totalIstanbul));
		}
		fclose(inp);
	}

	return 0;
}

int findTotalVote(int votes[][20], char cities[], int rows, char givenCity, int partyVotesInGivenCity[5]){
	int totalVote = 0;
	for(int i = 0; i < rows; i++){
		if(cities[i] == givenCity){
			partyVotesInGivenCity[votes[0][i] - 1] += votes[1][i];
			totalVote += votes[1][i];
		}
	}
	return totalVote;
}

double findPercentage(int votes, int totalVotes){
	return 100.0 * votes / totalVotes;
}