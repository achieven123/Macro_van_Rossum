#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct LinkedListNode {
	element coef;
	element exop;
	LinkedListNode* link;
} LinkedListNode;

typedef struct LinkedListHead {
	int size;
	LinkedListNode* head;
	LinkedListNode* tail;
} LinkedListHead;

LinkedListHead* CreateHead() {
	LinkedListHead* p = (LinkedListHead*)malloc(sizeof(LinkedListHead));

	p->size = 0;
	p->head = p->tail = NULL;

	return p;
}

void InsertNode(LinkedListHead* p, element coef, element exop) {
	LinkedListNode* temp = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	temp->coef = coef;
	temp->exop = exop;
	temp->link = NULL;

	if (p->tail == NULL) {
		p->head = p->tail = temp;
	}
	else {
		p->tail->link = temp;
		p->tail = temp;
	}

	p->size++;
}

void PolyAdd(LinkedListHead* p1, LinkedListHead* p2, LinkedListHead* p3) {
	LinkedListNode* a = p1->head;
	LinkedListNode* b = p2->head;
	int sum;

	while (a && b) {
		if (a->exop == b->exop) {
			sum = a->coef + b->coef;
			
			if (sum != 0) InsertNode(p3, sum, a->exop);
			a = a->link; b = b->link;
		}
		else if (a->exop > b->exop) {
			InsertNode(p3, a->coef, a->exop);
			a = a->link;
		}
		else {
			InsertNode(p3, b->coef, b->exop);
			b = b->link;
		}

	}
		for (; a != NULL; a = a->link) InsertNode(p3, a->coef, a->exop);
		for (; b != NULL; b = b->link) InsertNode(p3, b->coef, b->exop);
}

void PrintPoly(LinkedListHead* p3) {
	LinkedListNode* p = p3->head;

	for (; p != NULL; p = p->link) {
		printf("%d^%d + ", p->coef, p->exop);
	} printf("\n");
}

int main() {
	LinkedListHead* a = CreateHead();
	LinkedListHead* b = CreateHead();
	LinkedListHead* c = CreateHead();

	InsertNode(a, 1, 5);
	InsertNode(a, 1, 4);
	InsertNode(a, 1, 3);
	InsertNode(a, 1, 2);

	InsertNode(b, 1, 5);
	InsertNode(b, 1, 4);
	
	PolyAdd(a, b, c);

	PrintPoly(a);
	PrintPoly(b);
	PrintPoly(c);

	return 0;
}