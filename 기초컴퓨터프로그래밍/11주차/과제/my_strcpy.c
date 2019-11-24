#include <stdio.h> 
void my_strcpy(char *psrc, char *pdst) {
    while (*psrc) {
        *pdst++ = *psrc++;
    }
}
int main(void) {
	char src_msg[] = "Hello, World\n";
	char dst_msg[256];

	my_strcpy(src_msg, dst_msg);
	printf("%s%s", src_msg, dst_msg);
	return 0;
}