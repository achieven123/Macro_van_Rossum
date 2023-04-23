#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef int element;

typedef struct StackType {
	element data[MAX];
	int top;
};

void InitStack(StackType* s) {
	s->top = -1;
}

int IsEmpty(StackType* s) {
	return(s->top == -1);
}

int IsFull(StackType* s) {
	return(s->top == MAX - 1);
}

void Push(StackType* s, element value) {
	if (IsFull(s)) {
		printf("스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = value;
}

element Pop(StackType* s) {
	if (IsEmpty(s)) {
		printf("스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

int main() {
	StackType* s = (StackType*)malloc(sizeof(StackType));

	InitStack(s);

	for (int i = 0; i < 10; i++) {
		Push(s, i);
	}

	for (int i = 0; i < 10; i++) {
		printf("%d\n", Pop(s));
	}

	return 0;
}