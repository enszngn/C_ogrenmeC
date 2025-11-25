#include <stdio.h>

int main(){

	FILE *inp;
	inp = fopen("sales.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		double purchasePrice[20], salePrice[20], totalProfit = 0;
		int status, i = 0;
		status = fscanf(inp, "%lf %lf", &purchasePrice[i], &salePrice[i]);
		while(status != EOF){
			i++;
			status = fscanf(inp, "%lf %lf", &purchasePrice[i], &salePrice[i]);
		}
		printf("Purchase  Sale    Profit\n");
		printf("--------  ------  ------\n");
		for(int p = 0; p < i; p++){
			printf("%8.2f  %6.2f  %6.2f\n", purchasePrice[p], salePrice[p], salePrice[p] - purchasePrice[p]);
			totalProfit +=  salePrice[p] - purchasePrice[p];
		}
		printf("\n\nTotal Profit is: %.2f", totalProfit);
		fclose(inp);
	}

	return 0;
}
