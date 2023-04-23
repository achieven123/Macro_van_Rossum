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

LinkedListNode* DeleteFirstNode(LinkedListNode* head) {
	LinkedListNode* removed;

	if (head == NULL) return NULL;

	removed = head;
	head = removed->link;
	free(removed);

	return head;
}

LinkedListNode* DeleteNode(LinkedListNode* head, LinkedListNode* pre) {
	LinkedListNode* removed;

	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void PrintList(LinkedListNode* head) {
	/*for (LinkedListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	} printf("NULL\n");*/

	LinkedListNode* p = head;

	while (p != NULL) {
		printf("%d->", p->data);
		p = p->link;
	} printf("NULL\n");
}

LinkedListNode* ConnectList(LinkedListNode* head1, LinkedListNode* head2) {
	LinkedListNode* p = head1;

	while (p->link != NULL) {
		p = p->link;
	}

	p->link = head2;
	return head1;
}

LinkedListNode* InsertList(LinkedListNode* head1, LinkedListNode* head2, LinkedListNode* pre) {
	LinkedListNode* p = head2;

	while (p->link != NULL) {
		p = p->link;
	}

	p->link = pre->link;
	pre->link = head2;

	return head1;
}

int main() {
	LinkedListNode* head1 = NULL;
	LinkedListNode* head2 = NULL;
	
	for (int i = 0; i < 5; i++) {
		head1 = InsertFirstNode(head1, i);
		head2 = InsertFirstNode(head2, i);
	}

	//head1 = InsertList(head1, head2, head1->link);
	//head1 = ConnectList(head1, head2);

	PrintList(head1);

	return 0;
}