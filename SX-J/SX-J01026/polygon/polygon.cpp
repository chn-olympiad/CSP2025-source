#include <bits/stdc++.h>
using namespace std;
long long a[5005], dp[25][2005], a1[5005];
long long mo = 998244353, sum = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, op = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		a1[i] = a1[i - 1] + a1[i];
		if (a[i] != 1)
			op = 1;
	}
	sort(a + 1, a + n + 1);
	if (op == 0) {
		long long ans = 0, ui = 0;
		ui = n * (n - 1) / 2;
		for (int i = 3; i <= n; i++) {
			ans = (ans + ui*(n - i + 1) / i) % mo;
		}
		cout << ans;
	} else if (n <= 20) {
		for (int i = 1; i <= n; i++) {
			dp[i][a[i]] = 1;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= sum; j++) {
				dp[i][j] = max( dp[i - 1][j - a[i]] + dp[i - 1][j], dp[i][j]);
			}
		}
		long long ans = 0;
		for (int i = 3; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				for (int l = i + 1; l <= a1[j]; l++) {
					ans += dp[j][l];
					ans %= mo;
				}
			}
		}
		cout << ans;
	}
	return 0;
}
