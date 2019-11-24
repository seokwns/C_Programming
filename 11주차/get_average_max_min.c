#include <stdio.h> 
#include <time.h>
#include <stdlib.h>

double get_average_max_min(int nums[100], int *max, int *min) {
    int sum = 0;
    for (*max = *nums, *min = *nums; *nums; nums++) {
        if (*nums < *min) *min = *nums;
        if (*nums > *max) *max = *nums;

        sum += *nums;
    }

    return (double)sum / 100;
}

int main(void) {
	int random_nums[100]={0};
	double average;
	int max, min, i;
    srand(time(0));  

	for (i = 0; i < 10; i++) 
        random_nums[i] = rand()%1000;
        

	average = get_average_max_min(random_nums, &max, &min);
	printf("Average : %.2lf, Max : %d, Min : %d\n",
			average, max, min);  

	return 0;
}