#include <stdio.h>

int is_palindromic_number(int n) {
    int i, len = 0;
    char str[100] = "";

    for (i = 0; n > 0; n /= 10, i++) {
        str[i] = n%10 + '0';
    }

    for (i--, len = i; i >= 0; i--) {
        if (str[i] != str[len - i]) return 0; 
    }

    return 1;
}

int main(void) {
    unsigned int n;
	
    printf("Enter a positive integer : ");
    scanf("%d", &n);
	
    if (is_palindromic_number(n)) printf("is a palindromic number\n");
    else printf("is not a palindromic number\n");

    return 0;
}