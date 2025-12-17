#include <stdio.h>

int findTotalVote(int votes[][20]);

int main(){

    FILE *inp;
    inp = fopen("votes.txt", "r");
    if(inp == NULL)
        printf("ERROR");
    else{
        int votes[20][3];
        int status = 1;
        for(int i = 0; i < 3; i++){
            for(int p = 0; p < 20 || status != EOF; p++)
                status = fscanf(inp, "%d", &votes[p][i]);
        }

    }

    return 0;
}

int findTotalVote(int votes[][20], int columnNumber){
    int total = 0;
    for(int i = 0; i < columnNumber; i++){
        for(int p = 0; p < 20; p++)
            total += votes[p][i];
    }
}