#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	int n, m, k;
	std::cin >> n >> m >> k;
	
	std::vector<std::tuple<int, int, int>> es_(m), es(n - 1);
	for (int i = 0; i < m; i ++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		-- u, -- v;
		es_[i] = std::make_tuple(w, u, v);
	}
	
	std::sort(es_.begin(), es_.end());
	
	std::vector<int> fa(n + k);
	auto find = [&](int u) {
		while (fa[u] != u) {
			u = fa[u] = fa[fa[u]];
		}
		return u;
	};
	
	auto mst = [&](const std::vector<std::tuple<int, int, int>> &es) {
		std::iota(fa.begin(), fa.end(), 0);
		i64 ans = 0;
		for (auto _ : es) {
			int w, u, v;
			std::tie(w, u, v) = _;
			if (find(u) != find(v)) {
				ans += w;
				fa[find(u)] = find(v);
			}
		}
		return ans;
	};
	
	std::iota(fa.begin(), fa.end(), 0);
	i64 ans = 0;
	for (int i = 0; i < m; i ++) {
		int w, u, v;
		std::tie(w, u, v) = es_[i];
		if (find(u) != find(v)) {
			ans += w;
			fa[find(u)] = find(v);
			es.push_back(std::make_tuple(w, u, v));
		}
	}
	
	std::vector<int> c(n);
	std::vector<std::vector<std::tuple<int, int, int>>> a(k, std::vector<std::tuple<int, int, int>>(n));
	for (int i = 0; i < k; i ++) {
		std::cin >> c[i];
		for (int j = 0, w; j < n; j ++) {
			std::cin >> w;
			a[i][j] = std::make_tuple(w, i + n, j);
		}
		std::sort(a[i].begin(), a[i].end());
	}
	
	for (int S = 1; S < 1 << k; S ++) {
		auto e = es;
		i64 cost = 0;
		for (int i = 0; i < k; i ++) {
			if (S >> i & 1) {
				cost += c[i];
				e.insert(e.end(), a[i].begin(), a[i].end());
			}
		}
		std::sort(e.begin(), e.end());
		ans = std::min(ans, cost + mst(e));
	}
	
	std::cout << ans << '\n';

	return 0;
}

