#include <stdio.h> 
/**
* @brief : print out a given positive integer parameter n in binary
* @return: Non-zero value if n is a positive integer, zero otherwise
* @param : n - an integer to be printed out in binary
*/
int print_binary(int n) {
    if (n == 0) {
        return 0;
    }

    printf("%d = ", n);

	char rstr[256], str[256];
    int i, j;

    for (i = 0; n > 0; i++) {
        rstr[i] = n%2 + '0';
        n /= 2;
    }

    for (j = 0; rstr[j]; j++) {
        str[j] = rstr[i - 1 - j];
    }
    printf("%s in binary\n", str);
}

int main(void) {
    int n = 1;

    while (n > 0) {
        printf("Enter a positive integer (Enter 0 to Quit) : ");
        scanf("%d", &n);
        print_binary(n);
    }

    return 0;
}