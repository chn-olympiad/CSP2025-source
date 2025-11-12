#include <iostream>
#include <string.h>
using namespace std;
const int MAXN = 100010;
long long n, a[5][MAXN], max2;
inline void init() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> a[j][i];
		}
		max2 = max(a[2][i], max2);
	}
	return;
}
int dfs(int x, int c1, int c2, int c3) {
	if (x == n + 1) return 0;
	long long res = 0;
	if (c1 + 1 <= n / 2) {
		res = max(res, dfs(x + 1, c1 + 1, c2, c3) + a[1][x]);
	}
	if (c2 + 1 <= n / 2) {
		res = max(res, dfs(x + 1, c1, c2 + 1, c3) + a[2][x]);
	}
	if (c3 + 1 <= n / 2) {
		res = max(res, dfs(x + 1, c1, c2, c3 + 1) + a[3][x]);
	}
	return res;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		init();
		if (n < 199){
			cout << dfs(0, 0, 0, 0) << '\n';
		} else if (max2 == 0) {
			long long dp[MAXN / 2];
			memset(dp, 0, sizeof(dp));
			for (int i = 1; i <= n; i++) {
				for (int j = n / 2; j >= 1; j--) {
					dp[j] = max(dp[j], dp[j - 1] + a[1][i]);
				}
			}
			cout << dp[n / 2] << '\n';
		} else {
			long long dp[3][MAXN / 2];
			memset(dp, 0, sizeof(dp));
			for (int i = 1; i <= n; i++) {
				for (int j = n / 2; j >= 1; j--) {
					if (dp[1][j] < dp[1][j - 1] + a[1][i]) {
						dp[1][j] = dp[1][j - 1] + a[1][i];
					} 
					else dp[2][j] = dp[2][j - 1] + a[2][i];
				}
			}
			cout << dp[1][n / 2] + dp[2][n / 2] << '\n';
		}
	}
	return 0;
}