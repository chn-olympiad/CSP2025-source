#include<bits/stdc++.h>
using namespace std;

const int N = 210;
int n, dp[N][N][N];
array<int, 3> a[N];

inline void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
	if (n <= 200) {
		memset(dp, 0, sizeof(dp));
		int ans = 0;
		for (int i = 0; i <= n; i++) 
			for (int j = 0; j <= min(i, n / 2); j++) 
				for (int k = 0; k <= min(i - j, n / 2); k++) {
					if (j < n / 2) 
						dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + a[i + 1][0]);
					if (k < n / 2) 
						dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + a[i + 1][1]);
					if (i - j - k < n / 2) 
						dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + a[i + 1][2]);
					if (i == n && i - j - k <= n / 2) 
						ans = max(ans, dp[i][j][k]);
				}
		printf("%d\n", ans);
	}
	else {
		sort(a + 1, a + n + 1);
		int ans = 0;
		for (int i = n; i > n / 2; i--) 
			ans += a[i][0];
		printf("%d\n", ans);
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
