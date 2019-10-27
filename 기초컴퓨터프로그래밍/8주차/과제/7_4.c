#include <stdio.h>

void star();
void hello();

int main(void) {
    star();
    hello();
    star();
}

void star() {
    printf("*****");
}

void hello() {
    printf(" Hello C World ");
}