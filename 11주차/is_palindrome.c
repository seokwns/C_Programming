#include <stdio.h>
#include <ctype.h>
/**
* @brief : Check if the given str is a palindrome
* @return: 1 if the given str is a palindrome, zero otherwise
* @param : str - pointers to the null-terminated byte string to check
*/
int ispalindrome(char *str) {
    int i, len;
    
    for(len = 0; *(str + len); len++) ;
    for(len--, i = 0; *(str + i); i++) {
        if (*(str + i) != *(str + len - i)) return 0;
    }
    return 1;
}

int main(void) {
    char buffer[1024];

    gets(buffer);
    printf("[%s] is ", buffer);
    if (ispalindrome(buffer))
        puts("a palindrome");
    else
        puts("not a palindrome");
    return 0;
}