#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	char vendorName[20];
	char customerName[20];
	char productName[25];
	int quantity;
	double price;
	char status[15];
} order_t;

int main(){

	FILE *inp;
	inp = fopen("orders.bin", "rb");
	if(inp == NULL)
		printf("ERROR\n");
	else{
		order_t *orders;
		fseek(inp, 0, SEEK_END);
		int size = ftell(inp) / sizeof(order_t);
		rewind(inp);
		orders = (order_t *)malloc(sizeof(order_t) * size);
		printf("There are %d orders in the file\n\n", size);
		fread(orders, sizeof(order_t), size, inp);
		srand(time(NULL));
		int random = rand() % size + 1;
		printf("%d orders will be displayed\n\n", random);
		printf("Vendor           Customer        Product          Quantity   Price      Status\n");
		printf("------------------------------------------------------------------------------\n");
		for(int i = 0; i < random; i++)
			printf("%-12s     %-15s     %-17s      %2d       $%6.2f    %s\n", (orders + i)->vendorName, (orders + i)->customerName, (orders + i)->productName, (orders + i)->quantity, (orders + i)->price, (orders + i)->status);

		fclose(inp);
		free(orders);
	}

	return 0;
}
