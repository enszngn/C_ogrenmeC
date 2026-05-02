#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "linkedList_string.h"

node_t* searchPos(node_t *head, char string[]);

void displayList(node_t* head);

node_t* createList(FILE* inp);

int removeWord(node_t** head, char word[]);

int main() {

	FILE* inp;
	inp = fopen("words.txt", "r");
	if (inp == NULL)
		printf("ERROR\n");
	else {
		char word[30];
		node_t* head = createList(inp);
		printf("\nEnter a word to delete: ");
		scanf("%s", word);
		removeWord(&head, word);
		displayList(head);
	}

	fclose(inp);

	return 0;
}

node_t* searchPos(node_t* head, char string[]) {
	if (head == NULL || strcmp(head->data, string) > 0)
		return NULL;
	while (head->next != NULL) {
		if (strcmp(head->next->data, string) > 0)
			return head;
		head = head->next;
	}
	return head;
}

void displayList(node_t* head) {
	node_t* temp = head;
	while (temp != NULL) {
		printf("%s -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

node_t* createList(FILE* inp) {
	node_t* head = NULL;
	node_t* pos;
	char string[30];
	while (fscanf(inp, "%s", string) == 1) {
		pos = searchPos(head, string);
		if (pos == NULL)
			head = addBeginning(head, string);
		else {
			addAfter(pos, string);
		}
		displayList(head);
	}
	
	return head;
}

int removeWord(node_t** head, char word[]) {
	int isSuccessful = 0;
	if (*head == NULL) {
		printf("The list is empty");
		return 0;
	}

	int wordLen = strlen(word);
	node_t* deleted;
	while (*head != NULL && strncmp((*head)->data, word, wordLen) == 0) { //delete the first words that have the string
		deleted = *head;
		*head = (*head)->next;
		free(deleted);
		isSuccessful = 1;
	}

	node_t* temp = *head;
	while (temp != NULL && temp->next != NULL) {
		if (strncmp(temp->next->data, word, wordLen) == 0) {
			deleted = temp->next;
			temp->next = deleted->next;
			free(deleted);
			isSuccessful = 1;
		}
		else
			temp = temp->next;
	}

	return isSuccessful;
}
