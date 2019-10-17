#include <stdio.h>


int main(void) {
    int i;                  // index
    int num = 0, sum = 0;	// number
    char csv[256];

    scanf("%s",csv);

    for (i = 0; csv[i] != '\0'; i++) {
        if (csv[i] != ',') {
            num = num * 10 + (csv[i] - '0');
        } else {
            sum += num;
            num = 0;
        }
    }
    sum += num;
    printf("Sum of all values in CSV[%s] : %d", csv, sum);

    return 0;
}