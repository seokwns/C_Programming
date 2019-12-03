#include <stdio.h> 
#include <string.h>
// substitute all och characters in a 
// string pointed by str with nch
void strsubch(char *str, char och, char nch){
	for (; *str != '\0'; str++)
		if (*str == och) *str = nch;
}

int main(void)
{
	char csv[] = "123,456,789,234,567,890";
	char nsv[sizeof(csv)];
	char *pszval_array[100] = {nsv, NULL};

	char *pnsv = nsv;
	int i = 1;

	strcpy(nsv, csv);

	int x = 0;
	for (x = 0; nsv[x]; x++) {
		if (nsv[x - 1] == ',') {
			pszval_array[i] = &nsv[x];
			i++;
		}
	}

	strsubch(nsv, ',', '\0');

	for (i = 0; pszval_array[i] != NULL; i++)
		puts(pszval_array[i]);

	return 0;
}