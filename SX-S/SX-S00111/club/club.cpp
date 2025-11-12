#include <bits/stdc++.h>
using namespace std;
long long t, dp[202][202][202];
int a[100001][4];
long long ans;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	while (t--) {
		int n;
		ans = 0;
		scanf("%d", &n);
		if (n <= 400) {
			for (int i = 1; i <= n; i++)
				scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			for (int i = 0; i <= n / 2; i++) {
				for (int j = 0; j <= n / 2; j++) {
					for (int k = 0; k <= n / 2; k++) {
						dp[i][j][k] = 0;
					}
				}
			}
			for (int i = 0; i <= n / 2; i++) {
				for (int j = 0; j <= n / 2; j++) {
					for (int k = 0; k <= n / 2; k++) {
						if (i + j + k > n)
							break;
						if (i > 0)
							dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[i + j + k][1]);
						if (j > 0)
							dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + a[i + j + k][2]);
						if (k > 0)
							dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1] + a[i + j + k][3]);
						ans = max(dp[i][j][k], ans);
					}
				}
			}
		} else {
			int b[100001];
			for (int i = 1; i <= n; i++) {
				scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
				b[i] = a[i][1];
			}
			sort(b + 1, b + 1 + n);
			for (int i = 1; i <= n / 2; i++) {
				ans += b[i];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
