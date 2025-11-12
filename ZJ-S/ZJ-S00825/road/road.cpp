#include <bits/stdc++.h>
#define int long long
const int N = 1e4 + 6;
int n, m, k, c[N], a[12][N], tot = 0, f[N * 212], ans = 0, flg[N];
struct Edge {
	int x, y, w;
} edg[N * 212], tmp[N * 212];
int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}
bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}
void kruskal(int len) {
	std::sort(tmp + 1, tmp + len + 1, cmp);
	for (int i = 1; i <= k; ++i) flg[i] = 0;
	for (int i = 1; i <= len; ++i) {
		int x = tmp[i].x, y = tmp[i].y, w = tmp[i].w;
		if (x > n) ans += c[x - n] * (++flg[x - n] == 1);
		if (y > n) ans += c[y - n] * (++flg[y - n] == 1);
		++x, ++y;
		if (find(x) != find(y)) {
			ans += w, f[find(x)] = find(y);
		}
	}
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	std::cin >> n >> m >> k;
//	std::cout << n << " " << m << " " << k << "\n";
	for (int i = 1; i <= m; ++i) {
		int x, y, w; std::cin >> x >> y >> w;
		edg[++tot] = Edge {x, y, w};
	}
	bool ok = 1;
	for (int i = 1; i <= k; ++i) {
		std::cin >> c[i]; ok &= c[i] == 0;
		for (int j = 1; j <= n; ++j) {
			std::cin >> a[i][j]; ok &= a[i][j] == 0;
		}
	}
	if (ok && k != 0) return std::cout << "0\n", 0;
	if (k == 0) kruskal(tot);
	else {
		int fin = 1e18;
		for (int s = 0; s < (1 << k); ++s) {
			for (int i = 1; i <= n + k + 2; ++i) f[i] = i;
			for (int j = 1; j <= tot; ++j) tmp[j] = edg[j];
			int tot1 = tot;
			for (int i = 1; i <= k; ++i) {
				if (!(s >> (k - i) & 1)) continue;
				for (int j = 1; j <= n; ++j)
					tmp[++tot1] = {i + n, j, a[i][j]};
			}
			ans = 0, kruskal(tot1);
			fin = std::min(fin, ans);
		}
		std::cout << fin << "\n";
	}
}
