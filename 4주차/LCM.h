int LCM(int a, int b) {
	int gcd = GCD(a, b);
	int i;

	if (gcd == a || gcd == b) return ((a > b) ? a : b);
	else {
		for (i = 1; i > 0; i++) {
			if ((gcd * i) % a == 0 && (gcd * i) % b == 0) return gcd * i;
		}
	}
}