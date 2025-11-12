#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;

struct Membe {
	int a, b, c;
} membe[MAXN];
int dp[5005][205][205], dp1[5005][205];

bool cmp(Membe x, Membe y) {
	return x.a > y.a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		bool flag = 0;
		cin >> n;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			cin >> membe[i].a >> membe[i].b >> membe[i].c;
			if (membe[i].a != 0)
				flag = 1;
		}
		int ans = 0;
		if (1ll * n * n * n >= 5e8) {
			if (flag) {
				for (int i = 1; i <= n; i++) {
					for (int j = 0; j <= min(i, n / 2); j++) {
						if (i - j > n / 2)
							continue;
						if (j > 0)
							dp1[i][j] = max(dp1[i][j], dp1[i - 1][j - 1] + membe[i].a);
						if (i - j > 0)
							dp1[i][j] = max(dp1[i][j], dp1[i - 1][j] + membe[i].b);
					}
				}
				ans =  dp1[n][n / 2];
			} else {
				sort(membe + 1, membe + n + 1, cmp);
				for (int i = 1; i <= n / 2; i++)
					ans += membe[i].a;
			}
		} else {
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j <= min(i, n / 2); j++) {
					for (int k = 0; k <= min(i, n / 2); k++) {
						if (i - j - k > n / 2)
							continue;
						if (j > 0)
							dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + membe[i].a);
						if (k > 0)
							dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + membe[i].b);
						if (i - j - k > 0)
							dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + membe[i].c);
					}
				}
			}

			for (int j = 0; j <= n / 2; j++) {
				for (int k = 0; k <= n / 2; k++) {
					ans = max(ans, dp[n][j][k]);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
