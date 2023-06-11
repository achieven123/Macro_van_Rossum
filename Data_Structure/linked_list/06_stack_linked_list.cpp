#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;

void init(LinkedStackType* s) {
	s->top = NULL;
}

int isEmpty(LinkedStackType* s) {
	return (s->top == NULL);
}

int isFull(LinkedStackType* s) {
	return 0;
}

void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}

element pop(LinkedStackType* s) {
	if (isEmpty(s)) {
		fprintf(stderr, "스택이 비어 있음\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}

void printStack(LinkedStackType* s) {
	for (StackNode* p = s->top; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}

	printf("NULL \n");
}

int main() {
	LinkedStackType s;

	init(&s);

	push(&s, 1); printStack(&s);
	push(&s, 2); printStack(&s);
	push(&s, 3); printStack(&s);
	pop(&s); printStack(&s);
	pop(&s); printStack(&s);
	pop(&s); printStack(&s);

	return 0;
}