/*
* 후위표기식
* 수식을 왼쪽에서 오른쪽으로 스캔하면서 피연산자이면 스택에 저장하고,
* 연산자이면 스택에서 두개를 꺼내 연산하고 결과를 스택에 저장함
*/

#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct {
	element* data;
	int capacity;
	int top;
} StackType;

void init_stack(StackType* s) {
	s->capacity = 1;
	s->top = -1;
	s->data = (element*)malloc(sizeof(element));
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == s->capacity - 1);
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, sizeof(element) * s->capacity);
	}
	s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		printf("스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

int calculation(StackType* s, char str[]) {
	int a, b, c = -1;
	int result;

	for (int i = 0; str[i] != 0; i++) {
		switch (str[i]) {
		case '+':
		case '-':
		case '*':
		case '/':
			b = pop(s);
			a = pop(s);
			if (str[i] == '+') c = (a + b);
			if (str[i] == '-') c = (a - b);
			if (str[i] == '*') c = (a * b);
			if (str[i] == '/') c = (a / b);
			push(s, c);
			break;
		default:
			push(s, str[i] - '0');
			break;
		}
	}

	result = pop(s);

	if (is_empty(s)) return result;
	else return -1;
}

int main() {
	int test_case;

	scanf("%d", &test_case);

	while (test_case--) {
		char* str = (char*)malloc(sizeof(char) * 100);

		scanf("%s", str);

		StackType s;

		init_stack(&s);

		int result = calculation(&s, str);

		printf("%d\n", result);

		free(str);
	}

	return 0;
}