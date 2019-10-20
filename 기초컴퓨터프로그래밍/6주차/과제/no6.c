#include <stdio.h> 
double my_abs(double f) {
	if (f<0) f=-f;
	return f;
}

int main() {
	double x = 25;
	double epsilon = 0.01;
	double step = epsilon * epsilon;
	double ans = 0.0;
	int numGuesses = 0;
	
	double diff = my_abs(ans*ans - x);
	
	while (diff >= epsilon && ans <= x) {
		ans = ans + step;
		diff = my_abs(ans*ans -x);
		numGuesses = numGuesses + 1;
	}
	
	printf("# of Guesses = %d\n", numGuesses);
	
	if (diff >= epsilon)
		printf("Failed on square root of %f\n", x);
	else
		printf("%.20f is close to square root of %f", ans, x);
	
	return 0;
}