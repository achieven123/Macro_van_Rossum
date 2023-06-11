#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insertFirst(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));

	node->data = data;

	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}

	return head;
}

ListNode* insertLast(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));

	node->data = data;

	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}

	return head;
}

void printList(ListNode* head) {
	ListNode* p;

	if (head == NULL) return;

	p = head->link;

	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);

	printf("%d->", p->data);
}

int main() {
	ListNode* head = NULL;

	head = insertLast(head, 20);
	head = insertLast(head, 30);
	printList(head);

	return 0;
}