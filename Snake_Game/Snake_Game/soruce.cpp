#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include<time.h>

#pragma region Define Const

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27
#define SP 32

#define GAP_X 4
#define GAP_Y 2
#define MAP_WIDTH 25
#define MAP_HEIGHT 25
#define MAX_LENGTH 20
#define MAX_SPEED 100

#pragma endregion

#pragma region Enum & Struct

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
	WHITE
};

typedef int element;

typedef struct ListNode {
	element x;
	element y;
	ListNode* left;
	ListNode* right;
} ListNode;

#pragma endregion

#pragma region Function Declaration

void set_color(int back_color, int font_color);
void gotoxy(int x, int y);
int input_key();
void wait_input(int is_same);
void set_block(int x, int y, int color);
void delete_block(int x, int y);

void setup();

void init_game();

void draw_frame();
void draw_map();
void draw_info();

void game_start();
int game_over();

void init_list();
void insert_first(int dir);
void insert_end(int dir);
void delete_end();

void create_fruit();
int out_map(int x, int y);
void message_start(int x, int y, const char* message);
void message_end(int x, int y, const char* message);
#pragma endregion 

#pragma region Global Variable

int map[MAP_HEIGHT][MAP_WIDTH];
int snake[MAP_HEIGHT][MAP_WIDTH];
int fruit[MAP_HEIGHT][MAP_WIDTH];

int direction;
int speed;
int length;

int score;
int high_score;

ListNode* head;
ListNode* tail;

#pragma endregion

int main() {
	setup();
	game_start();

	return 0;
}

int input_key() {
	int input = _getch();
	if (input == 224) { input = _getch(); return input; }
	else return input;
}
void wait_input(int is_same) {
	while (true) {
		if (_kbhit()) {
			int input = input_key();
			if (input == is_same) break;
		}
	}
}

void setup() {
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
}
void gotoxy(int x, int y) {
	COORD pos = { x + GAP_X + 2, y + GAP_Y + 4 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void message_start(int font_color, const char* message) {
	set_color(BLACK, font_color);
	gotoxy(-2, MAP_HEIGHT + 2);
	printf("%s", message);
	set_color(BLACK, WHITE);
}

void message_end() {
	gotoxy(-2, MAP_HEIGHT + 2);
	for (int y = 0; y < 50; y++) printf(" ");
}

void set_color(int back_color, int font_color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back_color * 16 + font_color);
}

void set_block(int x, int y, int color) {
	set_color(color, WHITE);
	gotoxy(x * 2, +y);
	printf("  ");
	set_color(BLACK, WHITE);
}
void delete_block(int x, int y) {
	if (map[x][y] == 0) set_block(x, y, GREEN);
	else set_block(x, y, D_GREEN);
}

void draw_map() {
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			delete_block(x, y);
		}
	}
}
void draw_frame() {
	for (int x = -1, y = -4; x < MAP_WIDTH + 1; x++) {
		set_block(x, y, D_GRAY);
		set_block(x, y + 1, D_GRAY);
		set_block(x, y + 2, D_GRAY);
		set_block(x, y + 3, GRAY);
		set_block(x, y + MAP_HEIGHT + 4, GRAY);
	}

	for (int x = -1, y = 0; y < MAP_HEIGHT; y++) {
		set_block(x, y, GRAY);
		set_block(x + MAP_WIDTH + 1, y, GRAY);
	}
}
void draw_info() {
	int x = 0;
	int y = -3;

	set_color(D_GRAY, WHITE);
	gotoxy(x, y); printf("score %d", score);
	gotoxy(x + MAP_WIDTH * 2 - 15, y); printf("20223070 김경훈");

	x = MAP_WIDTH * 2 + 6;
	y = MAP_HEIGHT - 5;

	set_color(BLACK, WHITE);
	gotoxy(x, y + 0); printf("High Socre : %d", high_score);
	gotoxy(x, y + 1); printf("Speed      : %d", speed);
	gotoxy(x, y + 3); printf("Snake Move :  ←, →, ↑, ↓");
	gotoxy(x, y + 4); printf("Game Stop  :  ESC");
}
void create_fruit() {
	while (true) {
		int x = rand() % MAP_WIDTH;
		int y = rand() % MAP_HEIGHT;

		if (snake[y][x] == 1 || snake[y][x] == 2) continue;
		else {
			fruit[y][x] = 1;
			set_block(x, y, RED);
			break;
		}
	}
}

