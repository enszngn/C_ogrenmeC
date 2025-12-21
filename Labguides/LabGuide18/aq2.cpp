#include <stdio.h>

int menu();

void displayCharacterInfo(int characterInfo[][6], int rows, int searchedID);

void updateStrength(int characterInfo[][6], int rows);

int findLowestDex(int characterInfo[][6], int rows);

int findHighestInt(int characterInfo[][6], int rows);

void calculateArmorRating(int characterInfo[][6], int rows, int armorRatings[], int armors[]);

void displayAll(int characterInfo[][6], int rows);

int main(){

    FILE *inp;
    inp = fopen("info.txt", "r");
    if(inp == NULL)
        printf("ERROR");
    else{
        int characterInfo[4][6];
        int status = 1, i;
        int choice;
        int armorRatings[3] = {3, 2 , 1};
        int armorsOfCharacters[6];
        for(i = 0; i < 6 && status != EOF; i++){
            for(int p = 0; p < 4 && status != EOF; p++){
                status = fscanf(inp, "%d", &characterInfo[p][i]);
            }
        }
        int characterID;
        do{
            choice = menu();
            switch(choice){
                case 1:
                    printf("Enter character ID: ");
                    scanf("%d", &characterID);
                    displayCharacterInfo(characterInfo, i, characterID);
                    break;
                case 2:
                    updateStrength(characterInfo, i);
                    printf("Strength updated.\n");
                    break;
                case 3:
                    printf("Character with lowest dexterity has ID: %d\n", characterInfo[0][findLowestDex(characterInfo, i)]);
                    break;
                case 4:
                    printf("Character with the highest intelligence has ID: %d\n", characterInfo[0][findHighestInt(characterInfo, i)]);
                    break;
                case 5:
                    displayAll(characterInfo, i);
                    break;
                case 6:
                    printf("Armor ratings:\n");
                    calculateArmorRating(characterInfo, i, armorRatings, armorsOfCharacters);
                    for(int x = 0; x < i; x++){
                        printf("ID %d: %d\n", characterInfo[0][x], armorsOfCharacters[x]);
                    }
                    break;
                case 7:
                    printf("Exiting Program.\n");

            }
        } while(choice != 7);
        fclose(inp);
    }

    return 0;
}

int menu(){
    int choice;
    printf("\n1) Display character info\n");
    printf("2) Update strength of all characters\n");
    printf("3) Find ID of character with lowest dexterity\n");
    printf("4) Find ID of character with highest intelligence\n");
    printf("5) Display all characters\n");
    printf("6) Calculate armor ratings\n");
    printf("7) Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void displayCharacterInfo(int characterInfo[][6], int rows, int searchedID){
    for(int i = 0; i < rows; i++)
        if (characterInfo[0][i] == searchedID)
            printf("ID: %d, Strength: %d, Dexterity: %d, Intelligence: %d\n", characterInfo[0][i], characterInfo[1][i], characterInfo[2][i], characterInfo[3][i]);
}

void updateStrength(int characterInfo[][6], int rows){
    int amountToIncrease;
    printf("Enter the number to increase strength by: ");
    scanf("%d", &amountToIncrease);
    for(int i = 0; i < rows; i++)
        characterInfo[1][i] += amountToIncrease;
}

int findLowestDex(int characterInfo[][6], int rows){
    int min = characterInfo[2][0], minIndex = 0;
    for(int i = 0; i < rows; i++)
        if(characterInfo[2][i] < min){
            min = characterInfo[2][i];
            minIndex = i;
        }
    return minIndex;
}

int findHighestInt(int characterInfo[][6], int rows){
    int max = characterInfo[3][0], maxIndex = 0;
    for(int i = 0; i < rows; i++)
        if(characterInfo[3][i] > max){
            max = characterInfo[3][i];
            maxIndex = i;
        }
    return maxIndex;
}

void calculateArmorRating(int characterInfo[][6], int rows, int armorRatings[], int armors[]){
    for(int i = 0; i < rows; i++)
        armors[i] = characterInfo[1][i] * armorRatings[0] + characterInfo[2][i] * armorRatings[1] + characterInfo[3][i] * armorRatings[2];
}

void displayAll(int characterInfo[][6], int rows){
    printf("ID \tStrength\tDexterity\tIntelligence\n");
    for(int i = 0; i < rows; i++){
        printf("%3d\t%8d\t%9d\t%12d\n", characterInfo[0][i], characterInfo[1][i], characterInfo[2][i], characterInfo[3][i]);
    }
}