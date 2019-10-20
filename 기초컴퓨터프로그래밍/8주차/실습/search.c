#include <stdio.h> 
#define LENGTH 5

int main(void) {
    double a[LENGTH] = {1.1, 2.2, 3.3, 2.2, 1.1};
    double v;
    int i;
    
    scanf("%lf", &v);

    for(i = LENGTH - 1; i >= 0; i--) {
        if(a[i] == v) {
            printf("Found : %d\n", i);
            return 0;
        }
    }

    if(i == -1) printf("Not Found : -1\n");

    return 0;
}