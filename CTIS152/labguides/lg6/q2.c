#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct room_info{
	int number;
	char type;
}room_info_t;

typedef struct customer_information{
	char name[20];
	int birth_year;
	int day;
	double payment;
	room_info_t room_info;
}customer_information_t;

void readFromFile(FILE *inp, customer_information_t customers[], int n);

void displayAll(customer_information_t customers[], int n);

double calculateTotalEarnings(customer_information_t customers[], int n);

int findCustomerMaxPayment(customer_information_t customers[], int n);

int main(){

	FILE *inp;
	inp = fopen("customers.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		srand(time(NULL));
		int n = rand() % 16 + 5;
		double totalEarnings;
		int maxPaymentIndex;
		customer_information_t *customers;
		customers = (customer_information_t *)malloc(sizeof(customer_information_t) * n);
		readFromFile(inp, customers, n);
		printf("%d Customers' info will be read\n", n);
		displayAll(customers, n);
		totalEarnings = calculateTotalEarnings(customers, n);
		maxPaymentIndex = findCustomerMaxPayment(customers, n);
		printf("\nTotal Earnings of the hotel : %.2f\n", totalEarnings);
		printf("The Customer having maximum payment for accommodation:\n");
		printf("%s with the price %.2f\n", (customers + maxPaymentIndex)->name, (customers + maxPaymentIndex)->payment);
	}

	return 0;
}

void readFromFile(FILE *inp, customer_information_t customers[], int n){
	double price;
	for(int i = 0; i < n; i++){
		fscanf(inp, "%s %d %d %d %c", (customers + i)->name, &(customers + i)->birth_year, &(customers + i)->day, &(customers + i)->room_info.number, &(customers + i)->room_info.type);
		switch((customers + i)->room_info.type){
		case 'S': price = 3000;
			break;
		case 'T': price = 7500;
			break;
		case 'D': price = 10500;
		}
		(customers + i)->payment = (customers + i)->day * price;
	}
}

void displayAll(customer_information_t customers[], int n){
	printf("Name               Byear   Day   Room Num   Type    Payment\n");
	printf("-----------------------------------------------------------\n");
	for(int i = 0; i < n; i++){
		printf("%-15s     %d     %d    %d        %c    %8.2f\n", (customers + i)->name, (customers + i)->birth_year, (customers + i)->day, (customers + i)->room_info.number, (customers + i)->room_info.type, (customers + i)->payment);
	}
}

double calculateTotalEarnings(customer_information_t customers[], int n){
	double total = 0;
	for(int i = 0; i < n; i++)
		total += (customers + i)->payment;
	return total;
}

int findCustomerMaxPayment(customer_information_t customers[], int n){
	int maxPayment = customers->payment;
	int maxPaymentIndex = 0;
	int i;
	for(i = 0; i < n; i++)
		if((customers + i)->payment > maxPayment){
			maxPayment = (customers + i)->payment;
			maxPaymentIndex = i;
		}
	return i;
}

