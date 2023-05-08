#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define NUM_OF_SENTENCE 25
#define MAX_LENGTH 300

enum {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VOILET,
	DAKR_YELLOW,
	WHITE,
	GRAY,
	LIGHT_BLUE,
	LIGHT_GREEN,
	LIGHT_AQUA,
	LIGHT_RED,
	LIGHT_PURPLE,
	LIGHT_YELLOW,
	BRIGHT_WHITE,
};

void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

void start(int random, int count) {
	FILE* fp;
	fp = fopen("list.txt", "r");

	if (fp == NULL) {
		setColor(LIGHT_RED);
		printf("\n\n    시스템 : 파일이 존재하지 않습니다.\n\n    ");
		setColor(BRIGHT_WHITE);
		system("PAUSE >nul");
		return;
	}

	char c;
	char buffer[MAX_LENGTH];
	char* result;

	int arr[NUM_OF_SENTENCE] = { 0 };
	int index = 0;
	int lineCount = 0;
	int outputCount = 1;

	if (random == 1) {
		srand(time(NULL));

		for (int i = 0; i < count; i++) {
			while (1) {
				index = rand() % NUM_OF_SENTENCE;

				if (arr[index] == 0) {
					arr[index] = 1;
					break;

				}
			}
		}
	}
	else {
		for (int i = 0; i < count; i++) {
			arr[i] = 1;
		}
	}

	while (fgets(buffer, MAX_LENGTH, fp) != NULL) {
		if (arr[lineCount] == 1) {
			setColor(LIGHT_BLUE);
			printf("\n\n    [%d번 문제]\n\n", outputCount);
			setColor(BRIGHT_WHITE);
			printf("    %s    ", buffer);

			outputCount++;
			system("PAUSE >nul");
			system("cls");
		}

		lineCount++;
	}

	fclose(fp);
}

void setting(int* random, int* count) {
	int num;

	while (1) { //랜덤 유무 입력
		setColor(LIGHT_BLUE);
		printf("\n\n");
		printf("    === 출력 ===\n\n");
		printf("    무 작 위 : 1\n\n");
		printf("    순서대로 : 2\n\n");
		printf("\n");
		setColor(BRIGHT_WHITE);

		printf("    랜덤 유무 : ");
		scanf("%d", &num);

		if (num != 1 && num != 2) {
			setColor(LIGHT_RED);
			printf("\n    시스템 : 잘못 입력하였습니다.");
			setColor(BRIGHT_WHITE);
			Sleep(1000);
			system("cls");
		}
		else {
			*random = num;
			system("cls");
			break;
		}
	}

	while (1) { //질문 개수 입력
		setColor(LIGHT_BLUE);
		printf("\n\n");
		printf("    ============ 범위 ============\n\n");
		printf("    1에서 25사이의 수를 입력하시오.\n\n");
		printf("\n");
		setColor(BRIGHT_WHITE);

		printf("    질문 개수 : ");
		scanf("%d", &num);

		if (num < 1 || num > NUM_OF_SENTENCE) {
			setColor(LIGHT_RED);
			printf("\n    시스템 : 1과 %d 사이의 수를 입력하시오.", NUM_OF_SENTENCE);
			setColor(BRIGHT_WHITE);
			Sleep(1000);
			system("cls");
		}
		else {
			*count = num;
			break;
		}
	}
}

void intro() {
	int num;
	int isRandom = 1;
	int howMany = 3;

	while (1) {
		system("cls");

		setColor(LIGHT_BLUE);
		printf("\n\n");
		printf("    === 명 령 ===\n\n");
		printf("    1 : 시험 시작\n\n");
		printf("    2 : 시험 설정\n\n");
		printf("    3 : 종     료\n\n");
		printf("\n");
		setColor(BRIGHT_WHITE);

		printf("    메뉴 번호 입력 : ");
		scanf("%d", &num);


		switch (num)
		{
		case 1:
			system("cls");
			start(isRandom, howMany);
			break;
		case 2:
			system("cls");
			setting(&isRandom, &howMany);
			break;
		case 3:
			system("cls");
			setColor(LIGHT_YELLOW);
			printf("\n\n    수고하셨습니다.\n\n");
			setColor(BRIGHT_WHITE);
			return;
		default:
			setColor(LIGHT_RED);
			printf("\n    시스템 : 잘못 입력하였습니다.");
			setColor(BRIGHT_WHITE);
			Sleep(1000);
			system("cls");
			break;
		}
	}
}

int main() {
	intro();

	return 0;
}