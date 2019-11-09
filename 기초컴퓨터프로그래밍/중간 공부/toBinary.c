#include <stdio.h>
#include <math.h>

int main(void) {
    double n;
    int i, x;
    double j;

    scanf("%lf", &n);

    char rtoBin[100000], toBin[100000];
    
    if (n > 1.0) {
        for (i = n, x = 0; i > 0; x++, i /= 2) {
            rtoBin[x] = i%2 + '0';
        }

        for (x--, i = x; i >= 0; i--) {
            toBin[i] = rtoBin[x - i];
        }
    } else if (n > 0.0 && n < 1.0) {
        for (j = n, x = 0; j != 1.0; x++) {
            j *= 2;
            toBin[x] = ((int) (j)) + '0';
            if (j > 1) {
                j -= 1.0;
            }
        }
    }
    

    printf("%lf to binary : %s", n, toBin);

    return 0;
}
