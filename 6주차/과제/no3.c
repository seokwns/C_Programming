#include <stdio.h> 

int main(void) {
    int i;                  // index
    unsigned int num = 0;	// number
    unsigned int nd;
    char str[11];           // Max Digits + 1
    char rstr[11];          // Max Digits + 1

    scanf("%d",&num);

    for (i = num, nd = 0; i > 0; i /= 10, nd++) {
        rstr[nd] = i%10 + '0';
    }

    for (i = 0; i < nd; i++) {
        str[i] = rstr[nd - 1 - i];
    }

    printf("%d is [%s]\n",num, str);
    return 0;
}