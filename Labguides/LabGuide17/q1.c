#include <stdio.h>

void displayRowWise(int arr[][5]);

void displayColumnWise(int arr[][5]);

int main() {

  FILE *inp;
  inp = fopen("nums.txt", "r");
  if (inp == NULL)
    printf("ERROR");
  else {
    int arr[5][5];
    for (int i = 0; i < 5; i++) {
      for (int p = 0; p < 5; p++)
        fscanf(inp, "%d", &arr[p][i]);
    }
    displayRowWise(arr);
    displayColumnWise(arr);
  }

  return 0;
}

void displayRowWise(int arr[][5]) {
  printf("Original array, row-wise format: \n");
  for (int i = 0; i < 5; i++) {
    for (int p = 0; p < 5; p++)
      printf("%3d  ", arr[p][i]);
    printf("\n");
  }
}

void displayColumnWise(int arr[][5]) {
  printf("\nYour array, column-wise format: \n");
  for (int i = 0; i < 5; i++) {
    for (int p = 0; p < 5; p++)
      printf("%3d  ", arr[i][p]);
    printf("\n");
  }
}
