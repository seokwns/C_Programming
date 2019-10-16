#include <stdio.h> 
#include <time.h>

#define	MAX_NUM	1000000

int primes[1 + MAX_NUM];

void init(void) { //에라토스테네스의 채를 이용하여 MAX_NUM까지의 숫자들의 소수 여부를 판별합니다.
	int i, j;
    for (i = 2; i * i <= MAX_NUM; i++) {
    	if(!primes[i]) {
    		for (j = 2 * i; j <= MAX_NUM; j += i) {
    			primes[j] = 1;
			}	
    	}
	}
}
//LG GRAM 17 i7 최고성능 기준 최대 19ms, 평균 20~23ms의 속도를 보임.

int is_prime(int n) {
	if(n == 1) {
		init();
		return 0;
	}
	return !primes[n];
}

int main(void)
{
    int n=0, nprime=0, max_prime=0;
    clock_t t_start, t_end;
    double t_elapsed;
	
    printf("**************************************************\n");
	
    t_start = clock();
    for (n=1; n<=MAX_NUM; n++)	{
	if (is_prime(n)) {
	    nprime++;
	    max_prime = n;
	}
	if (n%(MAX_NUM/50)==0) printf("*");
    }
    t_end = clock();
    t_elapsed = 1000.0*(t_end - t_start)/CLOCKS_PER_SEC;
	
    printf("\n# of Prime numbers between 1 and %d : %d\n", MAX_NUM, nprime);
    printf("The maximum Prime number <= %d : %d\n", MAX_NUM, max_prime);        
    printf("It takes %.2f(ms) to carry out this computation", t_elapsed);
    return 0;
}