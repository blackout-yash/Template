class SQRT {
public:
	int n;
	vector <int> blocks;
	SQRT(int m) {
		n = sqrt(m) + 1;
		blocks.resize(n);
	}

	void build(int m, vector <int> &arr) {
		for(int i = 0; i < m; i++) blocks[i / n] += arr[i];
	}

	int query(int l, int r, vector <int> &arr) {
		int ans = 0,
			low = l / n,  
			high = r / n;
		
		if (low == high) {
			for (int i = l; i <= r; i++) ans += arr[i];
		} else {
			int end = ((low + 1) * n) - 1,
				start = high * n;
			for (int i = l; i <= end; i++) ans += arr[i];
			for (int i = low + 1; i <= high - 1; i++) ans += blocks[i];
			for (int i = start; i <= r; i++) ans += arr[i];
		}
		return ans;
	}
};