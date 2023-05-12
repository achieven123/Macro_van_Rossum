#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

#define W 119
#define S 115
#define A 97
#define D 100

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define ESC 27
#define ENTER 13

#define THICKNESS 2
#define GAP_WIDTH 6
#define GAP_HEIGHT 6
#define MAP_WIDTH 25
#define MAP_HEIGHT 25

#define SNAKE_LENGTH 5
#define START_POINT_X 12
#define START_POINT_Y 12

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

int map[MAP_HEIGHT][MAP_WIDTH] = { 0 };
int score = 0;
int max_score = 0;
int length = 0;
int speed = 150;

enum {
	BLACK,
	D_BLUE,
	D_GREEN,
	D_SKYBLUE,
	D_RED,
	D_VIOLET,
	D_YELLOW,
	GRAY,
	D_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};

void set_color(int back_color, int font_color);
void gotoxy(int x, int y);
int input_key();

void set_block(int x, int y, int color);
void delete_block(int x, int y);


void init();
void draw_window();
void draw_map();
void draw_info();

void game_start();
void init_snake();
void move_forward(int direction);
void change_dir(int direction);

void create_snake();
LinkedListNode* create_head(LinkedListNode* head, int x, int y, int dir);
LinkedListNode* create_body(LinkedListNode* head, int dir);

int main() {
	init();
	draw_window();
	draw_map();
	draw_info();

	game_start();

	return 0;
}

void set_color(int back_color, int font_color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back_color * 16 + font_color);
}

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int input_key() {
	int input = _getch();

	if (input == 224) { input = _getch(); return input; }
	else if (input == W) return UP;
	else if (input == S) return DOWN;
	else if (input == A) return LEFT;
	else if (input == D) return RIGHT;
}

void set_block(int x, int y, int color) {
	set_color(color, WHITE);
	gotoxy(GAP_WIDTH + x * 2, GAP_HEIGHT + y);
	printf("  ");
}

void delete_block(int x, int y) {
	if (map[GAP_WIDTH + x][GAP_HEIGHT + y] == 0) set_color(GREEN, WHITE);
	else set_color(D_GREEN, WHITE);
	gotoxy(GAP_WIDTH + x * 2, GAP_HEIGHT + y);
	printf("  ");
}

void init() {
	//커서 숨기기
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = FALSE;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	//윈도우 창 최대화 메시지
	system("cls");
	set_color(BLACK, WHITE);
	printf("Set the console window to full screen and press any key...");
	getch();
	system("cls");

	//맵 배열 생성
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			if ((x + y) % 2 != 0)  map[y][x] = 1;
		}
	}
}

void draw_window() {
	for (int i = 0; i < MAP_WIDTH * 2 + 4; i++) {
		set_color(D_GRAY, WHITE);
		gotoxy(GAP_WIDTH - THICKNESS + i, GAP_HEIGHT - 4);
		printf(" ");
		gotoxy(GAP_WIDTH - THICKNESS + i, GAP_HEIGHT - 3);
		printf(" ");
		gotoxy(GAP_WIDTH - THICKNESS + i, GAP_HEIGHT - 2);
		printf(" ");

		set_color(GRAY, WHITE);
		gotoxy(GAP_WIDTH - THICKNESS + i, GAP_HEIGHT - 1);
		printf(" ");
		gotoxy(GAP_WIDTH - THICKNESS + i, GAP_HEIGHT + MAP_HEIGHT);
		printf(" ");
	}

	for (int i = 0; i < MAP_HEIGHT; i++) {
		gotoxy(GAP_WIDTH - THICKNESS, GAP_HEIGHT + i);
		printf("  ");
		gotoxy(GAP_WIDTH - THICKNESS + THICKNESS + MAP_WIDTH * 2, GAP_HEIGHT + i);
		printf("  ");
	}
}

void draw_map() {
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			gotoxy(GAP_WIDTH + x * 2, GAP_HEIGHT + y);
			if (map[y][x] == 0) { set_color(GREEN, WHITE); printf(" "); }
			if (map[y][x] == 1) { set_color(D_GREEN, WHITE); printf(" "); }

			gotoxy(GAP_WIDTH + x * 2 + 1, GAP_HEIGHT + y);
			if (map[y][x] == 0) { set_color(GREEN, WHITE); printf(" "); }
			if (map[y][x] == 1) { set_color(D_GREEN, WHITE); printf(" "); }
		}
	}
}

