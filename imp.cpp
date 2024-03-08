#include <vector>
#include <iostream>
using namespace std;
#define int long long

int mul(int a, int b, int m) {a %= m; b %= m; return (((a * b) % m) + m) % m;}

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

int32_t main() {
    int MOD = 998244353;

    int num1 = 5887878787, 
        num2 = 233433333, 
        result = mul(num1, num2, MOD);

    int result1 = modDiv(result, num2, MOD),
        result2 = modDiv(result, num1, MOD); 
    
    if(result1 != num1) {
        cout << "Boom" << endl;
        cout << "Acutual1: " << num1 << endl;
        cout << "Output1: " << result1 << endl;
    }

    if(result2 != num2) {
        cout << "Boom" << endl;
        cout << "Acutual2: " << num2 << endl;
        cout << "Output2: " << result2 << endl;
    }

    return 0;
}