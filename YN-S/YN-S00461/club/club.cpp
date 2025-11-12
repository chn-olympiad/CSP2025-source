#include <bits/stdc++.h>
using namespace std;
const int N = 205;
#define int long long
int t;
int n, a[N][5];
int f[N];
int dp[N / 2][N / 2][N / 2], ans;

void dfs(int x, int y, int z, int sum) {
	if (x > n / 2 || y > n / 2 || z > n / 2)
		return;
	ans = max(ans, sum);
	for (int i = 1; i <= n; i++) {
		if (!f[i]) {
			f[i] = 1;
			dfs(x + 1, y, z, sum + a[i][1]);
			f[i] = 0;
		}
		if (!f[i]) {
			f[i] = 1;
			dfs(x, y + 1, z, sum + a[i][2]);
			f[i] = 0;
		}
		if (!f[i]) {
			f[i] = 1;
			dfs(x, y, z + 1, sum + a[i][3]);
			f[i] = 0;
		}
	}
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
//		memset(dp, 0, sizeof(dp));
		cin >> n;
		ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
				cin >> a[i][j];
//		for (int i = 0; i <= n / 2; i++) {
//			for (int j = 0; j <= n / 2; j++) {
//				for (int k = 0; k <= n / 2; k++) {
//					for (int o = 1; o <= n; o++) {
//						if (i == 0) {
//							if (j == 0) {
//								if (k == 0)
//									break;
//								else{
//									if(!f[o][3]){
//										if(dp[0][0][k]<dp[0][0][k-1]+a[o][3]){
//										dp[0][0][k]=dp[0][0][k-1]+a[o][3];
//										f[o][3]=1;
//									}
//									}
//
//								}
//
//									dp[0][0][k] = max(dp[0][0][k], dp[0][0][k - 1] + a[o][3]);
//							} else {
//								if (k == 0)
//									dp[0][j][0] = max(dp[0][j][0], dp[0][j - 1][0] + a[o][2]);
//								else
//									dp[0][j][k] = max(dp[0][j][k], max(dp[0][j - 1][k] + a[o][2], dp[0][j][k - 1] + a[o][3]));
//							}
//						} else {
//							if (j == 0) {
//								if (k == 0)
//									dp[i][0][0] = max(dp[i][0][0], dp[i - 1][0][0] + a[o][1]);
//								else
//									dp[i][0][k] = max(dp[i][0][k], max(dp[i - 1][0][k] + a[o][1], dp[i][0][k - 1] + a[o][3]));
//							} else {
//								if (k == 0)
//									dp[i][j][0] = max(dp[i][j][0], max(dp[i - 1][j][0] + a[o][1], dp[i][j - 1][0] + a[o][2]));
//								else
//									dp[i][j][k] = max(dp[i][j][k], max(dp[i - 1][j][k] + a[o][1], max(dp[i][j - 1][k] + a[o][2],
//									                                   dp[i][j][k - 1] + a[o][3])));
//							}
//						}
//						ans = max(ans, dp[i][j][k]);
//					}
//				}
//			}
//		}
		dfs(0, 0, 0, 0);
		cout << ans << '\n';
	}

	return 0;
}
