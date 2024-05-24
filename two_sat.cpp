// graphR = reverse of graphR
// comp[i] = ID of the SCC containing node i
// answer[i] = whether it is feasible to include i or not

// scc() = strongly connected component
// add_clause_or() = at least one of them is true
// add_clause_xor() = only one of them is true
// add_clause_and() = both of them have the same value

// NOTE:: For the following three add node functions
// int x, bool val: if 'val' is true, we take the variable to be x. Otherwise we take it to be x's complement.

class two_sat {
public:
    int n;
    vector <vector <int>> graph, graphR; 
    vector <int> vis, comp, topo, answer; 

    two_sat(int m) {
        n = m;
        vis.resize(2 * n);
        comp.resize(2 * n);
        answer.resize(2 * n);
        graph.assign(2 * n, vector <int> ());
        graphR.assign(2 * n, vector <int> ());
    }

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graphR[v].push_back(u);
    }

    void add_clause_or(int i, bool f, int j, bool g) {
        add_edge(i + (f ? n : 0), j + (g ? 0 : n));
        add_edge(j + (g ? n : 0), i + (f ? 0 : n));
    }

    void add_clause_xor(int i, bool f, int j, bool g) {
        add_clause_or(i, f, j, g);
        add_clause_or(i, !f, j, !g);
    }

    void add_clause_and(int i, bool f, int j, bool g) {
        add_clause_xor(i, !f, j, g);
    }

    void dfs(int root) {
        vis[root] = true;
        for (int node: graph[root]) {
            if (!vis[node]) dfs(node);
        }
        topo.push_back(root);
    }

    void scc(int root, int id) {
        comp[root] = id;
        vis[root] = true;
        for (int node: graphR[root]) {
            if (!vis[node]) scc(node, id);
        }
    }

    bool satisfiable() {
        for (int i = 0; i < 2 * n; i++) {
            if (!vis[i]) dfs(i);
        }

        int id = 0;
        reverse(topo.begin(), topo.end());
        fill(vis.begin(), vis.end(), false);
        for (int node : topo) {
            if (!vis[node]) scc(node, id++);
        }

        for (int i = 0; i < n; i++) {
            if (comp[i] == comp[i + n]) return false;
            answer[i] = (comp[i] > comp[i + n] ? 1 : 0);
        }

        return true;
    }
};