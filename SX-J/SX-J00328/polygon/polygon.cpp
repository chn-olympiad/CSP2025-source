#include <bits/stdc++.h>
using namespace std;
const int N = 5005, mod = 998244353;
int a[N];
int n;
long long dp[N];

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	long long ans = 0;
	dp[0] = 1;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = a[i] + 1; j <= 5001; j++) {
			(ans += dp[j]) %= mod;
		}
		for (int j = 5001; j >= 0; j--) {
			if (j + a[i] >= 5001)
				(dp[5001] += dp[j]) %= mod;
			else (dp[j + a[i]] += dp[j]) %= mod;
		}
	}
	cout << ans << endl;
	return 0;
}
