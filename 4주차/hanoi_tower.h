#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int **path; //하노이탑의 이동 과정을 담을 배열
int count;
void moving(int **pointer, int n, int ox, int tx, int mx); //하노이탑 이동 함수
int **getPath(void); //이동과정 반환 함수


void hanoi_tower(int n, int ox, int tx, int mx) {
	int i;
	count = 0;
	const int len = pow(2.0, (double)n) - 1; //하노이탑의 총 이동 횟수는 2^n - 1 이므로 이동 횟수만큼 할당

	path = (int **)malloc(sizeof(int *) * len);
	for (i = 0; i < len; i++) path[i] = (int *)malloc(sizeof(int) * 2);

	moving(path, n, ox, tx, mx);
}

void moving(int **pointer, int n, int ox, int tx, int mx) {
	if (n < 1) {
		printf("Error: n >= 1\n");
		return;
	}
	else if (n == 1) {
		pointer[count][0] = ox; //이동 전 위치
		pointer[count][1] = tx; //이동 후 위치
		count++;
	}
	else {
		moving(pointer, n - 1, ox, mx, tx);
		moving(pointer, 1, ox, tx, mx);
		moving(pointer, n - 1, mx, tx, ox);
	}
}

int **getPath(void) {
	return path;
}