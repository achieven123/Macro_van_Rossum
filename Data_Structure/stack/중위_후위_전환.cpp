/*
* 중위 표기식 -> 후위 표기식 전환
* 1. 피연산자는 그대로 출력
* 2. 연산자는 자신보다 낮은 연산자를 만날 때까지 pop()하고 자신을 push()
* 3. 단, 여는 괄호는 닫는 괄호가 아니면 pop()을 하지 않음
* 4. 닫는 괄호가 나오면 여는 괄호가 나올 때까지 pop()
* 5. 마지막에 도착하면 스택에서 차례로 pop()
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

element top(StackType* s) {
	if (is_empty(s)) {
		printf("스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

void calculation(StackType* s, char str[]) {
	for (int i = 0; str[i] != 0; i++) {
		switch (str[i]) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
		case ')':
			if (is_empty(s)) push(s, str[i]);
			else if (str[i] )
			break;
		default:
			printf("%c", str[i]);
			break;
		}
	}
}

int main() {
	int test_case;

	scanf("%d", &test_case);

	while (test_case--) {
		char* str = (char*)malloc(sizeof(char) * 100);

		scanf("%s", str);

		StackType s;

		init_stack(&s);

		calculation(&s, str);

		free(str);
	}

	return 0;
}