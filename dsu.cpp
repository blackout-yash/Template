const int n = 5 * 1e5;
vector <int> parent(n), _size(n);
void makeSet(int v) {
	parent[v] = v;
	_size[v] = 1;
}

int findSet(int v) {
	if (v == parent[v]) return v;
	return parent[v] = findSet(parent[v]);
}

void unionSets(int a, int b) {
	a = findSet(a);
	b = findSet(b);
	if (a != b) {
		if (_size[a] < _size[b]) swap(a, b);
		parent[b] = a;
		_size[a] += _size[b];
	}
}
