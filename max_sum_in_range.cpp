class Node {
    public:
    int sum, maxPrefix, maxSuffix, maxSum;

    Node(int x) {
        sum = maxPrefix = maxSuffix = maxSum = x;
    }
};

class SGTree {
public:
	vector <Node> seg;
	SGTree(int n) {
        seg.resize(4 * n + 1, Node(0));
	}
	
    Node operation(Node &left, Node &right) {
        Node curr(0);
        curr.sum = left.sum + right.sum;
        curr.maxPrefix = max(left.maxPrefix, left.sum + right.maxPrefix);
        curr.maxSuffix = max(left.maxSuffix + right.sum, right.maxSuffix);
        curr.maxSum = max({left.maxSum, right.maxSum, left.maxSuffix + right.maxPrefix});
        return curr;
    }

	Node query(int ind, int low, int high, int l, int r) {
        // Take care of Integer Overflow
		if (r < low || high < l) return Node(-1e13);
		else if (low >= l && high <= r) return seg[ind];

		int mid = low + (high - low) / 2;
		Node left = query(2 * ind + 1, low, mid, l, r);
		Node right = query(2 * ind + 2, mid + 1, high, l, r);

		return operation(left, right);
	}

    int ask(int ind, int low, int high, int l, int r) {
        Node curr = query(ind, low, high, l, r);
        return max({curr.sum, curr.maxPrefix, curr.maxSuffix, curr.maxSum});
    }

	void update(int ind, int low, int high, int i, int val) {
		if (low == high) {
            // Updating the value
			seg[ind] = Node(val);
			return;
		}

		int mid = low + (high - low) / 2;
		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
		else update(2 * ind + 2, mid + 1, high, i, val);

		seg[ind] = operation(seg[2 * ind + 1], seg[2 * ind + 2]);
	}
};