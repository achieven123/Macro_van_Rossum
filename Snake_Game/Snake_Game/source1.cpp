#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <time.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define ESC 27
#define YES 121
#define NO 110

#define GAP_WIDTH 4
#define GAP_HEIGHT 2
#define MAP_WIDTH 128
#define MAP_HEIGHT 32

#define MENU_X 64
#define MENU_Y 25

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

void SetColor(int backcolor, int fontcolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backcolor * 16 + fontcolor);
}

char game_title[9][81] = {
	"================================================================================",
	"                                                                                ",
	"####### ###    ##  #####  ##   ## #######     ######   #####  ###    ### #######",
	"##      ####   ## ##   ## ##  ##  ##         ##       ##   ## ####  #### ##     ",
	"####### ## ##  ## ####### #####   #######    ##   ### ####### ## #### ## #######",
	"     ## ##  ## ## ##   ## ##  ##  ##         ##    ## ##   ## ##  ##  ## ##     ",
	"####### ##   #### ##   ## ##   ## #######     ######  ##   ## ##      ## #######",
	"                                                                                ",
	"================================================================================"
};
int score = 0;
int elapsed_minute = 0;
int elapsed_second = 0;

void gotoxy(int x, int y);
int input_key();
void start_time();
void end_time();

void init();
void draw_map();
void draw_title();
void draw_menu(int index);
void select_menu();

void game_start();
void game_over();

void main() {
	SetColor(GRAY, WHITE);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf("                               \n");
	//printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	//printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	//printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	//printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//printf("%d", _getch());
	//_getch();
	//while (true) {
		//init();
		//draw_map();
		//draw_title();
		//select_menu();
	//}
}

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
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

void start_time() {
	clock_t start = clock();
	elapsed_second -= start / CLOCKS_PER_SEC;
}
void end_time() {
	clock_t end = clock();
	elapsed_second += end / CLOCKS_PER_SEC;
	elapsed_minute = elapsed_second / 60;
	elapsed_second %= 60;
}

void init() {
	start_time();

	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = FALSE;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	system("cls");
	gotoxy(0, 0); printf("Set the console window to full screen and press any key...");
	_getch();
	system("cls");
}
void draw_map() {
	for (int i = 0; i < MAP_WIDTH; i += 2) {
		gotoxy(GAP_WIDTH + i, GAP_HEIGHT);
		printf("■");
	}

	for (int i = 0; i < MAP_HEIGHT + 2; i++) {
		gotoxy(GAP_WIDTH - 1, GAP_HEIGHT + i);
		printf("■");
		gotoxy(GAP_WIDTH + MAP_WIDTH, GAP_HEIGHT + i);
		printf("■");
	}

	for (int i = 0; i < MAP_WIDTH; i += 2) {
		gotoxy(GAP_WIDTH + i, GAP_HEIGHT + MAP_HEIGHT + 1);
		printf("■");
	}
}
void draw_title() {
	gotoxy(28, 10); printf("================================================================================");
	gotoxy(28, 11); printf("                                                                                ");
	gotoxy(28, 12); printf("####### ###    ##  #####  ##   ## #######     ######   #####  ###    ### #######");
	gotoxy(28, 13); printf("##      ####   ## ##   ## ##  ##  ##         ##       ##   ## ####  #### ##     ");
	gotoxy(28, 14); printf("####### ## ##  ## ####### #####   #######    ##   ### ####### ## #### ## #######");
	gotoxy(28, 15); printf("     ## ##  ## ## ##   ## ##  ##  ##         ##    ## ##   ## ##  ##  ## ##     ");
	gotoxy(28, 16); printf("####### ##   #### ##   ## ##   ## #######     ######  ##   ## ##      ## #######");
	gotoxy(28, 17); printf("                                                                                ");
	gotoxy(28, 18); printf("================================================================================");
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
			printf("게임설정");
			break;
		case 2:
			gotoxy(MENU_X + 2, MENU_Y + 2);
			printf("종료");
			break;
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
}
void select_menu() {
	int input;
	int index = 0; // 0 1 2
	draw_menu(index);

	while (true) {
		input = input_key();

		if (input == UP && index > 0) { draw_menu(--index); gotoxy(0, 0); printf("%d", index); }
		if (input == DOWN && index < 2) { draw_menu(++index); gotoxy(0, 0); printf("%d", index); }
		if (input == ENTER && index == 0) { game_start(); break; }
		if (input == ENTER && index == 1) { game_over(); break; }
		if (input == ENTER && index == 2) { system("cls");  break; }
	}
}

