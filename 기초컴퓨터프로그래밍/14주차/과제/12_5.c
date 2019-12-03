#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;

    char name[10], tel[15];
    int save, state;

    fp = fopen("12_4.txt", "r");
    if (fp == NULL) {
        printf("해당 파일이 존재하지 않음.");
        exit(1);
    }
    printf("이름 \t 연락처 \t 저축액\n");

    while(1) {
        state = fscanf(fp, "%10s %15s %d", name, tel, &save);

        if (state == EOF) break;

        printf("%s \t %s\t %d\n", name, tel, save);
    }

    fclose(fp);

    return 0;
}