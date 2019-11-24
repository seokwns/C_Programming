#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double d = 5.1;
    double *p;

    p = &d;
    *p = 3.8;
    printf("*p == %g, d == %g\n", *p, d);
    p = (double*) malloc( sizeof(double) );
    *p = 5.8;
    printf("*p == %g\n", *p);

    free( p );

    return 0;
}