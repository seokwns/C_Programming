#include <math.h>
#include <ctype.h>

int str2int(char str[]) {
    int i, result = 0;
    
    for (int i = 0; str[i]; i++) {
        if(isdigit(str[i])) {
            result = result * 10 + (str[i] - '0');
        }
    }

    if(str[0] == '-') {
        result *= -1;
    }

    return result;
}