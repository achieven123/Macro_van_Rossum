#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

#define GAP_WIDTH 6
#define GAP_HEIGHT 6
#define MAP_WIDTH 25
#define MAP_HEIGHT 25

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

typedef int element;

typedef struct LinkedListNode {
	element x;
	element y;
	int length;
	LinkedListNode* link;
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

int map[MAP_HEIGHT][MAP_WIDTH * 2] = { 0 };
int score = 0;
int max_score = 0;

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
void init();
void draw_map();
void draw_info();

int input_key();
void game_start();
void create_snake();
LinkedListNode* create_body(LinkedListNode* head, int dir);

int main() {
	init();
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

void init() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = FALSE;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	system("cls");
	set_color(BLACK, WHITE);
	printf("Set the console window to full screen and press any key...");
	getch();
	system("cls");

	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			if ((x + y) % 2 != 0) {
				map[y][x * 2] = 1;
				map[y][x * 2 + 1] = 1;
			}
		}
	}
}

void draw_map() {

	for (int i = 0; i < MAP_WIDTH * 2 + 4; i++) {
		set_color(D_GRAY, WHITE);
		gotoxy(GAP_WIDTH - 2 + i, GAP_HEIGHT - 4);
		printf(" ");
		gotoxy(GAP_WIDTH - 2 + i, GAP_HEIGHT - 3);
		printf(" ");
		gotoxy(GAP_WIDTH - 2 + i, GAP_HEIGHT - 2);
		printf(" ");

		set_color(GRAY, WHITE);
		gotoxy(GAP_WIDTH - 2 + i, GAP_HEIGHT - 1);
		printf(" ");
		gotoxy(GAP_WIDTH - 2 + i, GAP_HEIGHT + MAP_HEIGHT);
		printf(" ");
	}

	for (int i = 0; i < MAP_HEIGHT; i++) {
		gotoxy(GAP_WIDTH - 2, GAP_HEIGHT + i);
		printf("  ");
		gotoxy(GAP_WIDTH + MAP_WIDTH * 2, GAP_HEIGHT + i);
		printf("  ");
	}

	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH * 2; x++) {
			gotoxy(GAP_WIDTH + x, GAP_HEIGHT + y);
			if (map[y][x] == 0) { set_color(GREEN, WHITE); printf(" "); }
			if (map[y][x] == 1) { set_color(D_GREEN, WHITE); printf(" "); }
		}
	}

	// 디자인 확인
	/*set_color(SKYBLUE, WHITE);
	gotoxy(GAP_WIDTH + 10, GAP_HEIGHT + 10);
	printf(" ");
	gotoxy(GAP_WIDTH + 11, GAP_HEIGHT + 10);
	printf(" ");
	gotoxy(GAP_WIDTH + 12, GAP_HEIGHT + 10);
	printf(" ");
	gotoxy(GAP_WIDTH + 13, GAP_HEIGHT + 10);
	printf(" ");
	gotoxy(GAP_WIDTH + 14, GAP_HEIGHT + 10);
	printf(" ");
	gotoxy(GAP_WIDTH + 15, GAP_HEIGHT + 10);
	printf(" ");

	set_color(BLUE, WHITE);
	gotoxy(GAP_WIDTH + 16, GAP_HEIGHT + 10);
	printf(" ");
	gotoxy(GAP_WIDTH + 17, GAP_HEIGHT + 10);
	printf(" ");

	set_color(RED, WHITE);
	gotoxy(GAP_WIDTH + 22, GAP_HEIGHT + 10);
	printf(" ");
	gotoxy(GAP_WIDTH + 23, GAP_HEIGHT + 10);
	printf(" ");*/
}

void draw_info() {

	set_color(D_GRAY, WHITE);
	gotoxy(GAP_WIDTH - 2 + 2, GAP_HEIGHT - 3);
	printf("SCORE %d", score);
	gotoxy(GAP_WIDTH - 2 + 37, GAP_HEIGHT - 3);
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

int input_key() {
	int input = _getch();

	if (input == 224) { input = _getch(); return input; }
	else if (input == W) return UP;
	else if (input == S) return DOWN;
	else if (input == A) return LEFT;
	else if (input == D) return RIGHT;
}

void game_start() {
	int location_x = GAP_WIDTH + MAP_WIDTH - 5;
	int location_y = (GAP_HEIGHT + 3 + MAP_HEIGHT) / 2 + 1;

	set_color(BLUE, WHITE);
	gotoxy(location_x, location_y);
	printf(" ");
	gotoxy(location_x + 1, location_y);
	printf(" ");

	while (true) {
		if (input_key() == RIGHT) {
			set_color(BLACK, WHITE);
			gotoxy(GAP_WIDTH - 2, GAP_HEIGHT + MAP_HEIGHT + 1);
			printf("Start Game!");

			create_snake();
			break;
		}
	}
}

void create_snake() {
	LinkedListNode* head = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	head->x = GAP_WIDTH + MAP_WIDTH - 5;
	head->y = (GAP_HEIGHT + 3 + MAP_HEIGHT) / 2 + 1;

	int dir = RIGHT;

	while (true) {
		int input = input_key();

		if (input == UP || input == DOWN || input == LEFT || input == RIGHT) {
			if ((input != UP && dir == DOWN) || (input != DOWN && dir == UP) ||
				(input != LEFT && dir == RIGHT) || (input != RIGHT && dir == LEFT)) {
				dir = input;

				head = create_body(head, dir);

				set_color(BLACK, WHITE);
				gotoxy(GAP_WIDTH - 2, GAP_HEIGHT + MAP_HEIGHT + 1);
				printf("키 입력이 정상 %d", input);
			}
		}

		if (input == ESC) break;
	}
}

LinkedListNode* create_body(LinkedListNode* head, int dir) {
	LinkedListNode* p = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	printf(" %d", head->x);
	printf(" %d", head->y);


	//p->link = pre->link;
	//pre->link = p;

	return head;
}