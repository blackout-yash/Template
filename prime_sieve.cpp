#include <bitset>
#define int long long

vector <int> prime;
const int range = 1e7;
bitset < range + 5 > b;

void sieve() {
    b.set();
    b[0] = b[1] = 0;
    for (int i = 2; i <= range; i++) {
        if (b[i]) {
            prime.push_back(i);
            for (int j = i * i; j <= range; j += i) b[j] = 0;
        }
    }
}
