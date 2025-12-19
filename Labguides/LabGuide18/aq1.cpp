#include <stdio.h>

int findTotalVote(int votes[][20], int columnSize, char givenCity, int partyVotes[]);

double findPercentage(int votesParty, int votesTotal);

int main(){

	FILE *inp;
	inp = fopen("votes.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		int votes[3][20];
		int partyVotesAnkara[5];
		int partyVotesIstanbul[5];
		int status, i = 0;
		status = fscanf(inp, "%d %d %c", &votes[1][i], &votes[2][i], &votes[3][i]);
		while(status != EOF){
			i++;
			status = fscanf(inp, "%d %d %c", &votes[1][i], &votes[2][i], &votes[3][i]);
		}
		int totalAnkara = findTotalVote(votes, 3, 'A', partyVotesAnkara);
		int totalIstanbul = findTotalVote(votes, 3, 'I', partyVotesIstanbul);
		printf("City Code       Ankara       Istanbul \n");
		printf("*********     **********    **********\n");
		printf("  Total          %4d           %4d   \n", totalAnkara, totalIstanbul);
		for(int i = 0; i < 5; i++){
			printf("    %d         %d  %4.1f     %d   %4.1f",
		}
		fclose(inp);
	}

	return 0;
}

int findTotalVote(int votes[][20], int columnSize, char givenCity, int partyVotes[]){
	int size = 0;
	for(int i = 0; i < 20; i++){
		if(votes[3][i] == givenCity){
			size += votes[2][i];
			partyVotes[votes[0][i] - 1] += votes[2][i];
		}
	}
	return size;
}

double findPercentage(int votesParty, int votesTotal){
	return 1.0 * votesParty / votesTotal * 100; 
}
