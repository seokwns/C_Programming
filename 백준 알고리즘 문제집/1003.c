#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

static int count0;
static int count1;

int fibonacci(int n);

int main(void) {

    int start_time, end_time;
    float time;
    
    int TestCase = -1;

    while (TestCase <= 0) {
        printf("Test Case : ");
        scanf("%d", &TestCase);

        if (TestCase <= 0 || TestCase > 40) {
            printf("TestCase는 1 이상의 수를 입력해야 합니다.");
        }
    }

    int i;
    int* cases = (int*) malloc(sizeof(int) * TestCase);

    for (i = 0; i < TestCase; i++) {
        cases[i] = -1;

        while (cases[i] < 0 || cases[i] > 40) {
            printf("[Case %d] : ", i + 1);
            scanf("%d", cases + i);
            
            if (cases[i] < 0 || cases[i] > 40) {
                printf("1 이상 40 이하의 수를 입력하세요.\n");
            }
        }
    }

    start_time = clock();
    for (i = 0; i < TestCase; i++) {
        fibonacci(cases[i]);
        printf("%d %d\n", count0, count1);
        count0 = 0;
        count1 = 0;
    }
    end_time = clock();

    time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\n\n걸린시간 : %f\n", time);
    
    return 0;
}

int fibonacci(int n) {
    if (n == 0) {
        count0++;
        return 0;
    } else if (n == 1) {
        count1++;
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}