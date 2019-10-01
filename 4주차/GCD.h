int GCD(int a, int b) {
	int start = (a > b) ? b : a;
	int i;

	for (i = start; i > 0; i--) {
		if (a % i == 0 && b % i == 0) return i;
	}

	return 1;
}
