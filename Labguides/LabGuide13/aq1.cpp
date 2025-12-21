#include <stdio.h>

int readFile(FILE *inp, int arr[]);
int menu(int num);

int main(){

	FILE *inp;
	inp = fopen("numbers.txt", "r");

	if(inp == NULL)
		printf("ERROR");
	else{
		int arr[30];
		int count = readFile(inp, arr);
		int num;
		do{
			num = menu(num);
			switch(num){
				case 1: 
					printf("All numbers\n************\n");
					for(int i = 0; i <= count; i++){
						printf("%d ", arr[i]);
					}
					printf("\n\n");
					break;
				case 2:
					printf("Even numbers\n***********\n");
					for(int i = 0; i <= count; i++){
						if(arr[i] % 2 == 0)	
							printf("%d ", arr[i]);
					}
					printf("\n\n");
					break;
				case 3:
					printf("Subscripts of odd numbers\n*************************\n");
					for(int i = 0; i <= count; i++){
						if(arr[i] % 2 == 1)	
							printf("%d ", i);
					}
					printf("\n\n");
					break;
				case 4:
					printf("The numbers with even subscripts\n*********************************\n");
					for(int i = 0; i <= count; i += 2)
						printf("%d ", arr[i]);
					printf("\n\n");
					break;
				case 5:
					printf("Minimum number\n*********************************\n");
					int min;
					for(int i = 0; i <= count; i++){
						if(i == 0)
							min = arr[i];
						else if(arr[i] < min)
								min = arr[i];
					}
					printf("%d\n", min);
					break;
				case 6:
					printf("Subscript of Maximum number\n*********************************\n");
					int max, subscriptMax;
					for(int i = 0; i <= count; i++){
						if(i == 0)
							max = arr[i];
						else if(arr[i] > max){
							max = arr[i];
							subscriptMax = i;
						}
					}
					printf("%d\n", subscriptMax);
					break;
			}
		} while (num != 7);

		
		fclose(inp);
	}	

	return 0;
}

int readFile(FILE *inp, int arr[]){
	int status, num, i = 0;
	status = fscanf(inp, "%d", &num);
	while(status != EOF){
		arr[i] = num;
		status = fscanf(inp, "%d", &num);
		i++;
	}
	return i - 1;
}

int menu(int num){
	printf("\nDISPLAY\n1. All numbers\n2. Even numbers\n3. Subscripts of odd numbers\n4. The numbers with even subscripts\n5. Minimum number\n6. Subscript of maximum number\n7. Exit");
	printf("\nEnter your choice: ");
	scanf("%d", &num);
	printf("\n");
	return num;
}
