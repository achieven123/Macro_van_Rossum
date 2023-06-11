#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DListNode {
	element data;
	struct DListNode* lLink;
	struct DListNode* rLink;
} DListNode;

void init(DListNode* phead) {
	phead->lLink = phead;
	phead->rLink = phead;
}

void printList(DListNode* phead) {
	DListNode* p;

	for (p = phead->rLink; p != phead; p = p->rLink) {
		printf("<-| |%d| |-> ", p->data);
	}

	printf("\n");
}

void insertNode(DListNode* before, element data) {
	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
	node->data = data;

	node->lLink = before;
	node->rLink = before->rLink;
	before->rLink->lLink = node;
	before->rLink = node;
}

void deleteNode(DListNode* head, DListNode* removed) {
	if (removed == head) return;

	removed->lLink->rLink = removed->rLink;
	removed->rLink->lLink = removed->lLink;

	free(removed);
}

int main() {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));

	init(head);

	for (int i = 0; i < 5; i++) {
		insertNode(head, i);
		printList(head);
	}

	for (int i = 0; i < 5; i++) {
		printList(head);
		deleteNode(head, head->rLink);
	}

	free(head);

	return 0;
}