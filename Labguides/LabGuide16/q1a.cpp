#include <stdio.h>

int main(){

	int arr[3][3]{{75, 20, 77}, {71, 23, 45}, {67, 89, 98}};
	for(int i = 0; i < 3; i++){
		for(int p = 0; p < 3; p++){
			printf("%d  ", arr[i][p]);
		}
		printf("\n");
	}

	return 0;
}
