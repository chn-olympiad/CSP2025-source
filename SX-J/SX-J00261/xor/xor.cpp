#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int n, k, a[N], ma = 0, ff[N][21], z[N][N][21], dp[N], ans = 0;
bool b[N][21], kk[21];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	int t = 1, as = k;
	while (as != 0) {
		if (as % 2 == 1)
			kk[t] = 1;
		as /= 2;
		t++;
	}
	ma = t - 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		int tt = 1, s = a[i];
		while (s != 0) {
			if (s % 2 == 1)
				b[i][tt] = 1;
			s /= 2;
			tt++;
		}
		for (int j = 1; j < tt; j++) {
			if (b[i][j] == 1)
				ff[i][j] = ff[i - 1][j] + 1;
			else
				ff[i][j] = ff[i - 1][j];
		}
		ma = max(ma, tt - 1);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= ma; j++) {
			if (b[i][j] == 1)
				ff[i][j] = ff[i - 1][j] + 1;
			else
				ff[i][j] = ff[i - 1][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			for (int q = 1; q <= ma; q++) {
				z[i][j][q] = ff[j][q] - ff[i - 1][q];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			bool flag = 0;
			for (int q = 1; q <= ma; q++) {
				if (kk[q] == 1) {
					if (z[j][i][q] % 2 == 0)
						flag = 1;
				} else if (kk[q] == 0) {
					if (z[j][i][q] % 2 != 0)
						flag = 1;
				}
			}
			if (flag == 0) {
				dp[i] = max(dp[i], dp[j - 1] + 1);
			} else
				dp[i] = max(dp[i], dp[i - 1]);
		}
	}
	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[i]);
	printf("%d\n", ans);
	return 0;
}
