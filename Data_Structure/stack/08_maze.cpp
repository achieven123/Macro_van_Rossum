#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct StackType {
	element* data;
	int capacity;
	int top;
} StackType;

void InitStack(StackType* s) {
	s->capacity = 1;
	s->top = -1;
	s->data = (element*)malloc(sizeof(element) * s->capacity);
}

int IsEmpty(StackType* s) {
	return (s->top == -1);
}

int IsFull(StackType* s) {
	return (s->top == s->capacity - 1);
}

void Push(StackType* s, element value) {
	if (IsFull(s)) {
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, sizeof(element) * s->capacity);
	}
	s->data[++(s->top)] = value;
}

element Pop(StackType* s) {
	if (IsEmpty(s)) {
		printf("스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}



int main() {
	StackType s;

	InitStack(&s);

	for (int i = 0; i < 10; i++) {
		Push(&s, i);
	}

	for (int i = 0; i < 10; i++) {
		printf("%d\n", Pop(&s));
	}

	free(s.data);

	return 0;
}