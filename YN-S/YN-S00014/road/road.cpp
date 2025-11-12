#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

struct edge {
	int u, v, w;

	const bool operator < (const edge &ed) const {
		return w < ed.w;
	}
};

struct Dsu {
	vector<int> pa;
	Dsu(int size) {
		pa.resize(size);
		for (int i = 1; i < size; i++)
			pa[i] = i;
	}

	int find(int x) {
		if (pa[x] == x)
			return x;
		pa[x] = find(pa[x]);
		return pa[x];
	}

	void merge(int x, int y) {
		pa[find(x)] = find(y);
	}
};

int c[N], a[15][N];
vector<edge> edges;

int kruskal(Dsu &dsu, vector<edge> &edges) {
	sort(edges.begin(), edges.end());

	int ans = 0;
	for (auto &ed : edges) {
		int u = ed.u, v = ed.v, w = ed.w;

		if (dsu.find(u) != dsu.find(v)) {
			dsu.merge(u, v);
			ans += w;
		}
	}

	return ans;
}

int n, m, k;
int ans = 1e14;

void dfs(int p, vector<edge> edges, int cost) {
	if (p == k + 1) {
		Dsu dsu(n + 128);
		int res = kruskal(dsu, edges) + cost;
		ans = min(ans, res);
		return;
	}

	dfs(p + 1, edges, cost);

	for (int j = 1; j <= n; j++)
		edges.push_back({p + n + 1, j, a[p][j]});

	dfs(p + 1, edges, cost + c[p]);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k;

	vector<edge> edges;
	Dsu dsu(n + k + 128);

	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({u, v, w});
	}

	bool spa = true;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		if (c[i] != 0)
			spa = false;

		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	if (!spa) {
		dfs(1, edges, 0);

		cout << ans;
	} else { // ÌØÊâĞÔÖÊ A
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				edges.push_back({i + n + 1, j, a[i][j]});
			}
		}
		cout << kruskal(dsu, edges);
	}

	return 0;
}