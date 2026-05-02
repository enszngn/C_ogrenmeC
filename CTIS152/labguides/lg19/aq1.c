#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stack_struct.h" 
#include "queue_int.h"

void displayStack(stack_t stack);

void displayQueue(queue_t queue);

int main() {

	FILE* inp;
	inp = fopen("courses.txt", "r");
	if (inp == NULL)
		printf("ERROR\n");
	else {
		course_t temp;
		char isBlank;
		stack_t temporary;
		stack_t pushThis;
		initializeS(&temporary);
		initializeS(&pushThis);
		queue_t prerequisites;
		initializeQ(&prerequisites);
		while (fscanf(inp, "%d %d%c", &(temp.code), &(temp.credit), &isBlank) == 3) {
			push(&temporary, temp);
			if (isBlank == '\n') {
				pushThis = temporary;
				insert(&prerequisites, pushThis);
				initializeS(&temporary);
			}
		}
		displayQueue(prerequisites);
	}

	fclose(inp);

	return 0;
}

void displayStack(stack_t stack) {
	course_t temp;
	while (!isEmptyS(&stack)) {
		temp = pop(&stack);
		printf("%d %d --> ", temp.code, temp.credit);
	}
	printf("NULL\n");
}

void displayQueue(queue_t queue) {
	printf("DISPLAY QUEUE\n");
	printf("--------------\n");
	stack_t temp;
	while (!isEmptyQ(&queue)) {
		temp = remove(&queue);
		displayStack(temp);
	}
}
