#include <stdio.h> 
#define NSIZE 3

void printNxN(int m[NSIZE][NSIZE]) {
	int i,j;
	char lineseg[8]="-------";

	printf("+");
	for (i=0;i<NSIZE;i++) printf("%s",lineseg);
	printf("+\n");

	for (i=0;i<NSIZE;i++) {
		printf("|");
		for (j=0;j<NSIZE;j++)	printf("%6d ",m[i][j]);
		printf("|\n");
	}

	printf("+");
	for (i=0;i<NSIZE;i++) printf("%s",lineseg);
	printf("+\n");
}

int main(void) {
	int A[NSIZE][NSIZE]={	
			{1,2,3},
			{4,5,6},
			{7,8,9} };
	int A_T[NSIZE][NSIZE];

	printNxN(A);
	int x, y;
    for(x = 0; x < NSIZE; x++)
        for(y = 0; y < NSIZE; y++)
            A_T[x][y] = A[y][x];

	printNxN(A_T);

	return 0;
}