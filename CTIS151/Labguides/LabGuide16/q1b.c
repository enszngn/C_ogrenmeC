#include <stdio.h>

int main(){

	int arr[3][3];
	for(int i = 0; i < 3; i++){
		for(int p = 0; p < 3; p ++){
			printf("Enter value for cell [%d][%d]:  ", i, p);
			scanf("%d", &arr[i][p]);
		}
	}
	for(int i = 0; i < 3; i++){
		for(int p = 0; p < 3; p ++){
			printf("%d  ", arr[i][p]);
		}
		printf("\n");
	}


	return 0;
}
