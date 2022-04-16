const int n = 2 * 1e5;
vector <int> parent(n), ssize(n);
void makeSet(int v) {
	parent[v] = v;
	ssize[v] = 1;
}

int findSet(int v) {
	if (v == parent[v]) return v;
	return parent[v] = findSet(parent[v]);
}

void unionSets(int a, int b) {
	a = findSet(a);
	b = findSet(b);
	if (a != b) {
		if (ssize[a] < ssize[b]) swap(a, b);
		parent[b] = a;
		ssize[a] += ssize[b];
	}
}