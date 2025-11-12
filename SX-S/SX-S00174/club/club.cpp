#include <bits/stdc++.h>
using namespace std;
long long t, n, a[105], b[105], c[105], dp[105][105][105], ans;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	for (int _ = 1; _ <= t; _++) {
		scanf("%lld", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
		}
		if (n >= 1000) {
			sort(a + 1, a + 1 + n, greater<int>());
			int tmp = 0;
			for (int i = 1; i <= (n / 2); i++) {
				tmp += a[i];
			}
			printf("%lld\n", tmp);
		}
		memset(dp, 0, sizeof dp);
		ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = (n / 2); j >= 0; j--) {
				for (int k = (n / 2); k >= 0; k--) {
					for (int l = (n / 2); l >= 0; l--) {
						if (j)
							dp[j][k][l] = max(dp[j][k][l], dp[j - 1][k][l] + a[i]);
						if (k)
							dp[j][k][l] = max(dp[j][k][l], dp[j][k - 1][l] + b[i]);
						if (l)
							dp[j][k][l] = max(dp[j][k][l], dp[j][k][l - 1] + c[i]);
						ans = max(ans, dp[j][k][l]);
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}