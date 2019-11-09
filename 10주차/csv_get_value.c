#include <stdio.h> 
int csv_get_value(char str[]) {
    static int i = 0;
	int num = 0;

	if (i < 0) return -1;

	while (str[i] >= '0' && str[i] <= '9') {
		num = num * 10 + (str[i] - '0');
		i++;
	}

	if (!str[i]) i =- 1;
	else i++;
		
	return num;
}

int main(void) {
    int num;				
	char str[] = "123,456,789";

	while ((num=csv_get_value(str)) >= 0)
		printf("%d\n", num);
    return 0;
}