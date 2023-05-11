#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#define GAP_WIDTH 6
#define GAP_HEIGHT 6
#define MAP_WIDTH 25
#define MAP_HEIGHT 25

int map[MAP_HEIGHT][MAP_WIDTH * 2] = { 0 };

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

void SetColor(int backcolor, int fontcolor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backcolor * 16 + fontcolor);
}

void gotoxy(int x, int y);
void init();
void draw_map();

int main() {
	init();
	draw_map();

	return 0;
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
	printf("Set the console window to full screen and press any key...");
	_getch();
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
		SetColor(D_GRAY, WHITE);
		gotoxy(GAP_WIDTH - 2 + i, GAP_HEIGHT - 4);
		printf(" ");
		gotoxy(GAP_WIDTH - 2 + i, GAP_HEIGHT - 3);
		printf("@");
		gotoxy(GAP_WIDTH - 2 + i, GAP_HEIGHT - 2);
		printf(" ");
		
		SetColor(GRAY, WHITE);
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
			if (map[y][x] == 0) { SetColor(GREEN, WHITE); printf(" "); }
			if (map[y][x] == 1) { SetColor(D_GREEN, WHITE); printf(" "); }
		}
	}

	gotoxy(GAP_WIDTH + 10, GAP_HEIGHT + 10);
	SetColor(RED, WHITE); printf(" ");
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
	gotoxy(GAP_WIDTH + 16, GAP_HEIGHT + 10);
	printf(" ");
	gotoxy(GAP_WIDTH + 17, GAP_HEIGHT + 10);
	printf(" ");

	printf("\n");
	printf("\n");
	SetColor(BLACK, WHITE);
}
