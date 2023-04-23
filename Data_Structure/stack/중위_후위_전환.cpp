/*
* ���� ǥ��� -> ���� ǥ��� ��ȯ
* 1. �ǿ����ڴ� �״�� ���
* 2. �����ڴ� �ڽź��� ���� �����ڸ� ���� ������ pop()�ϰ� �ڽ��� push()
* 3. ��, ���� ��ȣ�� �ݴ� ��ȣ�� �ƴϸ� pop()�� ���� ����
* 4. �ݴ� ��ȣ�� ������ ���� ��ȣ�� ���� ������ pop()
* 5. �������� �����ϸ� ���ÿ��� ���ʷ� pop()
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
		printf("���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element top(StackType* s) {
	if (is_empty(s)) {
		printf("���� ���� ����\n");
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