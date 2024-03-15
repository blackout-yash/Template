class LSGTree {
public:
	vector<int> seg, lazy;
	LSGTree(int n) {
		seg.resize(4 * n + 1);
		lazy.resize(4 * n + 1, 9e18);
	}
	 
	void build(int ind, int low, int high, vector <int> &arr) {
		if (low == high) {
			seg[ind] = arr[low];
			return;
		}
 
		int mid = low + (high - low) / 2;
		build(2 * ind + 1, low, mid, arr);
		build(2 * ind + 2, mid + 1, high, arr);
		seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
	}
 
	int query(int ind, int low, int high, int l, int r, int flg) {
		if (lazy[ind] != 9e18) {
            seg[ind] = min(seg[ind], lazy[ind]);
            if (low != high) {
                lazy[2 * ind + 1] = min(lazy[2 * ind + 1], lazy[ind]);
                lazy[2 * ind + 2] = min(lazy[2 * ind + 2], lazy[ind]);
            }
            lazy[ind] = 9e18;
		}
 
		if (high < l or r < low) return 9e18;
		else if (low >= l && high <= r) return seg[ind];
 
		int mid = low + (high - low) / 2;
		int left = query(2 * ind + 1, low, mid, l, r, flg);
		int right = query(2 * ind + 2, mid + 1, high, l, r, flg);
		return min(left, right);
	}
 
	void update(int ind, int low, int high, int l, int r, int val, int query) {
        if (lazy[ind] != 9e18) {
            seg[ind] = min(seg[ind], lazy[ind]);
            if (low != high) {
                lazy[2 * ind + 1] = min(lazy[2 * ind + 1], lazy[ind]);
                lazy[2 * ind + 2] = min(lazy[2 * ind + 2], lazy[ind]);
            }
            lazy[ind] = 9e18;
		}
 
		if (high < l or r < low) return;
		else if (low >= l && high <= r) {
            seg[ind] = min(val, seg[ind]);
            if (low != high) {
                lazy[2 * ind + 1] = min(val, lazy[2 * ind + 1]);
                lazy[2 * ind + 2] = min(val, lazy[2 * ind + 2]);
            }
			return;
		}
 
		int mid = low + (high - low) / 2;
		update(2 * ind + 1, low, mid, l, r, val, query);
		update(2 * ind + 2, mid + 1, high, l, r, val, query);
		seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
	}
};