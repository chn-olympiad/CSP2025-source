#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n, m;
ll a[100001][4];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;
	
	while (t--) {
		cin >> n;
		
		ll dp[10001][4] = {};
		
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		
		dp[1][1] = a[1][1];
		dp[1][2] = a[1][2];
		dp[1][3] = a[1][3];
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				int maxn = 0;
				if (j == 1) {
					if ((n >> 1) == 1) {
						maxn = max(dp[i - 1][2], dp[i - 1][3]);
					}
					else if ((n >> 1) > 1) {
						for (int k = 1; k < (n >> 1) && i - k >= 0; k++) {
							maxn += max(max(a[i - k][1], dp[i - k][3]), dp[i - k][2]);
						}
					}
				}
				else if (j == 2) {
					if ((n >> 1) == 1) {
						maxn = max(dp[i - 1][1], dp[i - 1][3]);
					}
					else if ((n >> 1) > 1) {
						for (int k = 1; k < (n >> 1) && i - k >= 0; k++) {
							maxn += max(max(dp[i - k][1], dp[i - k][3]), a[i - k][2]);
						}
					}
				}
				else {
					if ((n >> 1) == 1) {
						maxn = max(dp[i - 1][1], dp[i - 1][2]);
					}
					else if ((n >> 1) > 1) {
						for (int k = 1; k < (n >> 1) && i - k >= 0; k++) {
							maxn += max(max(dp[i - k][1], a[i - k][3]), dp[i - k][2]);
						}
					}
				}
				dp[i][j] = maxn + a[i][j];
			}
		}
		
		cout << max(dp[n][1], max(dp[n][2], dp[n][3])) << '\n';
	}
	
	return 0;
}