void game_start() {
	int delay = 100;

	for (int i = 0; i < 3; i++) { gotoxy(MENU_X, MENU_Y + i); printf("        "); }

	Sleep(delay);
	gotoxy(28, 10); printf("                                                                                ");
	gotoxy(28, 11); printf("================================================================================");
	gotoxy(28, 12); printf("####### ###    ##  #####  ##   ## #######     ######   #####  ###    ### #######");
	gotoxy(28, 13); printf("##      ####   ## ##   ## ##  ##  ##         ##       ##   ## ####  #### ##     ");
	gotoxy(28, 14); printf("####### ## ##  ## ####### #####   #######    ##   ### ####### ## #### ## #######");
	gotoxy(28, 15); printf("     ## ##  ## ## ##   ## ##  ##  ##         ##    ## ##   ## ##  ##  ## ##     ");
	gotoxy(28, 16); printf("####### ##   #### ##   ## ##   ## #######     ######  ##   ## ##      ## #######");
	gotoxy(28, 17); printf("================================================================================");
	gotoxy(28, 18); printf("                                                                                ");

	Sleep(delay);
	gotoxy(28, 10); printf("                                                                                ");
	gotoxy(28, 11); printf("                                                                                ");
	gotoxy(28, 12); printf("================================================================================");
	gotoxy(28, 13); printf("##      ####   ## ##   ## ##  ##  ##         ##       ##   ## ####  #### ##     ");
	gotoxy(28, 14); printf("####### ## ##  ## ####### #####   #######    ##   ### ####### ## #### ## #######");
	gotoxy(28, 15); printf("     ## ##  ## ## ##   ## ##  ##  ##         ##    ## ##   ## ##  ##  ## ##     ");
	gotoxy(28, 16); printf("================================================================================");
	gotoxy(28, 17); printf("                                                                                ");
	gotoxy(28, 18); printf("                                                                                ");

	Sleep(delay);
	gotoxy(28, 10); printf("                                                                                ");
	gotoxy(28, 11); printf("                                                                                ");
	gotoxy(28, 12); printf("                                                                                ");
	gotoxy(28, 13); printf("================================================================================");
	gotoxy(28, 14); printf("####### ## ##  ## ####### #####   #######    ##   ### ####### ## #### ## #######");
	gotoxy(28, 15); printf("================================================================================");
	gotoxy(28, 16); printf("                                                                                ");
	gotoxy(28, 17); printf("                                                                                ");
	gotoxy(28, 18); printf("                                                                                ");

	Sleep(delay);
	gotoxy(28, 10); printf("                                                                                ");
	gotoxy(28, 11); printf("                                                                                ");
	gotoxy(28, 12); printf("                                                                                ");
	gotoxy(28, 13); printf("                                                                                ");
	gotoxy(28, 14); printf("================================================================================");
	gotoxy(28, 15); printf("                                                                                ");
	gotoxy(28, 16); printf("                                                                                ");
	gotoxy(28, 17); printf("                                                                                ");
	gotoxy(28, 18); printf("                                                                                ");

	Sleep(delay);
	gotoxy(28, 14); printf("          ============================================================          ");

	Sleep(delay);
	gotoxy(28, 14); printf("                    ========================================                    ");

	Sleep(delay);
	gotoxy(28, 14);  printf("                             ====================                              ");

	Sleep(delay);
	gotoxy(28, 14); printf("                                    ========                                    ");

	Sleep(delay);
	gotoxy(28, 14); printf("                                    OOOOOOO0                                    ");
}
void game_over() {
	end_time();
	srand(time(0));

	for (int i = 0; i < 3; i++) { gotoxy(MENU_X, MENU_Y + i); printf("        "); }

	gotoxy(28, 22); printf("점수 : %d", score);
	gotoxy(28, 23); printf("시간 : %02d:%02d", elapsed_minute, elapsed_second);

	for (int i = 0; i < 6; i++) {
		int color = rand() % 15 + 1;
		int delay = 200;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i + 9);

		gotoxy(28, 10); printf("================================================================================");
		gotoxy(28, 11); printf("                                                                                ");
		gotoxy(28, 12); printf("  ######   #####  ###    ### #######     ######  ##        ## ####### #######   ");
		gotoxy(28, 13); printf(" ##       ##   ## ####  #### ##         ##    ##  ##      ##  ##      ##    ##  ");
		gotoxy(28, 14); printf(" ##   ### ####### ## #### ## #######    ##    ##   ##    ##   ####### #######   ");
		gotoxy(28, 15); printf(" ##    ## ##   ## ##  ##  ## ##         ##    ##    ##  ##    ##      ##   ##   ");
		gotoxy(28, 16); printf("  ######  ##   ## ##      ## #######     ######      ####     ####### ##    ##  ");
		gotoxy(28, 17); printf("                                                                                ");
		gotoxy(28, 18); printf("================================================================================");
		Sleep(delay);
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(40, 22); printf("계속하시겠습니까? (Y/N)");

	while (true) {
		fflush(stdin);
		int input = _getch();
		
		if (input == YES) {
			printf("Yes");
			system("Pause");
			return;
		}
		if (input == NO) {
			system("cls");
			exit(0);
		}
	}
}