#include <bits/stdc++.h>
#define int long long
const int N = 2e2 + 6;
int n, a[N][4], f[N][N][N], id[4][N], sa, sb, sc;
std::vector<int> al[N];
int calc(int x, int y, int z) {
	int sum = 0, aa = 0;
	int bb = (y == 1 ? sa : (y == 2 ? sb : sc));
	int cc = (z == 1 ? sa : (z == 2 ? sb : sc));
	std::vector<int> vis(n + 1, 0);
	for (int i = 0; i <= n / 2; ++i) {
		int u = 0, tb = 0, tc = cc, cur = cc;
		for (int j = 0; j <= n && u < n / 2; ++j) {
			int v = id[y][j];
			if (vis[v]) continue;
			cur = std::max(cur, tb + tc);
			tb += a[v][y], tc -= a[v][z]; ++u;
		}
//		std::cout << aa << " " << cur << "\n";
		sum = std::max(sum, aa + cur);
		aa += a[id[x][i]][x];
		cc -= a[id[x][i]][z];
	}
	return sum;
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	freopen("club1.in", "r", stdin);
//	freopen("club.out", "w", stdout);
	int t; std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 1; i <= n; ++i) al[i].clear();
		sa = sb = sc = 0;
		for (int i = 1; i <= n; ++i)
			std::cin >> a[i][1] >> a[i][2] >> a[i][3], sa += a[i][1], sb += a[i][2], sc += a[i][3];
		for (auto& v : {1, 2, 3}) {
			for (int i = 1; i <= n; ++i)
				id[v][i] = i;
			std::sort(id[v] + 1, id[v] + n + 1, [&](int x, int y) {
				return a[x][v] > a[y][v];
			});
		}
		int ans = calc(1, 2, 3);
		ans = std::max(ans, calc(1, 3, 2));
		ans = std::max(ans, calc(2, 1, 3));
		ans = std::max(ans, calc(2, 3, 1));
		ans = std::max(ans, calc(3, 1, 2));
		ans = std::max(ans, calc(3, 2, 1));
		std::cout << ans << "\n";
	}
}
