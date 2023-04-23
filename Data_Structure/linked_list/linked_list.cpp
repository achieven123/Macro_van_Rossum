#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct LinkedListNode {
	element data;
	LinkedListNode* link;
} LinkedListNode;

LinkedListNode* InsertFirstNode(LinkedListNode* head, element value) {
	LinkedListNode* p = (LinkedListNode*)malloc(sizeof(LinkedListNode));

	p->data = value;
	p->link = head;
	head = p;

	return head;
}

LinkedListNode* InsertNode(LinkedListNode* head, LinkedListNode* pre, element value) {
	LinkedListNode* p = (LinkedListNode*)malloc(sizeof(LinkedListNode));

	p->data = value;
	p->link = pre->link;
	pre->link = p;

	return head;
}

LinkedListNode* DeleteNode

int main() {
	LinkedListNode* head = NULL;



	return 0;
}