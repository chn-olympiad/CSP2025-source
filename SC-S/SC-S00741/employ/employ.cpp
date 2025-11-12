#include <bits/stdc++.h>
const long long mod = 998244353;

long long n, m, ans = 0, ans1 = 0;
bool flag = true;
char s[505];
long long c[505];
long long dp[2][505][505];

void solve() {
	scanf("%lld%lld%s", &n, &m, s + 1);
	for (long long i = 1; i <= n; i++) {
		scanf("%lld", &c[i]);
	}
	for (long long i = 1; s[i] != '\0'; i++) {
		if (s[i] == '0') {
			flag = false;
			break;
		}
	}
	if (flag == true) {
		printf("%lld", 0);
		return;
	}
	if (m == n) {
		for (long long i = 1; s[i] != '\0'; i++) {
			if (s[i] == '0') {
				printf("%lld", 0);
				return;
			}
		}
	}
	if (s[1] == '0' || c[1] == 0) {
		dp[0][1][c[1]] = 1;
	} else {
		dp[0][0][c[1]] = 1;
	}
	for (long long i = 1; i <= n; i++) {
		for (long long j = 0; j <= i; j++) {
			for (long long k = 1; k <= n; k++) {
				for (long long l = 1; l <= n; l++) {
					if (l == k) continue;
					if (i - 1 - j >= c[k] || s[i] == '0') dp[1][j][c[k]] += dp[0][j][c[l]];
					else if (j > 0) dp[1][j][c[k]] += dp[0][j - 1][c[l]];
				}
				dp[1][j][c[k]] %= mod;
			}
		}
		for (long long j = 0; j <= i; j++) {
			for (long long k = 1; k <= n; k++) {
				dp[0][j][c[k]] = dp[1][j][c[k]];
			}
		}
	}
	for (long long j = m; j <= n; j++) {
		for (long long k = 1; k <= n; k++) {
			ans += dp[1][j][c[k]];
		}
	}
	printf("%lld\n", ans);
}
int main() {
	freopen("employ.in", "r", stdin);	
	freopen("employ.out", "w", stdout);
	solve();
	return 0;
} 