#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 10005, K = 12;
constexpr i64 inf = 4E18;

// DSU
int f[N];
void init(int n) {
	std::iota(f, f + n, 0);
}
int find(int x) {
	while (f[x] != x) x = f[x] = f[f[x]];
	return x;
}
bool merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return false;
	f[y] = x;
	return true;
}

int n, m, k, c[K], pos[K];
std::vector<std::array<int, 3>> e, ke[K], t;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

	std::cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int x, y, w;
		std::cin >> x >> y >> w;
		x--, y--;
		e.push_back({w, x, y});
	}
	for (int i = 0; i < k; i++) {
		std::cin >> c[i];
		for (int j = 0; j < n; j++) {
			int w;
			std::cin >> w;
			ke[i].push_back({w, n + i, j});
		}
		std::sort(ke[i].begin(), ke[i].end());
	}
	std::sort(e.begin(), e.end());
	
	init(n);
	for(auto [w, x, y] : e) {
		if (merge(x, y)) t.push_back({w, x, y});
	}
	i64 ans = inf;
	for (int mask = 0; mask < 1 << k; mask++) {
		init(n + k);
		i64 cur = 0;
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
		for (int i = 0; i < k; i++) if (mask >> i & 1) {
			cur += c[i];
			q.emplace(ke[i][pos[i] = 0][0], i);
		}
		q.emplace(t[pos[k] = 0][0], k);
		int ok = 0, cn = n + __builtin_popcount(mask);
		while (!q.empty() && ok < cn - 1) {
			auto [_, idx] = q.top(); q.pop();
			const auto &ce = (idx == k ? t : ke[idx]);
			auto [w, x, y] = ce[pos[idx]];
			if (merge(x, y)) {
				cur += w;
				ok++;
			}
			pos[idx]++;
			if (pos[idx] < ce.size()) q.emplace(ce[pos[idx]][0], idx);
		}
		ans = std::min(ans, cur);
	}

	std::cout << ans << "\n";

    return 0;
}