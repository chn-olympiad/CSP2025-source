#include <bits/stdc++.h>
using namespace std;
int a[100005][5];
long long dp[105][5][2005];
int n, h;
long long ans;

void dfs(int i, int on, int tw, int th, long long cnt) {
	if (i == n + 1) {
		ans = max(ans, cnt);
		return ;
	}
	if (on < h) {
		int v = cnt + a[i][1];
		dfs(i + 1, on + 1, tw, th, v);
	}
	if (tw < h) {
		int v = cnt + a[i][2];
		dfs(i + 1, on, tw + 1, th, v);
	}
	if (th < h) {
		int v = cnt + a[i][3];
		dfs(i + 1, on, tw, th + 1, v);
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		h = n / 2;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
		}
		if (n <= 18) {
			dfs(1, 0, 0, 0, 0);
			printf("%lld\n", ans);
			continue;
		}
		for (int i = 1; i <= n; i++) {
			int id = i ;
			int lid = (i - 1) ;
			for (int j = 1; j <= 3; j++) {
				for (int k = 1; k <= h  && k <= i; k++) {
					for (int l = 1; l <= 3; l++) {

						if (j == l) {
							if (k > 1)
								dp[id][j][k] = max(dp[id][j][k], dp[lid][l][k - 1] + a[id][j]);
						}

						else {
							dp[id][j][k] = max(dp[id][j][k], dp[lid][l][k] + a[id][j]);
						}
					}

					ans = max(ans, dp[i][j][k]);
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
