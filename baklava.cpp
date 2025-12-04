#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	srand(time(NULL));
	int randomLetter = rand() % ('Z' - 'A') + 'A';
	printf("%c", randomLetter);

	return 0;
}
