#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_DEGREE 101

struct polynomial {
	int degree;
	int coef[MAX_DEGREE];
};

int inputPoly(int )

int main() {
	int row, column;

	printf("연립 선형방정식을 첨가행렬 형태로 입력하시오.\n");
	printf("입력할 첨가행렬의 행의 크기 : "); scanf("%d", &row);
	printf("입력할 첨가행렬의 열의 크기 : "); scanf("%d", &column);



	return 0;
}