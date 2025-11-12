#include <bits/stdc++.h>
using namespace std;
long long t;
long long a[100005][3];
long long dp[100005][3][4];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;

	while (t--) {
		long long n = 0, ans = 0;

		cin >> n;

		for (int i = 1; i <= n; i++) {

			for (int j = 1; j <= 3; j++) {

				for (int k = 1; k <= 3; k++) {

					dp[i][j][k] = 0;
				}

				a[i][j] = 0;
			}
		}

		for (int i = 1; i <= n; i++) {

			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}

		dp[1][1][1] = 1;
		dp[1][2][2] = 1;
		dp[1][3][3] = 1;
		dp[1][1][0] = a[1][1];
		dp[1][2][0] = a[1][2];
		dp[1][3][0] = a[1][3];

		for (int i = 2; i <= n; i++) {

			for (int j = 1; j <= 3; j++) {

				int s = 0;

				for (int k = 1; k <= 3; k++) {

					if (dp[i - 1][k][j] + 1 <= n / 2) {
						if (dp[i - 1][k][0] + a[i][j] > dp[i][j][0]) {
							dp[i][j][0] = dp[i - 1][k][0] + a[i][j];
							ans = max(dp[i][j][0], ans);
							s = k;
						}
					}

					ans = max(dp[i][j][0], ans);
				}

				dp[i][j][s]++;
			}

		}

		cout << ans << "\n";
	}

	return 0;
}
