#include <stdio.h>
#include "GCD.h"
#include "LCM.h"
#include "hanoi_tower.h"


int main(void) {
	hanoi_tower(3, 1, 3, 2);
	int** path = getPath();
	int i;

	for (i = 0; i < 8; i++) {
		printf("%d : %d -> %d\n", i + 1, path[i][0], path[i][1]);
	}
	return 0;
}