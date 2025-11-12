#include <bits/stdc++.h>

#define int long long
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))

constexpr int mod = 998244353, N = 5e2 + 10; 
int n, m, a[N], ans;
bool vis[N]; 
char c[N]; 
void add(int &x, int y) {
	x += y, (x >= mod) && (x -= mod); 
}
void dfs(int u, int s) {
	if (s + n - u + 1 < m) return ; 
	if (u > n) {
		if (s >= m) (++ans) %= mod; 
		return ; 
	}
	for (int i = 1; i <= n; ++i) 
		if (!vis[i]) {
			vis[i] = 1;
			if (u - 1 - s >= a[i] || c[u] == '0') dfs(u + 1, s);
			else dfs(u + 1, s + 1); 
			vis[i] = 0; 
		}
}

signed main() {
	freopen("employ.in", "r", stdin), freopen("employ.out", "w", stdout);
	std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) std::cin >> c[i];
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	dfs(1, 0);
	std::cout << ans << "\n"; 
	
	return 0;
}

