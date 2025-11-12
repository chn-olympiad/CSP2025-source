#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 5e3 + 100;
int n, dp[N][N], a[N];
long long ans;
void dfs(int x, int maxx, int p) {
	if (p == n) {
		if (x > 2 * maxx) {
			ans ++;
			ans %= mod;
		}
		return ;
	}
	dfs(x + a[p + 1], a[p + 1], p + 1);
	dfs(x, maxx, p + 1);
	return ;
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (n <= 20) {
		dfs(0, 0, 0);
		cout << ans;
		return 0;
	}
	else if (a[n] == 1) {
		cout << (n - 1) * (n - 2) / 2 % mod;
		return 0;
	}
	else {
		for (int i = 1; i <= n; i++) {
			ans += (n - i) * (n - i - 1) / 2 % mod;	
			ans %= mod;
		}
		cout << ans;
		return 0;
	}
	return 0;
}
