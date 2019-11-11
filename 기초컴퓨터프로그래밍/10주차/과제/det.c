#include <stdio.h> 
double det_2x2(double M[2][2]) {
    return (M[0][0] * M[1][1] - M[0][1] * M[1][0]);
}

int main(void) {
    double M1[2][2] = { {1.7, 3.2}, {2.3, 4.1} };

    printf("Matrix M = \n");
    printf("    [ %6.2f %6.2f ]\n", M1[0][0], M1[0][1]);
    printf("    [ %6.2f %6.2f ]\n", M1[1][0], M1[1][1]);

    printf("det(M) = %lf\n", det_2x2(M1));

    return 0;
} 