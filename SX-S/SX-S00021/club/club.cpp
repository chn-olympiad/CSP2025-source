#include <bits/stdc++.h>
using namespace std;
long long T, n, num1, num2, x[100010], ans;
long long dp[100010][5];
long long a[100010][5];
long long num[5];


int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);
	cin >> T;
	while (T--) {
		for (int i = 1; i <= n; i++) {
			a[i][0] = a[i][1] = a[i][2] = a[i][3] = 0;
			dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = 0;
			n = 0;
		}
		num[0] = num[1] = num[2] = num[3] = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];

			if (a[i][1] == 0)
				num1++;
			if (a[i][2] == 0)
				num2++;
			x[i] = a[i][0];
		}
		if (num1 == n && num2 == n) {
			sort(x + 1, x + 1 + n);
			for (int i = n; i >= 1; i++) {
				ans += x[i];
			}
			cout << ans << endl;
			continue;
		}
		if (n == 2) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (i != j) {
						ans = max(ans, a[1][i] + a[2][j]);
					}
				}
			}
			cout << ans << endl;
			continue;
		}
	}
	return 0;
}
