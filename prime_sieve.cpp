const int n = 1e7;
bitset < 1e7 + 5 > b;
vector <int> prime;

void sieve() {
    b.set();

    b[0] = b[1] = 0;

    for (long long i = 2; i <= n; i++) {
        if (b[i]) {
            prime.push_back(i);
            for (long long j = i * i; j <= n; j += i) {
                b[j] = 0;
            }
        }
    }
}
