#include <stdio.h>

int main(void) {
    int a[10] = {11, 22, 33, 44, 55};
    int i, j, n = 5;
    
    scanf("%d", &j);

    if (j < 1 || j >= 5) {
        a[4] = 55;
    } else {
        a[j - 1] = 55;
    }
    n--;

    for(i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");
	
    return 0;
}