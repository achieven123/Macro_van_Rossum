#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <math.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define ESC 27

#define GAP_WIDTH 4
#define GAP_HEIGHT 2
#define MAP_WIDTH 64
#define MAP_HEIGHT 40

#define MENU_X 34
#define MENU_Y 25

void gotoxy(int x, int y);
int input_key();

void init();
void draw_map();
void draw_title();
void start_game();

void draw_menu(int index);
void select_menu();

void main() {
	init();
	draw_map();
	draw_title();
	draw_menu(0);
	select_menu();
	getch();
}

void gotoxy(int x, int y) {
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void init() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = 0;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	printf("Set the console window to full screen and press any key...");
	getch();
	system("cls");
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

void draw_title() {
	gotoxy(0, 11);
	printf("				===============================================================================\n");
	printf("				                                                                               \n");
	printf("				####### ###    ##  #####  ##   ## #######    ######   #####  ###    ### #######\n");
	printf("				##      ####   ## ##   ## ##  ##  ##        ##       ##   ## ####  #### ##     \n");
	printf("				####### ## ##  ## ####### #####   #######   ##   ### ####### ## #### ## #######\n");
	printf("				     ## ##  ## ## ##   ## ##  ##  ##        ##    ## ##   ## ##  ##  ## ##     \n");
	printf("				####### ##   #### ##   ## ##   ## #######    ######  ##   ## ##      ## #######\n");
	printf("				                                                                               \n");
	printf("				===============================================================================\n");
}

void start_game() {
	int delay = 300;

	Sleep(delay);
	gotoxy(0, 11);
	printf("				                                                                               \n");
	printf("				===============================================================================\n");
	printf("				####### ###    ##  #####  ##   ## #######    ######   #####  ###    ### #######\n");
	printf("				##      ####   ## ##   ## ##  ##  ##        ##       ##   ## ####  #### ##     \n");
	printf("				####### ## ##  ## ####### #####   #######   ##   ### ####### ## #### ## #######\n");
	printf("				     ## ##  ## ## ##   ## ##  ##  ##        ##    ## ##   ## ##  ##  ## ##     \n");
	printf("				####### ##   #### ##   ## ##   ## #######    ######  ##   ## ##      ## #######\n");
	printf("				===============================================================================\n");
	printf("				                                                                               \n");

	Sleep(delay);
	gotoxy(0, 11);
	printf("				                                                                               \n");
	printf("				                                                                               \n");
	printf("				===============================================================================\n");
	printf("				##      ####   ## ##   ## ##  ##  ##        ##       ##   ## ####  #### ##     \n");
	printf("				####### ## ##  ## ####### #####   #######   ##   ### ####### ## #### ## #######\n");
	printf("				     ## ##  ## ## ##   ## ##  ##  ##        ##    ## ##   ## ##  ##  ## ##     \n");
	printf("				===============================================================================\n");
	printf("				                                                                               \n");
	printf("				                                                                               \n");

	Sleep(delay);
	gotoxy(0, 11);
	printf("				                                                                               \n");
	printf("				                                                                               \n");
	printf("				                                                                               \n");
	printf("				===============================================================================\n");
	printf("				####### ## ##  ## ####### #####   #######   ##   ### ####### ## #### ## #######\n");
	printf("				===============================================================================\n");
	printf("				                                                                               \n");
	printf("				                                                                               \n");
	printf("				                                                                               \n");

	Sleep(delay);
	gotoxy(0, 11);
	printf("				                                                                               \n");
	printf("				                                                                               \n");
	printf("				                                                                               \n");
	printf("				                                                                               \n");
	printf("				===============================================================================\n");
	printf("				                                                                               \n");
	printf("				                                                                               \n");
	printf("				                                                                               \n");
	printf("				                                                                               \n");

	Sleep(delay);
	gotoxy(0, 15);
	printf("				          ===========================================================          \n");

	Sleep(delay);
	gotoxy(0, 15);
	printf("				                    =======================================                    \n");

	Sleep(delay);
	gotoxy(0, 15);
	printf("				                              ===================                              \n");

	Sleep(delay);
	gotoxy(0, 15);
	printf("				                                   =========                                   \n");
}

int input_key() {
	int input = _getch();

	if (input == 224) {
		input = _getch();
		return input;
	}
	else if (input == ENTER) {
		return input;
	}
	else return 0;
}

void draw_menu(int index) {

	for (int idx = 0; idx < 3; idx++) {
		if (idx == index) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

		switch (idx) {
		case 0:
			gotoxy(MENU_X, MENU_Y);
			printf("게임시작");
			break;
		case 1:
			gotoxy(MENU_X, MENU_Y + 1);
			printf("게임방법");
			break;
		case 2:
			gotoxy(MENU_X + 1, MENU_Y + 2);
			printf("종료");
			break;
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
}

void select_menu() {
	int input;
	int index = 0; // 0 1 2

	while (true) {
		input = input_key();

		if (input == UP && index > 0) { draw_menu(--index); }
		if (input == DOWN && index < 3) { draw_menu(++index); }
		if (input == ENTER && index == 0) { start_game(); break; }
		if (input == ENTER && index == 1) { start_game(); break; }
		if (input == ENTER && index == 2) { system("cls");  break; }
	}
}