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
		printf("���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element Top(StackType* s) {
	if (IsEmpty(s)) {
		printf("���� ���� ����");
		exit(1);
	}
	else return s->data[s->top];
}

int Priority(char c) {
	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/') return 2;
	return 0;
}

void InfixToPostfix(char str[]) {
	StackType s;

	InitStack(&s);

	for (int i = 0; str[i] != NULL; i++) {
		//1. �ǿ����ڴ� ���
		if (str[i] >= '1' && str[i] <= '9') {
			printf("%c", str[i]);
			continue;
		}

		//2. ������ ����ִ� ��� �Ǵ� '('�� ��� push
		if (IsEmpty(&s) || str[i] == '(') {
			Push(&s, str[i]);
			continue;
		}

		//3. ')'�� ��� '(' ���� ������ ���
		if (str[i] == ')') {
			while (Top(&s) != '(') {
				printf("%c", Pop(&s));
			}

			continue;
		}

		//4. top���� �켱���� ũ�� push
		if (Priority(Top(&s)) < Priority(str[i])) {
			Push(&s, str[i]);
		}

		//5. top���� �켱���� �۰ų� ������ pop �� �ݺ�
		else {
			while (!IsEmpty(&s) && Priority(Top(&s)) >= Priority(str[i])) {
				printf("%c", Pop(&s));
			}

			Push(&s, str[i]);
		}
	}

	while (!IsEmpty(&s)) {
		printf("%c", Pop(&s));
	}

	printf("\n");
}

int main() {
	int test_case;
	scanf("%d", &test_case);

	while (test_case--) {
		char str[10];

		scanf("%s", &str);

		InfixToPostfix(str);
	}

	return 0;
}