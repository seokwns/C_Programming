#include <stdio.h>

int main(void) {
    int num;

    printf("1~10 사이 숫자 입력 : ");
    scanf("%d", &num);

    switch(num) {
        case 2:
        case 4:
        case 6:
        case 8:
        case 10:
            printf("입력 값 %d는 짝수\n", num);
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 9:
            printf("입력 값 %d는 홀수\n", num);
            break;
        default:
            printf("다시 입력하세요.\n");
    }

    return 0;
}