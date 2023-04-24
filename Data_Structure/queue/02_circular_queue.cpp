#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef int element;

typedef struct QueueType{
	int front;
	int rear;
	element data[MAX];
} QueueType;

void InitQueue(QueueType* q) {
	q->front = 0;
	q->rear = 0;
}

int IsEmpty(QueueType* q) {
	return (q->rear == q->front);
}

int IsFull(QueueType* q) {
	return ((q->rear + 1) % MAX == q->front);
}

void EnQueue(QueueType* q, element value) {
	if (IsFull(q)) {
		printf("큐 포화 에러\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX;
	q->data[q->rear] = value;
}

element DeQueue(QueueType* q) {
	if (IsEmpty(q)) {
		printf("큐 공백 에러\n");
		exit(1);
	}
	q->front = (q->front + 1) % MAX;
	return q->data[q->front];
}

void PrintQueue(QueueType* q) {
	if (!IsEmpty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX);
			printf("%d | ", q->data[i]);
			if (i == q->rear) break;
		} while (i != q->front);
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