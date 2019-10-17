#include <stdio.h>


int main(void) {
    int i; // index
    unsigned int num = 0; // number
    char str[] = "31415926";

    for (i = 0; str[i]; i++) {
	    num = num * 10 + (str[i] - '0');
    }

    printf("[%s] is %d\n",str,num);
    return 0;
}