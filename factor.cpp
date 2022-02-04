vector <int> factors(int n) {
	vector <int> factor;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			if (n / i != i) factor.pb(n / i);
			factor.pb(i);
		}
	} return factor;
}