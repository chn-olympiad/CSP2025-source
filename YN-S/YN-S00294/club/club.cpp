//wr 2025.11.1 CSP-S RP++!!!
#include <bits/stdc++.h>
using namespace std;
int a[105][3];
int dp[105][105][105];
int t;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		memset(dp, -0x3f, sizeof(dp));
		dp[0][0][0] = 0;
		for (int i = 1; i <= n; i++)
			for (int k1 = 0; k1 <= i; k1++)
				for (int k2 = 0; k2 <= i - k1; k2++) {
					int k3 = i - k1 - k2;
					if (k1)
						dp[i][k1][k2] = max(dp[i][k1][k2], dp[i - 1][k1 - 1][k2] + a[i][1]);
					if (k2)
						dp[i][k1][k2] = max(dp[i][k1][k2], dp[i - 1][k1][k2 - 1] + a[i][2]);
					if (k3)
						dp[i][k1][k2] = max(dp[i][k1][k2], dp[i - 1][k1][k2] + a[i][3]);
				}
		int ans = 0;
		for (int k1 = 0; k1 <= n / 2; k1++)
			for (int k2 = 0; k2 <= n / 2; k2++) {
				int k3 = n - k1 - k2;
				if (k3 <= n / 2)
					ans = max(ans, dp[n][k1][k2]);
			}
		cout << ans << "\n";
	}
	return 0;
}