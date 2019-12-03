#include <stdio.h> 
#include <string.h>

int main(void)
{
	char *pcolor[] = {"red", "orange",
		"yellow", "green", "blue", 
		"indigo", "violet", "purple",
 		"white", "ivory", "gray",
		"black", "cyan", "pink", 
		NULL};

	int i, j;
    const int LEN = 14;
    for (i = 0; i < LEN; i++) {
        for (j = 0; j < LEN; j++) {
            int cmp = strcmp(pcolor[i], pcolor[j]);
            if (cmp == -1) {
                char *tmp = (pcolor[i]);
                (pcolor[i]) = (pcolor[j]);
                (pcolor[j]) = tmp;
            }
        }
    }

    for (i = 0; i < LEN; i++) {
        printf("%s\n", pcolor[i]);
    }

	return 0;
}