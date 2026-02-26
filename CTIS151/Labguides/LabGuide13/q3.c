#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));

    int i, num;
    int arr[15];
    printf("Randomly Generated Array:\n");
    for(i = 0; i < 15; i++){
        arr[i] = rand() % 78 + 13;
        printf("%d ", arr[i]);
    }

    FILE *outp;
    outp = fopen("output.txt", "w");
    fprintf(outp, "Adding 20 to each then ASCII Equivalent\n");
    for(i = 0; i < 15; i++)
        fprintf(outp, "%d  %c\n", arr[i] + 20, arr[i] + 20);

    return 0;
}