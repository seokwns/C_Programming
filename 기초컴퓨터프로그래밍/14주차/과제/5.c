#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int sum, max;
    int buffer;
    FILE *fp = fopen("nums.bin", "r");

    if (fp == NULL) {
        printf("해당 파일 없음.\n");
        exit(1);
    }

    while ( fread(&buffer, sizeof(int), 1, fp) == 1 ) {
        sum += buffer;
        if (max < buffer) max = buffer;
    }

    printf("Max number : %d\n", max);
    printf("Sum : %d\n", sum);

    return 0;
}