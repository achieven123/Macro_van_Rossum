#include <stdio.h>


typedef int element;

typedef struct LinkedListNode {
	element location_x;
	element location_y;
	LinkedListNode* left_link;
	LinkedListNode* right_link;
} LinkedListNode;
//
//LinkedListNode* InsertFirstNode(LinkedListNode* head, element value) {
//	LinkedListNode* p = (LinkedListNode*)malloc(sizeof(LinkedListNode));
//
//	p->data = value;
//	p->link = head;
//	head = p;
//
//	return head;
//}

void init_snake(LinkedListNode* head, LinkedListNode* tail);
void insert_front(LinkedListNode* head, LinkedListNode* tail, int direction);
void delete_node(LinkedListNode* head, LinkedListNode* removed);

void print_list(LinkedListNode* head, LinkedListNode* tail) {
	LinkedListNode* p;

	for (p = head->right_link; p != NULL; p = p->right_link)
		printf("<-%d %d->", p->location_x, p->location_y);
	printf("\n");
}



int main() {


	return 0;
}

void game_start() {
	LinkedListNode* head = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	LinkedListNode* tail = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	init_snake(head, tail);

	int dir = RIGHT;

	while (true) {
		if (kbhit()) {
			int input = input_key();

			if (input == ESC) break;

			if (input == UP || input == DOWN || input == LEFT || input == RIGHT) {
				if ((input != UP && dir == DOWN) || (input != DOWN && dir == UP) ||
					(input != LEFT && dir == RIGHT) || (input != RIGHT && dir == LEFT)) {
					dir = input;
				}
			}
		}

		gotoxy(0, 0);
		print_list(head, tail);
		//insert_front(head, tail, dir);
		Sleep(speed);
	}
}

void init_snake(LinkedListNode* head, LinkedListNode* tail) {
	head->location_x = START_POINT_X;
	head->location_y = START_POINT_Y;
	tail->location_x = START_POINT_X - 1;
	tail->location_y = START_POINT_Y;

	head->left_link = NULL;
	head->right_link = tail;
	tail->left_link = head;
	tail->right_link = NULL;

	set_block(head->location_x, head->location_y, BLUE);
}

void insert_front(LinkedListNode* head, LinkedListNode* tail, int direction) {
	LinkedListNode* new_node = (LinkedListNode*)malloc(sizeof(LinkedListNode));

	new_node->location_x = head->location_x;
	new_node->location_y = head->location_y;

	new_node->right_link = head;
	head->left_link = new_node;
	head = new_node;

	/*new_node->left_link = head;
	new_node->right_link = head->right_link;
	head->right_link->left_link = new_node;
	head->right_link = new_node;*/

	if (direction == UP) head->location_y--;
	if (direction == DOWN) head->location_y++;
	if (direction == LEFT) head->location_x--;
	if (direction == RIGHT) head->location_x++;

	set_block(head->location_x, head->location_y, BLUE);

	//delete_node(head, tail->left_link);
}

void delete_node(LinkedListNode* head, LinkedListNode* removed) {
	//if (removed == head) return;

	//delete_block(removed->location_x, removed->location_y);

	removed->right_link->left_link = removed->left_link;
	removed->left_link->right_link = removed->right_link;

	free(removed);
}