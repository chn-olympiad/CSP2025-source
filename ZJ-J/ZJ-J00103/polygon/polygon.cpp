#include <bits/stdc++.h>

#define int long long
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))

constexpr int N = 5e3 + 100, mod = 998244353, maxn = 5e3 + 10, M = 5e3 + 100;  

int n, a[N], f[M], g[M];
void add(int &x, int y) {
	x += y, (x >= mod) && (x -= mod); 
}

signed main() {
	freopen("polygon.in", "r", stdin), freopen("polygon.out", "w", stdout);
	std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	std::sort(a + 1, a + 1 + n); 
	int ans = 0; 
	g[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = min(a[i] + 1, maxn); j <= maxn; ++j) add(ans, g[j]); 
		for (int j = 0; j <= maxn; ++j) if (g[j]) {
			add(f[j], g[j]);
			add(f[min(maxn, j + a[i])], g[j]); 
		}
		for (int j = 0; j <= maxn; ++j) g[j] = f[j], f[j] = 0; 
	}
	std::cout << ans << "\n"; 
	return 0;
}

