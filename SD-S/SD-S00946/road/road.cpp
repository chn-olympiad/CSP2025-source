#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <tuple>
#include <vector>
namespace {
using namespace std;
using i64 = int64_t;
const int N = 1e4 + 5, K = 15;
const i64 INF = 0x3f3f3f3f3f3f3f3f; 
int n, m, k, c[N], a[K][N], fa[N + K];
i64 cur, ans = INF;
vector<tuple<int, int, int>> E1, E2, E3;
int find(int u) {
	while (u != fa[u]) u = fa[u] = fa[fa[u]];
	return u;
}
} // namespace
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k, E1.resize(m);
	for (auto &p : E1) cin >> get<1>(p) >> get<2>(p) >> get<0>(p);
	sort(E1.begin(), E1.end());
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	for (int i = 0; i < 1 << k; i++) {
		cur = 0, E2.clear();
		for (int j = 1; j <= n + k; j++) fa[j] = j;
		for (int j = 1; j <= k; j++) {
			if (!(i & (1 << (j - 1)))) continue;
			cur += c[j];
			for (int l = 1; l <= n; l++) E2.emplace_back(a[j][l], l, j + n);
		}
		sort(E2.begin(), E2.end());
		E3.resize(E1.size() + E2.size());
		merge(E1.begin(), E1.end(), E2.begin(), E2.end(), E3.begin());
		for (auto &p : E3) {
			int w, u, v;
			tie(w, u, v) = p;
			if ((u = find(u)) != (v = find(v))) fa[v] = u, cur += w;
		}
		ans = min(ans, cur);
	}
	cout << ans;
}
