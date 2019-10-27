#include <stdio.h> 

int sum_of_3(int x, int y) {
    int i, result = 0;
    for (i = x; i <= y; i++) {
        if (i%3 == 0) result += i;
    }

    return result;
}

int main(void) {
    int b, e;

    scanf("%d%d", &b, &e);

    printf("sum == %d\n", sum_of_3(b, e));
    return 0;
}