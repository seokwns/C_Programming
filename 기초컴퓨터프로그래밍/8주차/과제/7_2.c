#include <stdio.h>

int add(int x, int y);

int main(void) {
    int result;

    result = add(20, 30);
    printf("ÇÕ°è : %d\n", result);
    return 0;
}

int add(int x, int y) {
    int res;
    res = x + y;
    return res;
}