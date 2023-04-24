#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListType {
	element coef;
	element exop;
	ListType* link;
} ListType;

typedef struct ListHead {
	int size;
	ListType* head;
	ListType* tail;
} ListHead;

ListHead* CreateHead() {
	ListHead* p = (ListHead*)malloc(sizeof(ListHead));
	
	p->size = 0;
	p->head = NULL;
	p->tail = NULL;

	return p;
}

void InsertNode(ListHead* p, element coef, element exop) {
	ListType* temp = (ListType*)malloc(sizeof(ListType));
	
	temp->coef = coef;
	temp->exop = exop;
	temp->link = NULL;

	if (p->tail == NULL) {
		p->head = temp;
		p->tail = temp;
	}
	else {
		p->tail->link = temp;
		p->tail = temp;
	}

	p->size++;
}

void PolyAdd(ListHead* p1,ListHead* p2, ListHead* p3) {
	ListType* a = p1->head;
	ListType* b = p2->head;
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

void PrintPoly(ListHead* p3) {
	ListType* p = p3->head;

	for (; p != NULL; p = p->link) {
		printf("%d^%d + ", p->coef, p->exop);
	} printf("\n");
}

int main() {
	ListHead* a = CreateHead();
	ListHead* b = CreateHead();
	ListHead* c = CreateHead();

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