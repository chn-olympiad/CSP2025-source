#include <bits/stdc++.h>

#define int long long
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))

constexpr int N = 5e5 + 10, M = (1ll << 20) + 10; 
int n, k, a[N], s[N], dp[N], buc[M], vis[M];  

signed main() {
	freopen("xor.in", "r", stdin), freopen("xor.out", "w", stdout);
	std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i) std::cin >> a[i], s[i] = s[i - 1] ^ a[i];
	dp[0] = 0, vis[0] = 1; 
	for (int i = 1; i <= n; ++i) {
		int cur = s[i] ^ k;
		if (vis[cur]) dp[i] = max(dp[i - 1], buc[cur] + 1);
		else dp[i] = dp[i - 1]; 
		buc[s[i]] = max(buc[s[i]], dp[i]), vis[s[i]] = 1; 
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) ans = max(ans, dp[i]);
	std::cout << ans << "\n"; 
	return 0;
}

