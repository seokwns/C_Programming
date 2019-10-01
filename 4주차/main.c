#include <stdio.h>
#include "GCD.h"
#include "LCM.h"
#include "hanoi_tower.h"


int main(void) {
	
	int a, b;

	printf("Enter number a : ");
	scanf_s("%d", &a);
	printf("Enter number b : ");
	scanf_s("%d", &b);

	printf("GCD of %d and %d : %d\n", a, b, GCD(a, b));
	printf("LCM of %d and %d : %d\n", a, b, LCM(a, b));
	
	return 0;
}