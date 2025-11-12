#include <bits/stdc++.h>
using namespace std;
int n, m, k, minn = INT_MAX, minn1 = INT_MAX, x[10001], y[10001];
int t[10001][10001], a[11], b[11][10001], c[11];
int dp[10001][10001][2];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j][0] = INT_MAX;
			dp[i][j][1] = INT_MAX;
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> x[i] >> y[i] >> t[x[i]][y[i]];
	}
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
		for (int j = 1; j <= n; j++)
			cin >> b[i][j];
	}
	for (int i = 1; i <= m; i++) {
		dp[x[i]][y[i]][0] = min(dp[x[i - 1]][y[i - 1]][0], dp[x[i - 1]][y[i - 1]][1]) + t[x[i]][y[i]];
		if (x[i] <= k) {
			dp[x[i]][y[i]][1] = min(dp[x[i]][y[i]][0], min(dp[x[i - 1]][y[i - 1]][0],
			                        dp[x[i - 1]][y[i - 1]][1]) + (!c[i]) * a[i] + b[x[i]][y[i]]);
			c[i] = 1;
		}

	}
	cout << min(dp[x[m]][y[m]][0], dp[x[m]][y[m]][1]);
	return 0;
}
