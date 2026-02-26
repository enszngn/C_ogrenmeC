#include <stdio.h>

int main(){

	FILE *inp;
	inp = fopen("nums.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		int arr[8][8];
		for(int i = 0; i < 8; i++){
			for(int p = 0; p < 8; p++)
				fscanf(inp, "%d", &arr[i][p]);
		}
		for(int i = 0; i < 8; i++){
			for(int p = 0; p < 8; p++)
				printf("%2d ", arr[i][p]);
			printf("\n");
		}
		fclose(inp);
	}

	return 0;
}
