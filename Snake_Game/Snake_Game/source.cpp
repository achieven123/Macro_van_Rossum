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
#define MAP_WIDTH 70
#define MAP_HEIGHT 20

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void title() {
	printf("\n\n\n\n");
	printf("	####### ###    ##  #####  ##   ## #######\n");
	printf("	##      ####   ## ##   ## ##  ##  ##\n");
	printf("	####### ## ##  ## ####### #####   #####\n");
	printf("	     ## ##  ## ## ##   ## ##  ##  ##\n");
	printf("	####### ##   #### ##   ## ##   ## #######\n\n");

	printf("	 ######   #####  ###    ### #######\n");
	printf("	##       ##   ## ####  #### ##\n");
	printf("	##   ### ####### ## #### ## #####\n");
	printf("	##    ## ##   ## ##  ##  ## ##\n");
	printf("	 ######  ##   ## ##      ## #######\n");
}

void menu() {

}

void draw_map(void) { //맵 테두리 그리는 함수 
	for (int i = 0; i < MAP_WIDTH; i+= 2) {
		gotoxy(MAP_X + i, MAP_Y);
		printf("■");
	}
	for (int i = MAP_Y + 1; i < MAP_HEIGHT - 1; i++) {
		gotoxy(MAP_X, i);
		printf("■");
		gotoxy(MAP_X + MAP_WIDTH - 1, i);
		printf("■");
	}
	for (int i = 0; i < MAP_WIDTH; i+= 2) {
		gotoxy(MAP_X + i, MAP_Y + MAP_HEIGHT - 1);
		printf("■");
	}
}

int main() {
	title();


	draw_map();
}