#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int count;
    printf("정수의 개수 : ");
    scanf("%d", &count);

    int *nums = (int *)malloc(sizeof(int) * count);
    int i, len;

    for (i = 0; i < count; i++) scanf("%d", nums + i);

    for (len = i, i = 0; i < len; i++) printf("%d ", *(nums + len - i - 1));

    free(nums);

    return 0;
}