#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product{
	char name[30];
	double unit_price;
	int quantity;
} product_t;

void read_from_file(FILE *inp, product_t products[], int product_count);

void display(product_t products[], int product_count);

int main(){

	FILE *inp;
	inp = fopen("products.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		int product_count;
		int product_number;
		double money;
		fscanf(inp, "%d", &product_count);
		product_t *products;
		products = (product_t *)malloc(sizeof(product_t) * product_count);
		read_from_file(inp, products, product_count);
		display(products, product_count);
		printf("\nEnter the product number to purchase (-1 to stop): ");
		scanf("%d", &product_number);
		while(product_number != -1){
			if((products + product_number - 1)->quantity != 0){
				printf("Insert the money: ");
				scanf("%lf", &money);
				if(money < (products + product_number - 1)->unit_price){
					printf("Your money is not enough, and returned back\n");
					display(products, product_count);
				}
				else{
					printf("%.2f TL returned back\n", money - (products + product_number - 1)->unit_price);
					((products + product_number - 1)->quantity)--;
					display(products, product_count);
				}
			}
			else{
				printf("There is no more %s left\n", (products + product_number - 1)->name);
				display(products, product_count);
			}
			printf("\nEnter the product number to purchase (-1 to stop): ");
			scanf("%d", &product_number);
		}
		free(products);
		fclose(inp);
	}

	return 0;
}

void read_from_file(FILE *inp, product_t products[], int product_count){
	for(int i = 0; i < product_count; i++){
		fscanf(inp, " %[^0-9] %lf %d", (products + i)->name, &(products + i)->unit_price, &(products + i)->quantity);
	}
}

void display(product_t products[], int product_count){
	printf("   PRODUCT       UNIT PRICE QUANTITY\n");
	for(int i = 0; i < product_count; i++){
		printf("%d. %-15s   %.2f       ", i + 1, (products + i)->name, (products + i)->unit_price);
		if((products + i)->quantity == 0)
			printf("%3s\n", "OUT");
		else
			printf("%3d\n", (products + i)->quantity);
	}
}
