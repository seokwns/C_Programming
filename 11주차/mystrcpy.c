#include <stdio.h> 
void mystrcpy(char dest[], char src[]) {
	int i = 0, j = 0;
	while (src[i])
		dest[j++] = src[i++];
}
void mystrcpy2(char *dest, char *src) {
	while (*src)
        *(dest++) = *(src++);
}

int main(void) {
	char mystr1[256];
	char mystr2[256];

	gets(mystr1);

	mystrcpy(mystr2, mystr1);
	puts(mystr2);

	mystrcpy2(mystr2, mystr1);
	puts(mystr2);
	return 0;
}