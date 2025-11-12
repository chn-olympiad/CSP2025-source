#include <bits/stdc++.h>

#define int long long

struct E {
	int u, v, w;
	int c;
};

int dsu[20010];
bool enabled[20010];
int ext[20010];
int n, m, k;

int find(int x) {
	return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

int kruscal(const std::vector<E>& edges) {
	std::iota(dsu, dsu + n + k + 1, 0);
	int res = 0;
	for (auto&& e : edges) {
		if (!enabled[e.c]) {
			continue;
		}
		int ru = find(e.u), rv = find(e.v);
		if (ru == rv) {
			continue;
		}
		// printf("%d <-> %d\n", e.u, e.v);
		res += e.w;
		dsu[ru] = find(rv);
	}
	// printf("%d,%d\n",enabled[1],enabled[2]);
	// printf("%d,\n\n", res);
	return res;
}

int dfs(int idx, const std::vector<E>& edges) {
	if (idx == 0) {
		return kruscal(edges);
	}
	
	int res = LONG_LONG_MAX;
	res = std::min(res, dfs(idx - 1, edges));
	enabled[idx] = true;
	res = std::min(res, dfs(idx - 1, edges) + ext[idx]);
	enabled[idx] = false;
	return res;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	enabled[0] = true;
	std::cin >> n >> m >> k;
	std::vector<E> edges(m);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		edges[i] = {u, v, w, 0};
	}
	for (int i = n + 1; i <= n + k; i++) {
		std::cin >> ext[i - n];
		for (int j = 1; j <= n; j++) {
			int w;
			std::cin >> w;
			edges.push_back({i, j, w, i - n});
		}
	}
	std::sort(edges.begin(), edges.end(), [](auto&& a, auto&& b) {
		return a.w < b.w;
	});
	std::cout << dfs(k, edges) << '\n';
}


