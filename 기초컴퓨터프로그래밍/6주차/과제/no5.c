#include <stdio.h> 

int main(void)
{
    int i,j;
    int n1,n2,n3;

    for(j=0; j<10 ; ++j) {
        n1=9 - j;
        n2=1 + 1.5 * j;
        n3=9.5 - (0.5 * j);
        for(i=0;i<n1;++i) printf(". ");
        for(i=0;i<n2;++i) printf("* ");
        for(i=0;i<n3;++i) printf(". ");
        printf("\n");
    }
    for(j=0; j<9 ; ++j) {
        n1=2 * (j + 1);
        n2=13 - (1.5 * j);
        n3=4.5 - (0.5 * j);
        for(i=0;i<n1;++i) printf(". ");
        for(i=0;i<n2;++i) printf("* ");
        for(i=0;i<n3;++i) printf(". ");
        printf("\n");
    }
    return 0;
}