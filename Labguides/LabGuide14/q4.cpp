#include <stdio.h>

void showMenu(int *choice);

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
			switch(choice){
			case 1: {
				int reservation, isReserved = 0;
				printf("Enter roomID : ");
				scanf("%d", &reservation);
				for(int p = 0; p < i && isReserved != 1; p++)
					if(reservation == roomID[p]){
						isReserved = 1;
						printf("Sorry! The room is reserved.\n");
					}
				if(isReserved == 0){
					char roomtype;
					int numberOfDays;
					printf("Enter Type: ");
					scanf(" %c", &roomtype);
					printf("Enter number of days: ");
					scanf("%d", &numberOfDays);
					roomID[i] = reservation;
					roomType[i] = roomtype;
					numberOfdays[i] = numberOfDays;
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
						i++;
					}
					break;
				}
				case 2:
					printf("Total number of reservations: %d\n\n", i);
					printf("S: Suit, D: Double, A: Apart\n\n");
					printf("RoomID  Type  #ofDays\n");
					printf("******  ****  *******\n");
					for(int k = 0; k < i; k++)
						printf(" %d     %c       %d\n", roomID[k], roomType[k], numberOfdays[k]);
					break;
				case 3: {
					int numOfSuits = 0, suitIndex[i], p, k;
					for(k = 0, p = 0; k < i; k++)
						if(roomType[k] == 'S'){
							numOfSuits++;
							suitIndex[p] = k; 
							p++;
						}
					printf("\nTotal number of suits reserved: %d\n", numOfSuits);
					int totalRevenue = 0;
					for(k = 0; k < p; k++)
						totalRevenue += totalPrice[suitIndex[k]];
					printf("Total revenue from suits reserved: %d\n", totalRevenue);
				}
					break;
				case 4: {
					printf("--- ALL STATISTICS ---\n");
					printf("Total reservations: %d\n", i);
					int totalRevenue = 0, k;
					int numberOfSuit = 0, numberOfDouble = 0, numberOfApart = 0;
					int revenueSuit = 0, revenueDouble = 0, revenueApart = 0;
					for(k = 0; k < i; k++){
						totalRevenue += totalPrice[k];
						if(roomType[k] == 'S'){
							numberOfSuit++;
							revenueSuit += totalPrice[k];
						}
						else if(roomType[k] == 'D'){
							numberOfDouble++;
							revenueDouble += totalPrice[k];
						}
						else if(roomType[k] == 'A'){
							numberOfApart++;
							revenueApart += totalPrice[k];
						}
					}
					printf("Total revenue: %d TL\n", totalRevenue);
					printf("Room Type   #of Reservations   Revenue\n\n");
					printf("*********   ****************   *******\n");
					printf("Suit               %-2d          %d TL\n", numberOfSuit, revenueSuit);
					printf("Double             %-2d          %d TL\n", numberOfDouble, revenueDouble);
					printf("Apart              %-2d          %d TL\n", numberOfApart, revenueApart);
				}
			}
		} while(choice != 5);

	}

	return 0;
}

void showMenu(int *choice){
	printf("\n\n--- WINTER HOTEL RESERVATION MENU ---\n");
	printf("1. New Reservation\n");
	printf("2. Display Reservations\n");
	printf("3. Total number of Suits reserved\n");
	printf("4. Display all statistics\n");
	printf("5. Exit\n");
	printf("Enter your choice (1-5): ");
	scanf("%d", &*choice);
	while(*choice > 5 || *choice < 1){
		printf("Invalid choice! Please enter a number between 1 and 5.\n");
		printf("\nEnter your choice (1-5): ");
		scanf("%d", &*choice);
	} 
}
