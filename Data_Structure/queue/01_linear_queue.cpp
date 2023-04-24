#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef int element;

typedef struct QueueType {
	int front;
	int rear;
	element data[MAX];
} QueueType;

void InitQueue(QueueType* q) {
	q->front = -1;
	q->rear = -1;
}

int IsEmpty(QueueType* q) {
	return (q->front == q->rear);
}

int IsFull(QueueType* q) {
	return (q->rear == MAX - 1);
}

void EnQueue(QueueType* q, element value) {
	if (IsFull(q)) {
		printf("큐 포화 에러\n");
		return;
	}
	q->data[++(q->rear)] = value;
}

element DeQueue(QueueType* q) {
	if (IsEmpty(q)) {
		printf("큐 공백 에러\n");
		exit(1);
	}
	return q->data[++(q->front)];
}

void PrintQueue(QueueType* q) {
	for (int i = 0; i < MAX; i++) {
		if (i <= q->front || i > q->rear) {
			printf("   | ");
		}
		else {
			printf("%d | ", q->data[i]);
		}
	}

	printf("\n");
}

int main() {
	QueueType q;

	InitQueue(&q);

	EnQueue(&q, 10);
	EnQueue(&q, 20);
	EnQueue(&q, 30);

	PrintQueue(&q);

	DeQueue(&q);
	DeQueue(&q);
	DeQueue(&q);

	PrintQueue(&q);

	return 0;
}