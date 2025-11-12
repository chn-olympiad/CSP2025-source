#include <bits/stdc++.h>
#define int long long
#define Max(a, b) a > b ? a : b
#define Min(a, b) a < b ? a : b
using namespace std;

int n, a[100005][5], dp[505][505][505], i, j, k, l, ans;

void solve() {
	cin >> n;
	for (i = 1; i <= n; i ++)
		for (j = 1; j <= 3; j ++) cin >> a[i][j];
	for (i = 0; i <= n; i ++)
		for (j = 0; j <= n; j ++)
			for (k = 0; k <= n; k ++) dp[i][j][k] = 0;
	ans = 0;
	for (l = 1; l <= n; l ++) {
		for (i = Min(l, n / 2); i >= 0; i --) {
			for (j = Min(l - i, n / 2); j >= 0; j --) {
				for (k = Min(l - i - j, n / 2); k >= 0; k --) {
					if (i >= 1) dp[i][j][k] = Max(dp[i][j][k], dp[i - 1][j][k] + a[l][1]);
					if (j >= 1) dp[i][j][k] = Max(dp[i][j][k], dp[i][j - 1][k] + a[l][2]);
					if (k >= 1) dp[i][j][k] = Max(dp[i][j][k], dp[i][j][k - 1] + a[l][3]);
					ans = Max(ans, dp[i][j][k]);
				}
			}
		}
	}
	cout << ans << '\n';
	return ;
}
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T --) solve();
	return 0;
}
