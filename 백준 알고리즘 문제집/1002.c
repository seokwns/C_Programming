/*
* 백준 알고리즘 문제집 1002번 문제
* FIELD : 기하 알고리즘
* SOLUTION : 두 원의 위치관계를 묻는 문제입니다.
*            두 원의 중심좌표와 반지름을 알 때, 교점의 개수를 구하면 됩니다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN -10000
#define MAX 10000
//입력가능한 좌표의 최대값과 최소값

#define INFINITE -1

#define INNER 1
#define INLINE 0
#define OUTTER -1
//두 원의 중심의 위치관계를 나타내는 상수


typedef struct CircleData {
    int X;
    int Y;
    int r;
} CircleData;
//원의 정보를 담은 구조체


CircleData** getCase(int TestCase);
int getDistance(CircleData p1, CircleData p2);
int checkCirclePoint(CircleData p1, CircleData p2);


int main(void) {
    int TestCase = -1, i;

    while (TestCase <= 0) {
        printf("Test Case: ");
        scanf("%d", &TestCase);

        if (TestCase <= 0) printf("Test Case는 0보다 커야 합니다.\n");
    }
    //테스트 케이스를 입력받습니다.

    CircleData** cases = getCase(TestCase);
    int result;

    for (i = 0; i < TestCase; i++) {
        int DIS = getDistance(cases[i][0], cases[i][1]);
        //두 원의 중심 사이 거리
        int AddDis = cases[i][0].r + cases[i][1].r;
        //두 원의 반지름의 합

        CircleData MAX_CIR = cases[i][0].r > cases[i][1].r? cases[i][0] : cases[i][1];
        CircleData MIN_CIR = cases[i][0].r < cases[i][1].r? cases[i][0] : cases[i][1];
        //위치관계를 나타낼 때 기준이 되는 원은 반지름이 큰 원이므로 반지름이 큰 원을 구합니다.

        switch(checkCirclePoint(MAX_CIR, MIN_CIR)) {
            case INNER: //작은 원의 중심이 큰 원 내부에 있을 때
                if (DIS + MIN_CIR.r < MAX_CIR.r) result = 0;
                if (DIS + MIN_CIR.r == MAX_CIR.r) result = 1;
                if (DIS + MIN_CIR.r > MAX_CIR.r) result = 2;
                if (DIS == 0 && MAX_CIR.r == MIN_CIR.r) result = INFINITE;
                break;

            case INLINE: //작은 원의 중심이 큰 원의 둘레에 있을 때
                result = 2;
                break;

            case OUTTER: //작은 원의 중심이 외부에 있을 때
                if (DIS > AddDis) result = 0;
                if (DIS == AddDis) result = 1;
                if (DIS < AddDis) result = 2;
                break;
        }

        printf("[Case %d] %d\n", i + 1, result);
    }

    return 0;
}

CircleData** getCase(int TestCase) { //케이스별 좌표를 입력받는 함수 입니다.
    int i;
    CircleData** cases = (CircleData**) malloc(sizeof(CircleData*) * TestCase);

    for (i = 0; i < TestCase; i++) {
        cases[i] = (CircleData*) malloc(sizeof(CircleData) * 2);
        printf("[Case %d] position: ", i + 1);

        CircleData p1 = {MIN - 1, MIN - 1, -1};
        CircleData p2 = {MIN - 1, MIN - 1, -1};

        while (p1.X < MIN || p1.X > MAX || p1.Y < MIN || p1.Y > MAX ||
               p2.X < MIN || p2.X > MAX || p2.Y < MIN || p2.Y > MAX ||
               p1.r < 0 || p1.r > MAX) {

            scanf("%d %d %d %d %d %d", &p1.X, &p1.Y, &p1.r, &p2.X, &p2.Y, &p2.r);
            cases[i][0] = p1;
            cases[i][1] = p2;

            if (p1.X < MIN || p1.X > MAX || p1.Y < MIN || p1.Y > MAX ||
                p2.X < MIN || p2.X > MAX || p2.Y < MIN || p2.Y > MAX ||
                p1.r < 0 || p1.r > MAX) {

                printf("좌표는 -10000이상 10000이하의 정수, 거리는 10000이하 자연수를 입력해야합니다.\n");
                printf("[Case %d] position: ", i + 1);

            }
        }
    }

    return cases;
}

int getDistance(CircleData p1, CircleData p2) { //두 원의 중심간 거리를 구합니다.
    return (int)( sqrt( pow(p1.X - p2.X, 2) + pow(p1.Y - p2.Y, 2) ) );
}

int checkCirclePoint(CircleData p1, CircleData p2) { //두 원의 중심의 위치관계를 반환합니다.
    int position = pow(getDistance(p1, p2), 2) - pow(p1.r, 2);

    if (position > 0) return OUTTER;
    else if (position == 0) return INLINE;
    else return INNER;
}