#include <stdio.h>

int main(void) {
    int num;
    do {
        printf("음수 입력 : ");
        scanf("%d", &num);
    } while (num > 0);

    printf("사용자가 입력한 음수 : %d\n", num);

    return 0;
}