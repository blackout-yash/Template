vector <int> primeFactors(int n) {
	vector <int> factor;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {  
            		factor.push_back(i);  
            		n = n / i;  
		} 
	} 
	if (n >= 2) factor.push_back(n);
	return factor;
}
