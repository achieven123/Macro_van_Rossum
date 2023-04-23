/*
* 피보나치 수열
* 1, 1, 2, 3, 5, 8, 13, 21 ...
*/

#include <stdio.h>

int fibo(int n) {
	if (n <= 2) return 1;
	else return (fibo(n - 1) + fibo(n - 2));
}

int main() {
	printf("%d", fibo(7)); //13

	return 0;
}