#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

void swap(int *n1, int *n2) {
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}


void sort_integers(int *pn) {
	int x, y;
	for (x = 0; pn[x] != -1; x++) {
		for (y = x; pn[y] != -1; y++) {
			if (pn[x] > pn[y]) swap( (pn + x), (pn + y) );
		}
	}
}


int count_duplicate(int *pn) {
	int i = 0, j, count = 0;

    for (i = 0; pn[i] != -1; i++) {
        if (pn[i] == pn[i + 1]) count++;
        if ((pn[i - 1] != pn[i]) && (pn[i] == pn[i + 1])) count++;
    }

    if (count == 1) count = 0;

    return count;
}


int main(void) {
    int *pns = NULL;
    unsigned int nsize;
    int i;

    puts("Enter the number of random numbers to generate:");
    scanf("%u", &nsize);
    srand(time(0));

    pns = (int*)malloc(sizeof(int) * (nsize + 1));
    assert(pns);

    for (i = 0; i < nsize; i++) {
    	pns[i] = rand()%10;
	}
	pns[i] = -1;

    sort_integers(pns);

	for (i = 0; i < nsize + 1; i++) {
		printf("%d ", *(pns + i));
	}
	printf("\n");
    printf("The number of duplicate numbers is %d\n", count_duplicate(pns));
	
    return 0;
}