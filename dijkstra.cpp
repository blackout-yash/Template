vector <vector<pair<int, int>>> graph(n);
vector <int> vis(n);

int dijkstra(int source) {
	set <pair<int, int>> s;
	s.insert({0, source});
	dis[source] = 0;

	while (!s.empty()) {
		auto node = *s.begin();
		int weight = node.first, root = node.second;
		s.erase(s.begin());

		if (vis[root]) continue;
		else vis[root] = 1;

		for (auto x : graph[root]) {
			int child = x.first,
			    weightChild = x.second;

			if (dis[root] + weightChild < dis[child]) {
				dis[child] = dis[root] + weightChild;
				s.insert({dis[child], child});
			}
		}
	}
}