#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <math.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27

#define GAP_WIDTH 4
#define GAP_HEIGHT 2
#define MAP_WIDTH 64
#define MAP_HEIGHT 40

#define MENU_X 34
#define MENU_Y 25

void gotoxy(int x, int y);
void draw_title();
void draw_menu(int x, int y);
void select_menu(int x, int y);
void draw_map();
int input_key();

int main() {
	draw_title();
	draw_map();
	draw_menu(MENU_X, MENU_Y);
	select_menu(MENU_X, MENU_Y);
	_getch();
}

int input_key() {
	int input = _getch();

	if (input == 224) {
		input = _getch();
		return input;
	}
	else return 0;
}

void gotoxy(int x, int y) {
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void draw_title() {
	printf("Set the console window to full screen and press any key...");
	getch();
	system("cls");

	printf("\n\n\n\n\n\n\n\n\n\n\n");

	printf("				===============================================================================\n\n");
	printf("				####### ###    ##  #####  ##   ## #######    ######   #####  ###    ### #######\n");
	printf("				##      ####   ## ##   ## ##  ##  ##        ##       ##   ## ####  #### ##\n");
	printf("				####### ## ##  ## ####### #####   #######   ##   ### ####### ## #### ## #######\n");
	printf("				     ## ##  ## ## ##   ## ##  ##  ##        ##    ## ##   ## ##  ##  ## ##\n");
	printf("				####### ##   #### ##   ## ##   ## #######    ######  ##   ## ##      ## #######\n\n");
	printf("				===============================================================================\n");
}

void draw_menu(int x, int y) {
	gotoxy(x, y);
	printf("게임시작");

	gotoxy(x, y + 1);
	printf("게임방법");

	gotoxy(x + 1, y + 2);
	printf("종료");
}

void select_menu(int x, int y) {
	int input;
	int index = -1;

	while (true) {
		input = input_key();

		if (input == UP) index = abs(index - 1) % 3;
		if (input == DOWN) index = abs(index + 1) % 3;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

		switch (index) {
		case 0:
			gotoxy(x, y);
			printf("게임시작");
			break;
		case 1:
			gotoxy(x, y + 1);
			printf("게임방법");
			break;
		case 2:
			gotoxy(x + 1, y + 2);
			printf("종료");
			break;
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
}

void draw_map() {
	for (int i = 0; i < MAP_WIDTH; i++) {
		gotoxy(GAP_WIDTH + i, GAP_HEIGHT);
		printf("■");
	}

	for (int i = GAP_HEIGHT + 1; i < MAP_HEIGHT + 1; i++) {
		gotoxy(GAP_WIDTH, i);
		printf("■");
		gotoxy(GAP_WIDTH + MAP_WIDTH - 1, i);
		printf("■");
	}

	for (int i = 0; i < MAP_WIDTH; i++) {
		gotoxy(GAP_WIDTH + i, GAP_HEIGHT + MAP_HEIGHT - 1);
		printf("■");
	}
}