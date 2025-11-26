#include <stdio.h>

int showMenu(int *choice);

int main(){

	FILE *inp;
	inp = fopen("reservations.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		int roomID[30], numberOfdays[30], status, i = 0, price, totalPrice[30], choice;
		char roomType[30];
		status = fscanf(inp, "%d %c %d", &roomID[i], &roomType[i], &numberOfdays[i]);
		switch(roomType[i]){
			case 'S': 
				price = 3000;
				break;
			case 'D':
				price = 2000;
				break;
			case 'A':
				price = 1500;
		}
		totalPrice[i] = price * numberOfdays[i];
		while(status != EOF){
			i++;
			status = fscanf(inp, "%d %c %d", &roomID[i], &roomType[i], &numberOfdays[i]);
			switch(roomType[i]){
				case 'S': 
					price = 3000;
					break;
				case 'D':
					price = 2000;
					break;
				case 'A':
					price = 1500;
			}
			totalPrice[i] = price * numberOfdays[i];
		}
		do{
			showMenu(&choice);
		} while(choice != 5);
	}

	return 0;
}

int showMenu(int *choice){
	int menu;
	printf("--- WINTER HOTEL RESERVATION MENU ---\n");
	printf("1. New Reservation\n");
	printf("2. Display Reservations\n");
	printf("3. Total number of Suits reserved\n");
	printf("4. Display all statistics\n");
	printf("5. Exit\n");
	do{
		printf("Enter Your choice (1-5): ");
		scanf("%d", &*choice);
	} while(menu > 5 && menu < 1);
	return menu;
}
