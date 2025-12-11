#include <stdio.h>
#define SIZE 9

void readFromFile(FILE *inp, char arr[SIZE][SIZE]);

void displayTwoDimension(char arr[SIZE][SIZE]);

void displayDimension(char arr[SIZE][SIZE], int dimension);

int main() {

  FILE *inp;
  inp = fopen("words.txt", "r");
  if (inp == NULL)
    printf("ERROR");
  else {
    int dimension;
    char words[SIZE][SIZE];
    readFromFile(inp, words);
    displayTwoDimension(words);
    do {
      printf("Enter the dimension: [1-9]  ");
      scanf("%d", &dimension);
    } while ((dimension < 1 || dimension > 9) && dimension != -1);
    while (dimension != -1) {
      displayDimension(words, dimension);
      do {
        printf("Enter the dimension: [1-9]  ");
        scanf("%d", &dimension);
      } while ((dimension < 1 || dimension > 9) && dimension != -1);
    }
    printf("EXIT!\n");
  }

  return 0;
}

void readFromFile(FILE *inp, char arr[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int p = 0; p < SIZE; p++)
      fscanf(inp, "%c ", &arr[p][i]);
  }
}

void displayTwoDimension(char arr[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int p = 0; p < SIZE; p++)
      printf("%c", arr[p][i]);
    printf("\n");
  }
}

void displayDimension(char arr[SIZE][SIZE], int dimension) {
  printf("Dimension for %d, MAJOR elements of the file is: ", dimension);
  for (int i = 0; i < dimension; i++)
    printf("%c", arr[i][i]);
  printf("\n");
  printf("Dimension for %d, MINOR elements of the file is: ", dimension);
  for (int i = 0; i < dimension; i++)
    printf("%c", arr[dimension - i - 1][i]);
  printf("\n");
}
