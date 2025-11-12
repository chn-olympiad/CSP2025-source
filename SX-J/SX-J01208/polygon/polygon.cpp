#include <bits/stdc++.h>
using namespace std;
long long n, a[5005], mod = 998244353, ans, vis[5005];

long long dfs(long long x, long long y, long long maxx, long long kk) {
	if (n - x < kk - y) {
		return 0;
	} else if (y == kk) {
		if (maxx)
		}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans = (ans + dfs(j, 1, 0, i)) % mod;
		}
	}
	cout << ans;
	return 0;
}
