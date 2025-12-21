#include <stdio.h>

int getText(char text[]);

void printMatrix(char text[], int keySize, int textSize);

void encryptText(FILE *outp, char text[], int keySize, int textSize);

int main(){

	FILE *outp;
	outp = fopen("output.txt", "w");
	char text[60];
	int textSize = getText(text), keySize;
	do{
	printf("Please enter key size (2-20): ");
	scanf("%d", &keySize);	
	} while(keySize <= 2 || keySize >= 20);
	printMatrix(text, keySize, textSize);
	encryptText(outp, text, keySize, textSize);
	fclose(outp);
	return 0;
}

int getText(char text[]){
	printf("Please enter a text (. to stop): ");
	int i = 0;
	char ch = getchar();
	while(ch != '.'){
		text[i] = ch;
		i++;
		ch = getchar();
	}
	return i - 1;
}

void printMatrix(char text[], int keySize, int textSize){
	printf("  ");
	for(int i = 1; i <= keySize; i++)
		printf("%d  ", i);
	printf("\n  ");
	for(int p = 0; p <= textSize; p++){
		printf("%c  ", text[p]);
		if((p + 1) % keySize == 0)
			printf("\n  ");
	}
}

void encryptText(FILE *outp, char text[], int keySize, int textSize){
	int i, p;
	for(i = 0; i < keySize; i++){
		for(p = i; p <= textSize; p += keySize)
			fprintf(outp, "%c", text[p]);
	}
}
