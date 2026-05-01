#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include "linkedList_struct.h"
#define SIZE 10

int hashCode(int supplyId);

void initArray(node_t* Arr[]);

int menu();

node_t* searchSupplyId(node_t* head, int supplyId);

void insertSupply(supplyInfo_t supply, node_t* hashTable[]);

void removeSupply(int id, node_t* hashTable[]);

void display(node_t *hashTable[]);

int main() {

	int choice;
	supplyInfo_t insert;
	int deleted;
	node_t* hashTable[10];
	initArray(hashTable);
		do {
		choice = menu();
		switch (choice) {
		case 1:
			printf("\nEnter supplyId and price: ");
			scanf("%d %lf", &(insert.supplyId), &(insert.price));
			insertSupply(insert, hashTable);
			break;
		case 2:
			printf("\nEnter a supplyId to delete: ");
			scanf("%d", &deleted);
			removeSupply(deleted, hashTable);
			break;
		case 3:
			display(hashTable);
			break;
		}
		printf("\n");
	} while (choice != 4);

	return 0;
}

int hashCode(int supplyId) {
	return (supplyId % 10) - 1;
}

void initArray(node_t *Arr[]) {
	for (int i = 0; i < SIZE; i++) {
		Arr[i] = NULL;
	}
}

int menu() {
	int choice;
	printf("                MENU\n");
	printf("***********************************\n");
	printf("1. Insert a supply to the Hash Table\n");
	printf("2. Remove a supply from the Hash Table\n");
	printf("3. Display a Hash Table\n");
	printf("4. Exit\n");
	printf("Please Enter your choice: ");
	scanf("%d", &choice);
	while (choice > 4 || choice < 1) {
		printf("Please Enter your choice: ");
		scanf("%d", &choice);
	}
	return choice;
}

node_t* searchSupplyId(node_t* head, int supplyId) {
	node_t* temp = head;
	while (temp != NULL) {
		if (temp->data.supplyId == supplyId)
			return temp;
		temp = temp->next;
	}
	return temp;
}

void insertSupply(supplyInfo_t supply, node_t* hashTable[]) {
	int index = hashCode(supply.supplyId);
	if (hashTable[index] == NULL)
		hashTable[index] = addBeginning(hashTable[index], supply);
	else {
		node_t* temp = searchSupplyId(hashTable[index], supply.supplyId);
		if (temp == NULL) {
			temp = hashTable[index];
			while (temp->next != NULL)
				temp = temp->next;
			addAfter(temp, supply);
		}
		else {
			temp->data.price = supply.price;
			printf("\nThe supplyId has been already inserted, price will be updated!\n");
		}
	}
	printf("\nInserted supplyId : %d ( supplyId ) and %.2f ( price )\n", supply.supplyId, supply.price);
}

void removeSupply(int id, node_t* hashTable[]) {
	int index = hashCode(id);
	node_t* temp = hashTable[index];
	if (temp == NULL)
		printf("This supply does not exist\n");
	else {
		if (temp->data.supplyId == id) {
			hashTable[index] = temp->next;
			free(temp);
			printf("\nSupply which has an Id %d is removed.\n", id);
		}
		else {
			node_t* deletedNode = searchSupplyId(hashTable[index], id);
			if (deletedNode == NULL)
				printf("\nThis supply does not exist\n");
			else {
				temp->next = deletedNode->next;
				free(deletedNode);
				printf("\nSupply which has an Id %d is removed.\n", id);
			}
		}
	}
}

void display(node_t* hashTable[]) {
	node_t* temp;
	printf("\nHash Table Content\n");
	for (int i = 0; i < SIZE; i++) {
		temp = hashTable[i];
		printf("H[%d]: ", i);
		if (temp == NULL)
			printf("has no elements\n");
		else {
			while (temp != NULL) {
				printf("%d %6.2f -> ", temp->data.supplyId, temp->data.price);
				temp = temp->next;
			}
			printf("NULL\n");
		}
	}
}
