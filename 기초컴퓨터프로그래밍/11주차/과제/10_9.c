#include <stdio.h>

void swap(double *a, double *b) {
    double tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse(double a[], int len) {
    int i;

    for (i = 0; i < len / 2; i++) 
        swap(&a[i], &a[len - 1 - i]);
}

int main(void) {
    double a[] = {1.1, 3.3, 5.5, 2.2, 6.6, 4.4, 7.7};
    double temp;
    int len = 7, i;

    reverse(a, len);

    for (i = 0; i < len; ++i) 
        printf("%g ", a[i]);
    printf("\n");
    
    return 0;
}