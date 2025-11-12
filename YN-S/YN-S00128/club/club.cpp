#include <bits/stdc++.h>
#define maxn 100100
using namespace std;
int n;
int a[maxn][5];
int c[5];
int m;
int dp[maxn];

int dfs(int x, int sum) {
	if (x > n) {
		return sum;
	} else {
		int ret = 0;
		for (int i = 1; i <= 3; i++) {
			c[i]++;
			if (c[i] <= m) {
				ret = max(ret, dfs(x + 1, sum + a[x][i]));
			}
			c[i]--;
		}
		return ret;
	}
}

void solve() {
	cin >> n;
	m = n / 2;
	int a2m = 0, a3m = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		a2m = max(a2m, a[i][2]);
		a3m = max(a3m, a[i][3]);
	}
	int ans = 0;
	if (n <= 10) {
		cout << dfs(1, 0) << endl;
		return;
	}
	if (a2m == 0) {
		for (int i = 1; i <= m; i++)
			dp[i] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = m; j >= 1; j--) {
				dp[j] = max(dp[j], dp[j - 1] + a[i][1]);
			}
		}
		ans = dp[m];
	} else if (a3m == 0) {
		for (int i = 1; i <= m; i++)
			dp[i] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = m; j >= 1; j--) {
				dp[j] = max(dp[j] + a[i][2], dp[j - 1] + a[i][1]);
			}
		}
		ans = dp[m];
	} else {
		for (int i = 1; i <= m; i++)
			dp[i] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = m; j >= 1; j--) {
				dp[j] = max(dp[j] + max(a[i][2], a[i][3]), dp[j - 1] + a[i][1]);
			}
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}