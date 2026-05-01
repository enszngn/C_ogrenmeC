#include <stdlib.h>

typedef struct supplyInFo{
	int supplyId;
	double price;
} supplyInfo_t;

typedef supplyInfo_t LType;

typedef struct node_i {
	LType data;
	struct node_i* next;
} node_t;

inline node_t* getNode() {
	node_t* node;
	node = (node_t*)malloc(sizeof(node_t));
	node->next = NULL;
	return node;
}

inline node_t* addBeginning(node_t* head, LType item) {
	node_t* temp = getNode();
	temp->data = item;
	temp->next = head;
	return temp;
}

inline void addAfter(node_t* node, LType item) {
	node_t* temp = getNode();
	temp->data = item;
	temp->next = node->next;
	node->next = temp;
}