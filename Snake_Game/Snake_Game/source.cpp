#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define PAUSE 112
#define ESC 27

#define MAP_X 3
#define MAP_Y 2
#define MAP_WIDTH 30
#define MAP_HEIGHT 20

void gotoxy(int x, int y, char* s) {
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("%s", s);
}
void gotoxy(int x, int y, const char* s) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("%s", s);
}

void title() {
	system("title Snake Game");

	printf("####### ###    ##  #####  ##   ## #######\n");
	printf("##      ####   ## ##   ## ##  ##  ##\n");
	printf("####### ## ##  ## ####### #####   #####\n");
	printf("     ## ##  ## ## ##   ## ##  ##  ##\n");
	printf("####### ##   #### ##   ## ##   ## #######\n\n");

	printf(" ######   #####  ###    ### #######\n");
	printf("##       ##   ## ####  #### ##\n");
	printf("##   ### ####### ## #### ## #####\n");
	printf("##    ## ##   ## ##  ##  ## ##\n");
	printf(" ######  ##   ## ##      ## #######\n");
}


void draw_map(void) { //맵 테두리 그리는 함수 
	for (int i = 0; i < MAP_WIDTH; i++) {
		gotoxy(MAP_X + i, MAP_Y, "■");
	}
	for (int i = MAP_Y + 1; i < MAP_HEIGHT - 1; i++) {
		gotoxy(MAP_X, i, "■");
		gotoxy(MAP_X + MAP_WIDTH - 1, i, "■");
	}
	for (int i = 0; i < MAP_WIDTH; i++) {
		gotoxy(MAP_X + i, MAP_Y + MAP_HEIGHT - 1, "■");
	}
}

int main() {
	title();


	//draw_map();
}