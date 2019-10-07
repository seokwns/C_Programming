#include <stdio.h>
#include "GCD.h"
#include "LCM.h"
#include "hanoi_tower.h"


int main(void) {
	int** path;
	int i, n;

	printf("하노이탑 원반 개수 : ");
	scanf("%d", &n);
	hanoi_tower(n, 1, 3, 2);
	path = getPath();

	for (i = 0; i < getLength(); i++) {
		printf("%d : %d -> %d\n", i + 1, path[i][0], path[i][1]);
	}
	_free();
	
	return 0;
}