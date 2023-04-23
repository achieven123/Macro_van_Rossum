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

element Top(StackType* s) {
	if (IsEmpty(s)) {
		printf("스택 공백 에러");
		exit(1);
	}
	else return s->data[s->top];
}

int Calculate(char str[]) {
	StackType s;

	InitStack(&s);

	for (int i = 0; str[i] != NULL; i++) {
		int a, b, c = 0;

		switch (str[i]) {
		case '+':
		case '-':
		case '*':
		case '/':
			b = Pop(&s);
			a = Pop(&s);

			if (str[i] == '+') c = a + b;
			if (str[i] == '-') c = a - b;
			if (str[i] == '*') c = a * b;
			if (str[i] == '/') c = a / b;

			Push(&s, c);
			break;
		
		default:
			Push(&s, str[i] - '0');
			break;
		}
	}

	int res = Pop(&s);

	if (!IsEmpty(&s)) exit(1);
	else return res;
}

int main() {
	int test_case;
	scanf("%d", &test_case);

	while (test_case--) {
		char str[10];

		scanf("%s", &str);

		printf("%d\n", Calculate(str));
	}

	return 0;
}