void init_list() {
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));

	new_node->x = MAP_WIDTH / 2;
	new_node->y = MAP_HEIGHT / 2;
	new_node->left = NULL;
	new_node->right = NULL;

	head = new_node;
	tail = new_node;

	set_block(head->x, head->y, BLUE);
}

void insert_first(int dir) {
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));

	new_node->x = head->x;
	new_node->y = head->y;

	if (dir == UP) new_node->y--;
	if (dir == DOWN) new_node->y++;
	if (dir == LEFT) new_node->x--;
	if (dir == RIGHT) new_node->x++;

	new_node->left = NULL;
	new_node->right = head;
	head->left = new_node;
	head = new_node;

	set_block(head->x, head->y, BLUE);
	set_block(head->right->x, head->right->y, SKYBLUE);
	if (snake[head->y][head->x] == 0) snake[head->y][head->x] = 2;
	snake[head->right->y][head->right->x] = 1;
}

void insert_end(int dir) {
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));

	new_node->x = tail->x;
	new_node->y = tail->y;

	if (dir == UP) new_node->y++;
	if (dir == DOWN) new_node->y--;
	if (dir == LEFT) new_node->x++;
	if (dir == RIGHT) new_node->x--;

	new_node->left = tail;
	new_node->right = NULL;
	tail->right = new_node;
	tail = new_node;

	length++;
	set_block(tail->x, tail->y, SKYBLUE);
	snake[tail->y][tail->x] = 1;
}

void delete_end() {
	ListNode* removed;

	delete_block(tail->x, tail->y);

	removed = tail;
	removed->left->right = NULL;
	tail = removed->left;

	snake[removed->y][removed->x] = 0;

	free(removed);
}

int out_map(int x, int y) {
	if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT) return 1;
	else return 0;
}

void init_game() {
	srand(time(NULL));

	head = NULL;
	tail = NULL;

	direction = RIGHT;
	speed = 10;
	length = 0;
	score = 0;

	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			if ((x + y) % 2 != 0) map[y][x] = 1;
			snake[y][x] = 0;
			fruit[y][x] = 0;
		}
	}

	draw_map();
	draw_frame();
	draw_info();
	create_fruit();

	init_list();
	insert_end(direction);
	insert_end(direction);
	insert_end(direction);

	message_start(GREEN, "press 's' to srart");
	wait_input('s');
	message_end();
}

void game_start() {
	init_game();

	while (true) {
		if (_kbhit()) {
			int input = input_key();

			switch (input) {
			case UP:
			case DOWN:
			case LEFT:
			case RIGHT:
				if ((input != UP && direction == DOWN) ||
					(input != DOWN && direction == UP) ||
					(input != LEFT && direction == RIGHT) ||
					(input != RIGHT && direction == LEFT)) {
					direction = input;
				}
				break;

			case ESC:
				message_start(GREEN, "press 'ESC' to continue . . .");
				wait_input(ESC);
				message_end();
				break;
			}
		}

		insert_first(direction);

		if (fruit[head->y][head->x] == 1) {
			fruit[head->y][head->x] = 0;

			score += 100;
			if (length < MAX_LENGTH) length++;
			else delete_end();

			if (score % 900 == 0 && score != 0 && speed < MAX_SPEED) speed += 10;
			if (score > high_score) high_score = score;

			create_fruit();
			draw_info();
		}
		else {
			delete_end();
		}

		if (out_map(head->x, head->y) || snake[head->y][head->x] == 1) {
			draw_frame();
			draw_info();
			if (game_over()) init_game();
			else break;
		}

		Sleep(MAX_SPEED - speed);
	}
}

int game_over() {

	for (int i = 0; i < 3; i++) {
		message_start(RED, "Game Over!");
		Sleep(300);
		message_end();
		Sleep(300);
	}

	message_start(GREEN, "Play Again? [y/n]");

	while (true) {
		if (_kbhit()) {
			int input = input_key();
			if (input == 'y') return 1;
			if (input == 'n') return 0;
		}
	}
}