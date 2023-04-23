#include <stdio.h>

#define MAX 10

typedef int element;

typedef struct {
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

void EnQueue(QueueType* q, int item) {
	if (IsFull(q)) {
		printf("큐 포화 상태");
	}
	q->data[++(q->rear)] = item;
}

int DeQueue(QueueType* q) {
	if (IsEmpty(q)) {
		printf("큐 공백 상태");
	}
	
	return q->data[++(q->front)];
}

void PrintQueue(QueueType* q) {
	for (int i = 0; i < MAX; i++) {
		if (i <= q->front || i > q->rear)
			printf("   | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}

int main() {
	QueueType q;

	InitQueue(&q);

	EnQueue(&q, 10);
	EnQueue(&q, 20);
	EnQueue(&q, 30);
	
	printf("%d\n", DeQueue(&q));
	printf("%d\n", DeQueue(&q));

	return 0;
}