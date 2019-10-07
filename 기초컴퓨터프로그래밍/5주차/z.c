//불쾌지수 Z = 40.6 + 0.72 * (X + Y)
//온도 X, 습구온도 Y

#include <stdio.h>

int main(void) {
    int temp, hum;
    printf("온도를 입력하세요 : ");
    scanf("%d", &temp);
    printf("습구온도를 입력하세요 : ");
    scanf("%d", &hum);

    double Z = 40.6 + 0.72 * (temp + hum);
    printf("불쾌지수 Z = %.2f", Z);
}