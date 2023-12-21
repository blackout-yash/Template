vector <int> factors(int n) {
	vector <int> factor;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			if (n / i != i) factor.push_back(n / i);
			factor.push_back(i);
		}
	} 
	return factor;
}