void draw_info() {
	set_color(D_GRAY, WHITE);
	gotoxy(GAP_WIDTH, GAP_HEIGHT - 3);
	printf("SCORE %d", score);
	gotoxy(GAP_WIDTH + 35, GAP_HEIGHT - 3);
	printf("20223070 김경훈");

	int width = 60;
	int height = 16;

	set_color(BLACK, WHITE);
	gotoxy(GAP_WIDTH + width + 5, GAP_HEIGHT + height);
	printf("SNAKE GAME");

	gotoxy(GAP_WIDTH + width, GAP_HEIGHT + height + 3);
	printf("High Socre : %d", max_score);

	gotoxy(GAP_WIDTH + width, GAP_HEIGHT + height + 5);
	printf("Move Up    : W or ↑");
	gotoxy(GAP_WIDTH + width, GAP_HEIGHT + height + 6);
	printf("Move Down  : S or ↓");
	gotoxy(GAP_WIDTH + width, GAP_HEIGHT + height + 7);
	printf("Move Left  : A or ←");
	gotoxy(GAP_WIDTH + width, GAP_HEIGHT + height + 8);
	printf("Move Right : D or →");
}

void game_start() {
	LinkedListNode* head = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	init_snake();

	int dir = RIGHT;
	
	while (true) {

		if (kbhit()) {
			int input = input_key();

			if (input == ESC) break;

			if (input == UP || input == DOWN || input == LEFT || input == RIGHT) {
				if ((input != UP && dir == DOWN) || (input != DOWN && dir == UP) ||
					(input != LEFT && dir == RIGHT) || (input != RIGHT && dir == LEFT)) {
					dir = input;
					//change_dir(dir);
				}
			}
		}

		move_forward(dir);
		Sleep(speed);
	}
}

void init_snake(LinkedListNode* head) {
	head->location_x = START_POINT_X;
	head->location_y = START_POINT_Y;

	head->left_link = head;
	head->right_link = head;

	set_block(head->location_x, head->location_y, BLUE);
}

void move_forward(LinkedListNode* head, int direction) {
	LinkedListNode* new_node = (LinkedListNode*)malloc(sizeof(LinkedListNode));

	new_node->location_x = head->location_x;
	new_node->location_y = head->location_y;

	if (direction == UP) new_node->location_y--;
	if (direction == DOWN) new_node->location_y++;
	if (direction == LEFT) new_node->location_x--;
	if (direction == RIGHT) new_node->location_x++;
	
	set_block(new_node->location_x, new_node->location_y, BLUE);





	//if (direction == UP) head->location_y--;
	//if (direction == DOWN) head->location_y++;
	//if (direction == LEFT) head->location_x--;
	//if (direction == RIGHT) head->location_x++;

	//




	//delete_block(head->location_x, head->location_y);

	//if (direction == UP) head->location_y--;
	//if (direction == DOWN) head->location_y++;
	//if (direction == LEFT) head->location_x--;
	//if (direction == RIGHT) head->location_x++;

	//set_block(head->location_x, head->location_y, BLUE);
}


//void create_snake() {
//	LinkedListNode* head = NULL;
//	LinkedListNode* tail = NULL;
//
//	int x = GAP_WIDTH + START_POINT_X;
//	int y = GAP_HEIGHT + 3 + START_POINT_Y;
//	int dir = RIGHT;

//	while (true) {
//
//		if (input == UP || input == DOWN || input == LEFT || input == RIGHT) {
//			if ((input != UP && dir == DOWN) || (input != DOWN && dir == UP) ||
//				(input != LEFT && dir == RIGHT) || (input != RIGHT && dir == LEFT)) {
//				dir = input;
//
//				head = create_head(head, x, y, dir);
//
//				set_color(BLACK, WHITE);
//				gotoxy(GAP_WIDTH - 2, GAP_HEIGHT + MAP_HEIGHT + 1);
//				printf("키 입력이 정상 %d", input);
//			}
//		}
//
//		if (input == ESC) break;
//	}
//}
//
//LinkedListNode* create_head(LinkedListNode* head, int x, int y, int dir) {
//	LinkedListNode* p = (LinkedListNode*)malloc(sizeof(LinkedListNode));
//	set_color(BLACK, WHITE);
//	gotoxy(GAP_WIDTH - 2, GAP_HEIGHT + MAP_HEIGHT + 1);
//
//	p->location_x = x;
//	p->location_y = y;
//	head->link = head;
//	head = p;
//
//	length += 1;
//
//	return head;
//}
//
//LinkedListNode* create_body(LinkedListNode* head, int dir) {
//	LinkedListNode* p = (LinkedListNode*)malloc(sizeof(LinkedListNode));
//
//	SNAKE_LENGTH
//
//	printf(" %d", head->x);
//	printf(" %d", head->y);
//
//	p->link = pre->link;
//	pre->link = p;
//
//	return head;
//}
