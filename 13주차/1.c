#include <stdio.h> 
int main(void) 
{
    int x=11, y=22, z=33, i;

    int *p[3] = {&x, &y, &z};

    for (i=0; i<3; i++) printf("%d\n", *p[i]);

    return 0;
}
