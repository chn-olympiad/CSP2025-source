//! expect: 64
#include <bits/stdc++.h>
using i64 = long long;
constexpr int ROOT = 1, N = 1e4 + 15, K = 11;

template <typename T>
void read(T& v) {
	v = 0; char c;
	while (!isdigit(c = getchar()));
	do { v = (v << 1) + (v << 3) + (c ^ '0'); } while (isdigit(c = getchar()));
}

struct Edge {
	int v; i64 w;
};

namespace std {

template <>
struct less<Edge> {
	auto operator () (const Edge& l, const Edge& r) const -> bool {
		return l.w > r.w;
	}
};

}

int n, m, k, tag, vis[N], len[N], uw[K], up[K][N];
std::vector<Edge> to[N];

void add(int u, int v, int w) {
	to[u].emplace_back(Edge{ v, w }), 
	to[v].emplace_back(Edge{ u, w });
}

void update(int u) {
	for (int v = 1; v <= n; v++) add(u + n, v, up[u][v]);
}

auto solve(int tot) -> i64 {
	i64 c = 0;
	std::priority_queue<Edge> q{};
	vis[ROOT] = ++tag;
	for (const auto &it : to[ROOT]) q.emplace(it);
	for (int cnt = 1; cnt != tot + n; ) {
		auto e = q.top();
		q.pop();
		if (vis[e.v] == tag) continue;
		c += e.w, vis[e.v] = tag, cnt++;
		for (const auto &it : to[e.v]) if (vis[it.v] != tag) q.emplace(it);
	}
	return c;
}

auto main() -> int {
	freopen("road.in", "r", stdin), freopen("road.out", "w", stdout);
	read(n), read(m), read(k);
	for (int i = 0, u, v, w; i != m; i++) read(u), read(v), read(w), add(u, v, w);
	for (int i = 1; i <= k; i++) read(uw[i]), std::for_each(up[i] + 1, up[i] + 1 + n, read<int>);
	for (int i = 1; i <= n; i++) len[i] = to[i].size();
	i64 ans = 1e17;
	for (int i = 0; i != (1 << k); i++) {
		i64 c = 0;
		int tot = 0;
		for (int j = 0; j != k; j++)
			if (i & (1 << j)) update(j + 1), c += uw[j + 1], tot++;
		ans = std::min(ans, solve(tot) + c);
		for (int j = 1; j <= n; j++) to[j].resize(len[j]);
		for (int j = 1; j <= k; j++) to[j + n].clear();
	}
	printf("%lld", ans);
}
