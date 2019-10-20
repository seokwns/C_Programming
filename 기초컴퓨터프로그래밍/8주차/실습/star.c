#include <stdio.h> 

void line(int n1, int n2, int n3, int n4) {
    int i;
    
    for(i = 0; i < n1; ++i) printf(". ");  
    for(i = 0; i < n2; ++i) printf("* ");  
    for(i = 0; i < n3; ++i) printf(". ");  
    for(i = 0; i < n4; ++i) printf("* ");  
    printf("\n");
}

int main(void) {
    int j;

    for(j = 0; j < 10; ++j)
        line(9 - j, 2 * j + 1, 9 - j, 0);
    for(j = 0; j < 9; ++j)
        line(0, j + 1, 17 - (2 * j), j + 1);
        
    return 0;
}