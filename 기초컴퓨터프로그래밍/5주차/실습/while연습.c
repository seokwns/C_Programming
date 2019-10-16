#include <stdio.h> 

int main(void) {
    int ai = 3;
    
    while (ai <= 48) {
	    printf("%d ", ai);
	    ai *= 2;
    }
    printf("\n");

    return 0;
}