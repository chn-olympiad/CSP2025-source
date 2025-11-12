#include <bits/stdc++.h>
using namespace std;
int n, m, dp[505][505][505], a[505], c[505], s2[505], s[505][505], ans, jc[505];
char b[505];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", b + 1);
	jc[0] = 1;
	for (int i = 1; i <= n; i++) {
		s2[i] = s2[i - 1];
		if (b[i] == '0')
			s2[i]++;
		jc[i] = 1ll * jc[i - 1] * i % 998244353;
	}
	dp[0][0][0] = s[0][0] = 1;
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= min(i, m); j++) {
			for (int k = 1; k <= n; k++) {
				if (b[i] == '1' && i - j - 1 < c[k]) {
					for (int k2 = 0; k2 <= i - 1; k2++)
						dp[i][j][k] = (dp[i][j][k] + s[k2][j - 1] - dp[k2][j - 1][k] + 998244353) % 998244353;
					s[i][j] = (s[i][j] + dp[i][j][k]) % 998244353;
				}
				cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << ' ' << s[i][j] << endl;
			}
		}
	}
	for (int i = m; i <= n; i++)
		ans = (ans + 1ll * jc[n - i] * s[i][m] % 998244353) % 998244353;
	cout << ans;
	return 0;
}