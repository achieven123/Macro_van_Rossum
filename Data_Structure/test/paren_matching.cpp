/*
* 괄호 검사
* 1. 왼쪽 괄호와 오른쪽 괄호의 개수가 같아야 함				-> 1, 3
* 2. 괄호 사이에는 포함 관계만 존재함						-> 2
* 3. 같은 괄호에서 왼쪽 괄호는 오른쪽 괄호보다 먼저 나와야 함	-> 2
*/

/*
3
({[(({}))]})
[{]}
)(

Good!
Retry...
Retry...
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

int check(StackType* s, char str[]) {
	for (int i = 0; str[i] != 0; i++) {
		switch (str[i]) {
		case '(': case '{': case '[':
			push(s, str[i]);
			break;
		case ')': case '}': case ']':
			if (is_empty(s)) return 1;
			char pop_value = pop(s);
			if (pop_value != '(' && str[i] == ')' ||
				pop_value != '{' && str[i] == '}' ||
				pop_value != '[' && str[i] == ']'
				) {
				return 2;
			}
			break;
		}
	}

	if (!is_empty(s)) return 3;

	return 0;
}

int main() {

	int test_case;

	scanf("%d", &test_case);

	while (test_case--) {
		char* str = (char*)malloc(sizeof(char) * 100);

		scanf("%s", str);

		StackType s;

		init_stack(&s);

		if (check(&s, str) == 0) printf("Good!\n");
		else printf("Retry...\n");
	}

	return 0;
}