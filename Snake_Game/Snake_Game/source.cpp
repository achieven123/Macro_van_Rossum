#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27

#define GAP_WIDTH 4
#define GAP_HEIGHT 2
#define MAP_WIDTH 66
#define MAP_HEIGHT 40

void gotoxy(int x, int y);
void main_title();
void main_menu();
void draw_map();

int main() {
	main_title();
	draw_map();
}

void gotoxy(int x, int y) {
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void main_title() {
	printf("Set the console window to full screen and press any key...");
	getch();
	system("cls");

	printf("\n\n\n\n\n");
	printf("				####### ###    ##  #####  ##   ## #######	 ######   #####  ###    ### #######\n");
	printf("				##      ####   ## ##   ## ##  ##  ##		##       ##   ## ####  #### ##\n");
	printf("				####### ## ##  ## ####### #####   #####		##   ### ####### ## #### ## #####\n");
	printf("				     ## ##  ## ## ##   ## ##  ##  ##		##    ## ##   ## ##  ##  ## ##\n");
	printf("				####### ##   #### ##   ## ##   ## #######	 ######  ##   ## ##      ## #######\n\n");
}

void main_menu() {

}

void draw_map() {
	for (int i = 0; i < MAP_WIDTH; i++) {
		gotoxy(GAP_WIDTH + i, GAP_HEIGHT);
		printf("бс");
	}
	for (int i = GAP_HEIGHT + 1; i < MAP_HEIGHT + 1; i++) {
		gotoxy(GAP_WIDTH, i);
		printf("бс");
		gotoxy(GAP_WIDTH + MAP_WIDTH - 1, i);
		printf("бс");
	}
	for (int i = 0; i < MAP_WIDTH; i++) {
		gotoxy(GAP_WIDTH + i, GAP_HEIGHT + MAP_HEIGHT - 1);
		printf("бс");
	}
}