#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "queue_struct.h"

book_info_t findMaxQueue(queue_t queue, int numberOfElements);

int main() {

	FILE* inp;
	inp = fopen("books.bin", "rb");
	if (inp == NULL)
		printf("ERROR\n");
	else {
		queue_t queue;
		initializeQ(&queue);
		book_info_t tempBook;
		book_info_t max;
		fseek(inp, 0, SEEK_END);
		int size = ftell(inp) / sizeof(book_info_t);
		rewind(inp);
		printf("There are %d records in the file!\n\n", size);
		for (int i = 0; i < size; i++) {
			fread(&tempBook, sizeof(book_info_t), 1, inp);
			insert(&queue, tempBook);
		}
		max = findMaxQueue(queue, size);
		printf("The Most Expensive Book\n");
		printf("ID: %d\n", max.id);
		printf("Title: %s\n\n", max.title);
		printf("Price: %.2f", max.price);

		fclose(inp);
	}

	return 0;
}

book_info_t findMaxQueue(queue_t queue, int numberOfElements) {
	book_info_t max = {-987654321, "", -1};
	book_info_t temp;
	for (int i = 0; i < numberOfElements; i++) {
		temp = remove(&queue);
		insert(&queue, temp);
		if (max.price < temp.price)
			max = temp;
	}
	return max;
}
