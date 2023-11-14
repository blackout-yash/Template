int gcdExtended(int a, int b, int &x, int &y) {
	if (a == 0) {
		x = 0, y = 1;
		return b;
	}
	int x1, y1, gcd = gcdExtended(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return gcd;
}

int modInverse(int b, int m) {
	int x, y, gcd = gcdExtended(b, m, x, y);
	if (gcd != 1) return -1;
	return (x % m + m) % m;
}

int modDiv(int a, int b, int m) {
	a = a % m;
	int inv = modInverse(b, m);
	if (inv == -1) return -1;
	return (inv * a) % m;
}