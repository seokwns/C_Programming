#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int buffer;
    int max = 0, sum = 0, count = 0;
    FILE *fp = fopen("nums.txt", "r");

    if(fp == NULL) {
        printf("해당 파일 없음.\n");
        exit(1);
    }
    
    while (1) {
        int state = fscanf(fp, "%d", &buffer);

        if (state == EOF) break;

        sum += buffer;
        if (max < buffer) max = buffer;
    }

    printf("Max number: %d\n", max);
    printf("Sum : %d\n", sum);

    fclose(fp);

    return 0;
}