#include <stdio.h>
#include <math.h>

int isEvilNumber(int num);

int main(){

	printf("%d\n", isEvilNumber(9));

	return 0;
}

int isEvilNumber(int num){
	int binaryNum = 0;
	for(int i = 0; num > 0; i++){
		binaryNum += num % 2 * pow(10, i);
		num -= pow(2, i);
	}

	return binaryNum;
} 
