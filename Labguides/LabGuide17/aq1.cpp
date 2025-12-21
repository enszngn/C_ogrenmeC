#include <stdio.h>

int menu();

void listStockInfo(int stockInformation[][20], int rows);

int searchProduct(int stockInformation[][20], int rows, int productID);

void buyProduct(FILE *outp, int stockInformation[][20], int rows, int productID, int quantity, int *sumOfPayments);

int main(){

    FILE *inp;
    inp = fopen("company.txt", "r");
    if(inp == NULL)
        printf("ERROR");
    else{
        FILE *outp;
        outp = fopen("shopping.txt", "w");
        int stockInformation[3][20];
        int status, i = 0;
        int choice;
        int totalPrice = 0;
        int productID, quantity;
        status = fscanf(inp, "%d %d %d", &stockInformation[0][i],&stockInformation[1][i], &stockInformation[2][i]);
        while(status != EOF){
            i++;
            status = fscanf(inp, "%d %d %d", &stockInformation[0][i],&stockInformation[1][i], &stockInformation[2][i]);
        }
        fprintf(outp, "ID      PRICE  QUANTITY  PAYMENT\n");
        fprintf(outp, "------  -----  --------  -------\n");
        do{
            choice = menu();
            switch (choice) {
            case 1:
              listStockInfo(stockInformation, i);
              break;
            case 2:
              printf("\nEnter the productID: ");
              scanf("%d", &productID);
              while ((searchProduct(stockInformation, i, productID)) == -1) {
                printf("\nWrong product number\n");
                printf("\nEnter the productID: ");
                scanf("%d", &productID);
              }
              if (stockInformation[2][searchProduct(stockInformation, i,
                                                    productID)] == 0)
                printf("SORRY! The product is out of stock\n");
              else {
                printf("Enter the quantity: ");
                scanf("%d", &quantity);
                while (stockInformation[2][searchProduct(
                           stockInformation, i, productID)] < quantity) {
                  printf("\nThere are %d product in the stock\n",
                         stockInformation[2][searchProduct(stockInformation, i,
                                                           productID)]);
                  printf("Re-enter the quantity: ");
                  scanf("%d", &quantity);
                }
                buyProduct(outp, stockInformation, i, productID, quantity,
                           &totalPrice);
              }
              break;
            case 3:
              listStockInfo(stockInformation, i);
            }
        } while (choice != 3);
        fclose(inp);
        fclose(outp);
    }

    return 0;
}

int menu() {
  int choice;
  printf("\nMENU\n");
  printf("1. List Stock Info\n");
  printf("2. Buy a product\n");
  printf("3. Exit\n");
  do {
    printf("Enter choice: ");
    scanf("%d", &choice);
  } while (choice < 1 || choice > 3);
  return choice;
}

void listStockInfo(int stockInformation[][20], int rows){
    printf("    ID Price Stock\n");
    printf("------ ----- -----\n");
    for(int i = 0; i < rows; i++)
        printf("%6d %5d %5d\n", stockInformation[0][i], stockInformation[1][i], stockInformation[2][i]);
}

int searchProduct(int stockInformation[][20], int rows, int productID){
    for(int i = 0; i < rows; i++){
        if(stockInformation[0][i] == productID)
            return i;
    }
    return -1;
}

void buyProduct(FILE *outp, int stockInformation[][20], int rows, int productID, int quantity, int *sumOfPayments){
    int price = stockInformation[0][searchProduct(stockInformation, rows, productID)];
    fprintf(outp, "%6d  %3d  %8d  %7d\n", productID, price, quantity, price * quantity);
    *sumOfPayments += price * quantity;
    stockInformation[2][searchProduct(stockInformation, rows, productID)] -= quantity;
}