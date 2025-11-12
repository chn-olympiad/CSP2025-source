#include <bits/stdc++.h>
using namespace std;
int a[205], b[205], c[205], dp[105][105][105], ans;
int n, T;

void dfs(int i, int j, int k, int sum) {
	if (i > n / 2 || j > n / 2 || k > n / 2)
		return ;
	if (i + j + k == n)
		ans = max(ans, sum);
	dfs(i + 1, j, k, sum + a[i + j + k + 1]);
	dfs(i, j + 1, k, sum + b[j + i + k + 1]);
	dfs(i, j, k + 1, sum + c[k + i + j + 1]);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		memset(dp, 0, sizeof dp);
		ans = 0;

		cin >> n;
		for (int i = 1; i <= n; i++) {
			scanf("%d %d %d", &a[i], &b[i], &c[i]);
		}
		if (n < 100000) {
			for (int i = 0; i <= n / 2; i++) {
				for (int j = 0; j <= n / 2; j++) {
					for (int k = 0; k <= n / 2; k++) {
						if (i + j + k > n)
							break;
						if (k != 0) {
							dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1] + c[i + k + j]);
						}
						if (j != 0) {
							dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + b[i + k + j]);
						}
						if (i != 0) {
							dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[i + k + j]);
						}
						if (i + j + k == n)
							ans = max(dp[i][j][k], ans);

					}
				}
			}
		} else {
			//cout << '\n';
			for (int i = 1; i <= n; i++) {
				ans += max(a[i], max(b[i], c[i]));
			}
		}
		cout << ans << '\n';

	}
	return 0;
}