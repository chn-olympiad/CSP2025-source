#include <bits/stdc++.h>
using namespace std;
int dp[500009][2], sum[500009], a[500009];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int x = 1; x <= n; x++) {
		cin >> a[x];
	}
	for (int x = 1; x <= n; x++) {
		if ((a[x]^sum[x - 1]) == k) {
			dp[x][1] = max(dp[x - 1][1] + 1, dp[x - 1][0] + 1);
			sum[x] = 0;
		} else {
			sum[x] = sum[x - 1] ^ a[x];
			dp[x][1] = max(dp[x - 1][1], dp[x - 1][0]);
			if (dp[x - 1][0] == dp[x][1])
				sum[x] = 0;
		}
		dp[x][0] = max(dp[x - 1][0], dp[x - 1][1]);
	}
	cout << max(dp[n][1], dp[n][0]);
	return 0;
}
