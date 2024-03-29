class SGTree {
public:
	vector<int> seg;
	SGTree(int n) {
		seg.resize(4 * n + 1);
	}
 
	void build(int ind, int low, int high, vector <int> &arr) {
		if (low == high) {
			seg[ind] = arr[low];
			return;
		}
 
		int mid = low + (high - low) / 2;
		build(2 * ind + 1, low, mid, arr);
		build(2 * ind + 2, mid + 1, high, arr);
 
		seg[ind] = __gcd(seg[2 * ind + 1], seg[2 * ind + 2]);
	}
 
	int query(int ind, int low, int high, int l, int r) {
		if (r < low || high < l) return -1;
		if (low >= l && high <= r) return seg[ind];
 
		int mid = low + (high - low) / 2;
		int left = query(2 * ind + 1, low, mid, l, r);
		int right = query(2 * ind + 2, mid + 1, high, l, r);
 
        	if(left == -1 && right == -1) return -1;
        	else if(left == -1) return right;
        	else if(right == -1) return left;
		return __gcd(left, right);
	}
 
	void update(int ind, int low, int high, int i, int val) {
		if (low == high) {
			// seg[ind] -= val;
			seg[ind] = val;
			return;
		}
 
		int mid = low + (high - low) / 2;
		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
		else update(2 * ind + 2, mid + 1, high, i, val);
 
		seg[ind] = __gcd(seg[2 * ind + 1], seg[2 * ind + 2]);
	}
};
