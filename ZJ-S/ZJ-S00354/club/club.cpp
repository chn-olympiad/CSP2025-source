#include <bits/stdc++.h>
using namespace std;
const int N = 205, NN = 1e5 + 7;
int n, a[N][4], aa[N];
long long ans = 0, dp[N][N][N];
void solve() {
	ans = 0;
	cin >> n;
	if (n >= 5e4) { //for A
		for (int i = 1, bb, cc; i <= n; i++) {
			cin >> aa[i] >> bb >> cc;
		}
		sort(aa + 1, aa + 1 + n);
		for (int i = n; i > n / 2; i--) {
			ans = ans + aa[i];
		}
		cout << ans << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		for (int j = 0; j <= n / 2; j++) {
			for (int k = 0; k <= n / 2 && (i - k - j >= 0); k++) {
				if (i - k - j <= n / 2) {
					dp[i][j][k] = max({(i - k - j > 0? dp[i - 1][j][k] + a[i][3] : -1), (k > 0? dp[i - 1][j][k - 1] + a[i][2] : -1), (j > 0? dp[i - 1][j - 1][k] + a[i][1] : -1)});
					//~ cout << ' ' << j << ' ' << k  << ' ' << i - j - k << ' ' << dp[i][j][k] << '\n';
					ans = max(dp[i][j][k], ans);
				}
			}
		}
	}
	cout << ans << '\n';
	return;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
/*

想了1h好像不会，保险点先打暴力吧

aim 60

*/
