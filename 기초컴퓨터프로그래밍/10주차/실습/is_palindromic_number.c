#include <stdio.h> 

int is_palindromic_number(unsigned int un) {
    int i, len = 0;
    char str[1000] = "";

    for (i = 0; un > 0; un /= 10, i++) {
        str[i] = un%10 + '0';
        printf("%c", str[i]);
    }

    printf("\n\n");
    
    str[i] = '\0';
    printf("\n%s\n", str);

    for (i--, len = i; i >= 0; i--) {
        if (str[i] != str[len - i]) return 0; 
    }

    return 1;
}

int main(void) {
    int i=0;
    unsigned int rn;

    while (i++ < 100000) {
        rn = myrand();
	if (is_palindromic_number(rn)) {
	    printf("%u is a palindromic number\n", rn);
	    break;
	}
        else   {
	    printf("%u is not a palindromic number\n", rn);
        }
    }
    return 0;
}