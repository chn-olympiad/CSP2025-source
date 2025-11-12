#include <bits/stdc++.h>
using namespace std;
long long t, n, a[100005][8], p, dp[100005][5];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		p = n / 2;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				dp[i][j] = max(dp[i - 1][j] + a[i][j], max(dp[i - 1][j - 1] + a[i][j], max(dp[i - 1][j + 1] + a[i][j],
				               max(dp[i - 1][j + 2] + a[i][j], dp[i - 1][j - 2] + a[i][j]))));
			}
		}
		cout << max(dp[n][1], max(dp[n][2], dp[n][3])) << "\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= p; j++) {
				dp[i][j] = 0;
			}
		}
	}
	return 0;
}
