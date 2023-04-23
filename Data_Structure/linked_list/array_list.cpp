#include <stdio.h>

#define MAX 100

typedef int element;
typedef struct {
	element array[MAX];
	int size;
} ArrayListType;

void InitArrayList(ArrayListType* L) {
	L->size = 0;
}

int IsEmpty(ArrayListType* L) {
	return (L->size == 0);
}

int IsFull(ArrayListType* L) {
	return (L->size == MAX);
}

element GetEntry(ArrayListType* L, int pos) {
	if (pos < 0 || pos >= L->size) printf("위치 오류\n");
	return L->array[pos];
}

void PrintList(ArrayListType* L) {
	for (int i = 0; i < L->size; i++) {
		printf("%d ", L->array[i]);
	} printf("\n");
}

void InsertLastNode(ArrayListType* L, element item) {
	if (L->size >= MAX) printf("리스트 오버플로우\n");
	L->array[L->size++] = item;
}

void InsertNode(ArrayListType* L, int pos, element item) {
	if (!IsFull(L) && (pos >= 0) && pos <= L->size) {
		for (int i = (L->size - 1); i >= pos; i--) {
			L->array[i + 1] = L->array[i];
		}

		L->array[pos] = item;
		L->size++;
	}
}

element DeleteNode(ArrayListType* L, int pos) {
	element item;

	if (pos < 0 || pos >= L->size) printf("위치 오류\n");

	item = L->array[pos];

	for (int i = pos; i < (L->size - 1); i++) {
		L->array[i] = L->array[i + 1];
	}

	L->size--;

	return item;
}

int main() {
	ArrayListType list;

	InitArrayList(&list);

	InsertNode(&list, 0, 10);
	PrintList(&list);
	InsertNode(&list, 0, 20);
	PrintList(&list);
	InsertNode(&list, 0, 30);
	PrintList(&list);

	return 0;
}