#include <stdio.h>
#include "str2int.h"

int main(void) {
    char str[] = "-31415926";
    int n = str2int(str);
    printf("%s -> %d", str, n);
    
    return 0;
}