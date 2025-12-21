#include <stdio.h>

void swap(int *num1, int *num2);

int main(){

    int num, i;
    printf("Enter the number of elements: ");
    scanf("%d", &num);
    while(num % 2 != 0 || num <= 0){
        printf("The number of elements should be EVEN and POSITIVE.\n\n");
        printf("Enter the number of elements: ");
        scanf("%d", &num);
    }
    int arr[100];
    for(i = 0; i < num; i++){
        printf("Enter elements on index [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < num; i += 2){
        swap(&arr[i], &arr[i + 1]);
    }
    printf("\nArray elements after changing adjacent elements:\n");
    for(i = 0; i < num; i++)
        printf("%d ", arr[i]);

    return 0;
}

void swap(int *num1, int *num2){
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
