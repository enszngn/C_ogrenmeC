#include <stdio.h>

int isAckermann(int m, int n);

int main(){

	int m, n;
	printf("Enter the value of m: ");
	scanf("%d", &m);
	printf("Enter the value of n: ");
	scanf("%d", &n);
	if(m < 0 || n < 0)
		printf("The value of both m & n had to be positive. exiting.\n");
	else{
		int result = isAckermann(m, n);
		printf("The result is %d\n", result);
	}

	return 0;
}

int isAckermann(int m, int n){
	if(m == 0)
		return n + 1;
	else if(m > 0 && n == 0)
		return isAckermann(m - 1, 1);
	else if(m > 0 && n > 0)
		return isAckermann(m - 1, isAckermann(m, n - 1));
	return 0;
}
