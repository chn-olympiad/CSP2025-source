#include <bits/stdc++.h>

int n, m, k;

long long mat[1005][1005];

struct Edge {
	int u, v;
	long long cost;
};

inline bool cmp1(const Edge &a, const Edge &b) {
	return a.cost < b.cost;
}

inline int find_fa(std::vector<int> &fa, int x) {
	if (fa[x] == x)
		return x;

	return fa[x] = find_fa(fa, fa[x]);
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	std::cin >> n >> m >> k;

	if (k == 0) {
		std::vector<Edge> g(m);
		for (int i = 0; i < m; ++i)
			std::cin >> g[i].u >> g[i].v >> g[i].cost;

		std::sort(g.begin(), g.end(), cmp1);

		std::vector<int> fa(n + 1);
		for (int i = 0; i <= n; ++i)
			fa[i] = i;

		long long ans = 0;
		for (auto &e : g) {
			int u = e.u, v = e.v;
			int uf = find_fa(fa, u), uv = find_fa(fa, v);

			if (uf == uv)
				continue;

			fa[uf] = uv;
			ans += e.cost;
		}

		std::cout << ans << std::endl;
		return 0;
	}

	for (int i = 0; i < 1005; ++i)
		for (int j = 0; j < 1005; ++j)
			mat[i][j] = LLONG_MAX;

	for (int i = 0; i < m; ++i) {
		int u, v;
		long long w;
		std::cin >> u >> v >> w;
		if (u > v)
			std::swap(u, v);

		mat[u][v] = w;
	}

	std::vector<long long> cost_by_vilage(n + 1);
	while (k--) {
		int c;
		std::cin >> c;

		for (int i = 1; i <= n; ++i)
			std::cin >> cost_by_vilage[i];

		for (int i = 1; i <= n; ++i)
			for (int j = i + 1; j <= n; ++j)
				mat[i][j] = std::min(mat[i][j], cost_by_vilage[i] + cost_by_vilage[j]);
	}

	std::vector<Edge> g;
	g.reserve((n - 1) * n / 2);
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			g.push_back({i, j, mat[i][j]});

	std::sort(g.begin(), g.end(), cmp1);

	std::vector<int> fa(n + 1);
	for (int i = 0; i <= n; ++i)
		fa[i] = i;

	long long ans = 0;
	int cnt = 0;
	for (auto &e : g) {
		// std::cout << "Edge : " << e.u << " " << e.v << " " << e.cost << std::endl;

		int u = e.u, v = e.v;
		int uf = find_fa(fa, u), uv = find_fa(fa, v);

		if (uf == uv)
			continue;

		fa[uf] = uv;
		ans += e.cost;
		cnt++;

		if (cnt == n - 1)
			break;
	}

	std::cout << ans << std::endl;

	fclose(stdin);
	fclose(stdout);

	return 0;
}
