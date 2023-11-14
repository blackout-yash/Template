vector <int> primeFactors(int n) {
	vector <int> factor;
    while (n % 2 == 0) {  
        factor.push_back(2);  
        n = n / 2;  
    } 
	for (int i = 1; i <= sqrt(n); i++) {
		while (n % i == 0) {  
            factor.push_back(i);  
            n = n / i;  
        } 
	} 
    if (n > 2) factor.push_back(n);

	return factor;
}