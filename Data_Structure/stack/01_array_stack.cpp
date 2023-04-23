#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef int element;

element stack[MAX];
int top = -1;

void InitStack() {
	top = -1;
}

int IsEmpty() {
	return (top == -1);
}

int IsFull() {
	return (top == MAX - 1);
}

void Push(element value) {
	if (IsFull()) {
		printf("스택 포화 에러\n");
		return;
	}
	else stack[++top] = value;
}

element Pop() {
	if (IsEmpty()) {
		printf("스택 공백 에러\n");
		exit(1);
	}
	else return stack[top--];
}

int main() {
	InitStack();

	for (int i = 0; i < 10; i++) {
		Push(i);
	}

	for (int i = 0; i < 10; i++) {
		printf("%d\n", Pop());
	}

	return 0;
}