#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 505, mod = 998244353;
int n, m, c[maxn], x[maxn];
int cnt1, cnt2, fac[maxn], C[maxn][maxn];
string s;
int dp[1 << 18][19];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		fac[i] = 1ll * fac[i - 1] * i % mod;
	}
	C[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		x[i] = s[i - 1] - '0';
		if (x[i] == 0) cnt1++;
	}
	for (int i = 1; i <= n; i++) {
		if (c[i] == 0) cnt2++;
	}
	if (m == n) {
		if (cnt1 == 0 && cnt2 == 0) printf("%d", fac[n]);
		else puts("0");
		return 0;
	}
	if (n <= 18) {
		dp[0][0] = 1;
		for (int i = 0; i < (1 << n); i++) {
			int cnt = __builtin_popcount(i);
			for (int j = 1; j <= n; j++) {
				if ((i >> j - 1) & 1) continue;
				int to = (i ^ (1 << j - 1));
				for (int k = 0; k <= cnt; k++) {
					if (x[cnt + 1] == 0 || k >= c[j]) {
						dp[to][k + 1] = (dp[to][k + 1] + dp[i][k]) % mod;
					} else {
						dp[to][k] = (dp[to][k] + dp[i][k]) % mod;
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i <= n - m; i++) {
			ans = (ans + dp[(1 << n) - 1][i]) % mod;
		}
		printf("%d", ans);
		return 0;
	}
	sort(c + 1, c + n + 1);
	int ans = 1;
	for (int i = n, j = n; i >= 1; i--) {
		if (c[i] == 0) {
			ans = 1ll * ans * i % mod;
			continue;
		}
		while (j > c[i]) {
			if (x[j] != 0) cnt1++;
			j--;
		}
		ans = 1ll * ans * cnt1 % mod;
		cnt1--;
	}
	printf("%d", (fac[n] - ans + mod) % mod);
	return 0;
}