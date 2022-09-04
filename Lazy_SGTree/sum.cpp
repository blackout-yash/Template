class LSGTree {
public:
	vector<int> tree, lazy;
	LSGTree(int n) {
		tree.resize(4 * n + 1);
		lazy.resize(4 * n + 1);
	}

	void build(int ind, int start, int end, vector <int> &arr) {
		if (start == end) {
			tree[ind] = arr[start];
			return;
		}

		int mid = start + (end - start) / 2;
		build(ind * 2 + 1, start, mid, arr);
		build(ind * 2 + 2, mid + 1, end, arr);

		tree[ind] = tree[ind * 2 + 1] + tree[ind * 2 + 2];
	}

	int query(int ind, int start, int end, int i, int j) {
		if (lazy[ind] != 0) {
			tree[ind] += (end - start + 1) * lazy[ind];
			if (start != end) {
				lazy[ind * 2 + 1] += lazy[ind];
				lazy[ind * 2 + 2] += lazy[ind];
			}
			lazy[ind] = 0;
		}

		if (start > end || start > j || end < i) return 0;

		if (start >= i && end <= j)
			return tree[ind];

		int mid = start + (end - start) / 2;
		int left = query(2 * ind + 1, start, mid, i, j);
		int right = query(2 * ind + 2, mid + 1, end, i, j);
		return (left + right);
	}

	void update(int ind, int start, int end, int i, int j, int val) {
		if (lazy[ind] != 0) {
			tree[ind] += (end - start + 1) * lazy[ind];
			if (start != end) {
				lazy[ind * 2 + 1] += lazy[ind];
				lazy[ind * 2 + 2] += lazy[ind];
			}
			lazy[ind] = 0;
		}

		if (start > end || start > j || end < i) return;

		if (start >= i && end <= j) {
			tree[ind] += (end - start + 1) * val;
			if (start != end) {
				lazy[ind * 2 + 1] += val;
				lazy[ind * 2 + 2] += val;
			}
			return;
		}

		int mid = start + (end - start) / 2;
		update(ind * 2 + 1, start, mid, i, j, val);
		update(ind * 2 + 2, mid + 1, end, i, j, val);
		tree[ind] = tree[ind * 2 + 1] + tree[ind * 2 + 2];
	}
};