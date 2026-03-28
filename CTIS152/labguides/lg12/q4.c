#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char vendorName[20];
	char customerName[20];
	char productName[25];
	int quantity;
	double price;
	char status[15];
} order_t;

void binSearch(FILE *inp, char name[]);

int main(){

	FILE *inp;
	inp = fopen("orders.bin", "rb");
	if(inp == NULL)
		printf("ERROR\n");
	else{
		char searched[40];
		printf("Enter a customer name to search (END to stop): ");
		scanf("%[^\n]", searched);
		while(strcmp(searched, "END")){
			binSearch(inp, searched);
			printf("Enter a customer name to search (END to stop): ");
			scanf(" %[^\n]", searched);
		}
		
		fclose(inp);
	}

	return 0;
}

void binSearch(FILE *inp, char name[]){
	int bottom, top = 0, middle;
	order_t temp_order;
	fseek(inp, 0, SEEK_END);
	bottom = ftell(inp) / sizeof(order_t);
	rewind(inp);
	int compare;
	while(top <= bottom && compare != 0){
		middle = (bottom - top) / 2;
		fseek(inp, middle, SEEK_SET);
		fread(&temp_order, sizeof(order_t), 1, inp);
		compare = strcmp(temp_order.customerName, name);
		if(compare == 0){
			printf("BINARY FILE CONTENT\n");
			printf("*******************\n\n");
			printf("Vendor           Customer        Product          Quantity   Price      Status\n");
			printf("------------------------------------------------------------------------------\n");
			printf("%-12s     %-15s     %-17s      %2d       $%6.2f    %s\n\n", temp_order.vendorName, temp_order.customerName, temp_order.productName, temp_order.quantity, temp_order.price, temp_order.status);
		}
		else if(compare < 0){
			top = middle + 1;
		}
		else{
			bottom = middle - 1;
		}
	}
}
