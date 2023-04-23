#include <stdio.h>
#include <stdlib.h>

typedef char element;

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

int CheckMatching(char str[]) {
	StackType s;
	InitStack(&s);

	for (int i = 0; str[i] != NULL; i++) {
		switch (str[i]) {
		case '(':
		case '{':
		case '[':
			Push(&s, str[i]);
			break;
		case ')':
		case '}':
		case ']':
			if (IsEmpty(&s)) return 0;
			else {
				char c = Pop(&s);
				if ((c == '(' && str[i] != ')') ||
					(c == '{' && str[i] != '}') ||
					(c == '[' && str[i] != ']')) {
					return 0;
				}
				break;
			}
		}
	}

	if (!IsEmpty(&s)) return 0;
	
	free(s.data);

	return 1;
}

int main() {
	int test_case;
	scanf("%d", &test_case);

	while (test_case--) {
		char str[10];

		scanf("%s", &str);

		if (CheckMatching(str)) {
			printf("괄호 검사 성공\n");
		}
		else printf("괄호 검사 실패\n");
	}

	return 0;
}