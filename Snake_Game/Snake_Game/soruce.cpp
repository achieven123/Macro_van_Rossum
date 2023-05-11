#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#define GAP_WIDTH 4
#define GAP_HEIGHT 2
#define MAP_WIDTH 70
#define MAP_HEIGHT 35

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
void draw_map();

int main() {
	getch();

	//for (int i = 0; i < 65; i++)
	//{
	//	printf("%d ", map[0][i]);
	//}
	draw_map();

	return 0;
}

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void draw_map() {
	SetColor(GRAY, WHITE);

	for (int i = 0; i < MAP_WIDTH + 4; i ++) {
		gotoxy(GAP_WIDTH + i, GAP_HEIGHT);
		printf(" ");
	}

	for (int i = 0; i < MAP_HEIGHT + 1; i++) {
		gotoxy(GAP_WIDTH, GAP_HEIGHT + i);
		printf("  ");

		for (int j = 2; j < MAP_WIDTH + 1; j += 4) {
			SetColor(GREEN, WHITE);
			gotoxy(GAP_WIDTH + j, GAP_HEIGHT + i + 1);
			printf("  ");
		}

		for (int j = 4; j < MAP_WIDTH + 1; j += 4) {
			SetColor(D_GREEN, WHITE);
			gotoxy(GAP_WIDTH + j, GAP_HEIGHT + i + 1);
			printf("  ");
		}

		SetColor(GRAY, WHITE);

		gotoxy(GAP_WIDTH + MAP_WIDTH + 2, GAP_HEIGHT + i);
		printf("  ");
	}

	for (int i = 0; i < MAP_WIDTH + 4; i ++) {
		gotoxy(GAP_WIDTH + i, GAP_HEIGHT + MAP_HEIGHT + 1);
		printf(" ");
	}
	printf("\n");
	SetColor(BLACK, WHITE);
}
