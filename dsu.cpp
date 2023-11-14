class DSU {
public:
	vector <int> parent, size;
	DSU (int n) {
		parent.resize(n);
		size.resize(n);
	}
	
	// DSU (int n) {
	// 	parent.resize(n);
	// 	size.resize(n);
	// 	for(int i = 0; i < n; i++) {
	// 		parent[i] = i;
	// 		size[i] = 1;
	// 	}
	// }

	void makeSet(int v) {
		parent[v] = v;
		size[v] = 1;
	}

	int findSet(int v) {
		if (v == parent[v]) return v;
		return parent[v] = findSet(parent[v]);
	}

	void unionSets(int a, int b) {
		a = findSet(a);
		b = findSet(b);
		if (a != b) {
			if (size[a] < size[b]) swap(a, b);
			parent[b] = a;
			size[a] += size[b];
		}
	}
};
