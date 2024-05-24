// It can be shown that the answer can be expressed as an irreducible fraction p/q, 
// where p and q are integers and q != 0 (mod 998244353). Output the integer equal 
// to p⋅(q^−1) mod 998244353. In other words, output such an integer x that 
// 0 ≤ x < 998244353 and x⋅q ≡ p (mod 998244353).

// p.(q^-1) mod MOD => (p.(q^-1)) % MOD == 1
// ans = p.(q^-1) mod MOD

int mul(int a, int b, int m = MOD) {a %= m; b %= m; return (((a * b) % m) + m) % m;}
int inv(int x, int m = MOD){
	int ans = 1, n = m - 2;
	while(n) {
		if(n & 1) ans = mul(ans, x);
		x = mul(x, x); n >>= 1;
	} 
	return ans;
}
int invMul(int a, int b, int m = MOD) {a %= m; b = inv(b); return mul(a, b);}