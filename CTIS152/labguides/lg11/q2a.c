#include <stdio.h>

int countChar(char string[], char searched){
	char small;
	if(searched > 'Z')
		small = searched - 'a' + 'A';
	else
		small = searched + 'a' - 'A';
	printf("%c\n", small);
	if(*string == '\0')
		return 0;
	else if(*string == searched || *string == small)
		return 1 + countChar(string + 1, searched);
	return countChar(string + 1, searched);
}

int main(){

	char string[100];
	printf("Enter a string: ");
	scanf("%[^\n]", string);
	int count = countChar(string, 'e');
	printf("The number of '%c' is %d\n", 'e', count);

	return 0;
}
