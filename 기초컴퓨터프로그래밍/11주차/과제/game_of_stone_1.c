#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N, looping;
    printf("n = ");
    scanf("%d", &N);

    while (looping) {
        printf("n = ");
        scanf("%d", &N);

        if (N == 0) break;

        int position[200] = {0, 1, 0, 1, 0, 1, 1, 1};
        int i;
        for (i = 8; i <= N; i++) {
            if (position[i - 1] == 0 || position[i - 2] == 0 || position[i - 3] == 0) position[i] = 1;
            else position[i] = 0;
        }

        if (position[N]) printf("Alice\n");
        else printf("Bob\n");
    }

    return 0;
}

/*
int main(void) {
    int a[200] = {0, 0, 1, 1, 1};
    int i, j, looping = 1;
    int N;

    while (looping) {
        printf("n = ");
        scanf("%d", &N);

        if (N == 0) break;

        for (i = 5; i <= N; i++) {
            for (j = 1; j <= 3; j++) {
                if(!a[i - j]) {
                    a[i] = 1;
                    break;
                }
            }
        }

        if (a[N]) printf("Alice\n");
        else printf("Bob\n");
    }
}
*/