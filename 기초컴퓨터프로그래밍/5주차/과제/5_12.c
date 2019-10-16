#include <stdio.h>

int main(void) {
    int num;
    int digit_1, digit_10, digit_100;

    printf("세 자리 정수 입력 : ");
    scanf("%d", &num);

    digit_100 = num / 100;
    digit_10 = (num % 100) / 10;
    digit_1 = num % 10;

    if(digit_100 % 2 == 0)
        printf("100의 자리 %d : 짝수 \n", digit_100);
    else
        printf("100의 자리 %d : 홀수 \n", digit_100);

    if(digit_10 % 2 == 0)
        printf(" 10의 자리 %d : 짝수 \n", digit_10);
    else
        printf(" 10의 자리 %d : 홀수 \n", digit_10);

    if(digit_1 % 2 == 0)
        printf("  1의 자리 %d : 짝수 \n", digit_1);
    else
        printf("  1의 자리 %d : 홀수 \n", digit_1);

    return 0;
}