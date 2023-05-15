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

#pragma region Draw Map

#define GAP_X 3
#define GAP_Y 3
#define MAP_WIDTH 25
#define MAP_HEIGHT 25

#pragma endregion 

#define SNAKE_LENGTH 5
#define START_POINT_X 12
#define START_POINT_Y 12

int map[MAP_HEIGHT][MAP_WIDTH] = { 0 };
int score = 0;
int max_score = 0;
int length = 0;
int speed = 500;

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
	gotoxy(GAP_X + x * 2, GAP_Y + y);
	printf("  ");
}

void delete_block(int x, int y) {
	if (map[GAP_X + x][GAP_Y + y] == 0) set_color(GREEN, WHITE);
	else set_color(D_GREEN, WHITE);
	gotoxy(GAP_X + x * 2, GAP_Y + y);
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
		gotoxy(GAP_X - THICKNESS + i, GAP_Y - 4);
		printf(" ");
		gotoxy(GAP_X - THICKNESS + i, GAP_Y - 3);
		printf(" ");
		gotoxy(GAP_X - THICKNESS + i, GAP_Y - 2);
		printf(" ");

		set_color(GRAY, WHITE);
		gotoxy(GAP_X - THICKNESS + i, GAP_Y - 1);
		printf(" ");
		gotoxy(GAP_X - THICKNESS + i, GAP_Y + MAP_HEIGHT);
		printf(" ");
	}

	for (int i = 0; i < MAP_HEIGHT; i++) {
		gotoxy(GAP_X - THICKNESS, GAP_Y + i);
		printf("  ");
		gotoxy(GAP_X - THICKNESS + THICKNESS + MAP_WIDTH * 2, GAP_Y + i);
		printf("  ");
	}
}

void draw_map() {
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			gotoxy(GAP_X + x * 2, GAP_Y + y);
			if (map[y][x] == 0) { set_color(GREEN, WHITE); printf(" "); }
			if (map[y][x] == 1) { set_color(D_GREEN, WHITE); printf(" "); }

			gotoxy(GAP_X + x * 2 + 1, GAP_Y + y);
			if (map[y][x] == 0) { set_color(GREEN, WHITE); printf(" "); }
			if (map[y][x] == 1) { set_color(D_GREEN, WHITE); printf(" "); }
		}
	}
}

void draw_info() {
	set_color(D_GRAY, WHITE);
	gotoxy(GAP_X, GAP_Y - 3);
	printf("SCORE %d", score);
	gotoxy(GAP_X + 35, GAP_Y - 3);
	printf("20223070 김경훈");

	int width = 60;
	int height = 16;

	set_color(BLACK, WHITE);
	gotoxy(GAP_X + width + 5, GAP_Y + height);
	printf("SNAKE GAME");

	gotoxy(GAP_X + width, GAP_Y + height + 3);
	printf("High Socre : %d", max_score);

	gotoxy(GAP_X + width, GAP_Y + height + 5);
	printf("Move Up    : W or ↑");
	gotoxy(GAP_X + width, GAP_Y + height + 6);
	printf("Move Down  : S or ↓");
	gotoxy(GAP_X + width, GAP_Y + height + 7);
	printf("Move Left  : A or ←");
	gotoxy(GAP_X + width, GAP_Y + height + 8);
	printf("Move Right : D or →");
}
