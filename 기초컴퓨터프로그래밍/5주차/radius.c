#include <stdio.h>
#define PI 3.14

int main(void) {
    float radius;
    printf("반지름 : ");
    scanf("%f", &radius);

    float A = 4 * PI * radius * radius;
    float V = (4.0/3) * PI * radius * radius * radius;

    printf("표면적 : %f\n", A);
    printf("부피 : %f", V);

    return 0;
}
