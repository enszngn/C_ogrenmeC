#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		FILE *outp;
		outp = fopen("output.bin", "wb");
		order_t *orders;
		fseek(inp, 0, SEEK_END);
		int size = ftell(inp) / sizeof(order_t);
		rewind(inp);
		orders = (order_t *)malloc(sizeof(order_t) * size);
		fread(orders, sizeof(order_t), size, inp);
		printf("BINARY FILE CONTENT\n");
		printf("*******************\n\n");
		printf("Vendor           Customer        Product          Quantity   Price      Status\n");
		printf("------------------------------------------------------------------------------\n");
		order_t temp_order;
		for(int i = 0; i < size; i++)
			if(strcmp((orders + i)->status, "Completed") == 0){
				temp_order = *(orders + i);
				printf("%-12s     %-15s     %-17s      %2d       $%6.2f    %s\n", temp_order.vendorName, temp_order.customerName, temp_order.productName, temp_order.quantity, temp_order.price, temp_order.status);
			}
		fclose(inp);
		free(orders);
		fclose(outp);
	}

	return 0;
}
