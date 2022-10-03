class SingleHash {
public:
	int mod = 1e9 + 7, base = 31;
	vector <ll> suffix, power;

	SingleHash(string &s) {
		int n = s.length();
		suffix.assign(n + 1, 0);
		power.assign(n + 1, 0);

		power[0] = 1;
		power[1] = base;
		for (int i = n - 1; i >= 0; --i) {
			suffix[i] = (s[i] + (suffix[i + 1] * base)) % mod;
		}

		for (int i = 2; i <= n; ++i) {
			power[i] = (power[i - 1] * base) % mod;
		}
	}

	int substr(int l, int r) {
		ll ans = suffix[l] - (suffix[r + 1] * power[r - l + 1]);
		return ((ans % mod) + mod) % mod;
	}
};
