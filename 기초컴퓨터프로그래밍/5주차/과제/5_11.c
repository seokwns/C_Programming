#include <stdio.h>

int main(void) {
    char menu;
    printf("음료 선택 (w-물, c-커피, g-녹차) : ");
    scanf("%c", &menu);

    switch(menu) {
        case 'w':
            printf("물입니다.\n");
            break;
        case 'c':
            printf("커피입니다.\n");
            break;
        case 'g':
            printf("녹차입니다.\n");
            break;
        default:
            printf("해당 메뉴가 없습니다.\n");
    }

    return 0;
}