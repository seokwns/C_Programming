#include <stdio.h>

int main(void) {
    int sum = 0;
    for(;;) {
        sum = sum + 10;
        if (sum >= 100) 
            break;
    }

    printf("sum 변수에 누적된 값은 %d입니다. \n", sum);

    return 0;
}