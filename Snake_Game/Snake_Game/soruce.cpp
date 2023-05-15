#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

#pragma region Key Input

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define W 119
#define S 115
#define A 97
#define D 100

#define ESC 27
#define ENTER 13

#pragma endregion

#pragma region Map Size

#define GAP_X 4
#define GAP_Y 2
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

#pragma endregion

#pragma region Function Prototype

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

typedef struct LinkedListNode {
	element x;
	element y;
	LinkedListNode* left;
	LinkedListNode* right;
} LinkedListNode;

#pragma endregion

int map[MAX_HEIGHT][MAX_WIDTH];
int snake[MAX_HEIGHT][MAX_WIDTH];
int map_width = 25;
int map_height = 25;
int current_score;
int max_score;
int speed;

int main() {
	init();
	draw_window();
	draw_map();
	draw_info();
	gotoxy(0, 0);
	printf("¾È´¨");
	//game_start();(
	_getch();
	return 0;
}

void set_color(int back_color, int font_color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back_color * 16 + font_color);
}

void gotoxy(int x, int y) {
	COORD pos = { x + GAP_X + 2, y + GAP_Y + 4 };
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
	gotoxy(x * 2, +y);
	printf("  ");
	set_color(BLACK, WHITE);
}

void delete_block(int x, int y) {
	if (map[x][y] == 0) set_block(x, y, GREEN);
	else set_block(x, y, D_GREEN);
}

void init() {
	//Ä¿¼­ ¼û±â±â
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = FALSE;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	//À©µµ¿ì Ã¢ ÃÖ´ëÈ­ ¸Þ½ÃÁö
	system("cls");
	set_color(BLACK, WHITE);
	printf("Set the console window to full screen and press any key...");
	getch();
	system("cls");

	//¸Ê ¹è¿­ »ý¼º
	for (int y = 0; y < MAX_HEIGHT; y++) {
		for (int x = 0; x < MAX_WIDTH; x++) {
			if ((x + y) % 2 != 0)  map[y][x] = 1;
		}
	}
}

void draw_window() {
	for (int x = -1, y = -4; x < map_width + 1; x++) {
		set_block(x, y, D_GRAY);
		set_block(x, y + 1, D_GRAY);
		set_block(x, y + 2, D_GRAY);
		set_block(x, y + 3, GRAY);
		set_block(x, y + map_height + 4, GRAY);
	}

	for (int x = -1, y = 0; y < map_height; y++) {
		set_block(x, y, GRAY);
		set_block(x + map_width + 1, y, GRAY);
	}
}

void draw_map() {
	for (int y = 0; y < map_height; y++) {
		for (int x = 0; x < map_width; x++) {
			delete_block(x, y);
		}
	}
}

void draw_info() {
	int x = 0;
	int y = -3;

	set_color(D_GRAY, WHITE);
	gotoxy(x, y); printf("score %d", current_score);
	gotoxy(x + map_width * 2 - 15, y); printf("20223070 ±è°æÈÆ");

	x = map_width * 2 + 6;
	y = map_height - 6;

	set_color(BLACK, WHITE);
	gotoxy(x, y); printf("High Socre : %d", max_score);
	gotoxy(x, y + 2); printf("Move Up    : W or ¡è");
	gotoxy(x, y + 3); printf("Move Down  : S or ¡é");
	gotoxy(x, y + 4); printf("Move Left  : A or ¡ç");
	gotoxy(x, y + 5); printf("Move Right : D or ¡æ");
}