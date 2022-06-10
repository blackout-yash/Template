const int n = 1e6;
vector <int> factInv(n), numInv(n), fact(n);

void invNum(int p) {
	numInv[0] = numInv[1] = 1;
	for (int i = 2; i < n; i++)
		numInv[i] = numInv[p % i] * (p - p / i) % p;
}

void invFact(int p) {
	factInv[0] = factInv[1] = 1;

	for (int i = 2; i < n; i++)
		factInv[i] = (numInv[i] * factInv[i - 1]) % p;
}

void _fact(int p) {
	fact[0] = 1;

	for (int i = 1; i < n; i++) {
		fact[i] = (fact[i - 1] * i) % p;
	}
}

void preCompute(int p = MOD) {
	invNum(p);
	invFact(p);
	_fact(p);
}

int nCr(int n, int r, int p = MOD) {
	return ((fact[n] * factInv[r]) % p * factInv[n - r]) % p;
}