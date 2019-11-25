#include <stdio.h>


int F(int k, int n);

int main(void) {
    int k;
    printf("k : ");
    scanf("%d", &k);
    
    int n;
    printf("n : ");
    scanf("%d", &n);


    int solutions = F(k, n);
    printf("soultion(k = %d, n = %d) = %d\n", k, n, solutions);

    return 0;
}

int F(int k, int n) {
    int solutions = 1; //BLACK k, RED 0 
    int x, y;

    for (x = 0; x <= k - n; x++) {
        for (y = k - (x + n); y >= 0; y--) {
            solutions += F(y - 1, n);
        }
    }

    return solutions;
}
