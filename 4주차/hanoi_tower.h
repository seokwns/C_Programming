#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int **path;
int count;
int len;
void moving(int **pointer, int n, int ox, int tx, int mx);
int **getPath(void);
int getLength(void);
void _free(void);


void hanoi_tower(int n, int ox, int tx, int mx) {
	int i;
	count = 0;
	len = pow(2.0, (double)n) - 1;

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
		pointer[count][0] = ox;
		pointer[count][1] = tx;
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

int getLength(void) {
	return len;
}

void _free(void) {
	free(path);
}