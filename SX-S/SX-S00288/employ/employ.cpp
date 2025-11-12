#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

constexpr int mod = 998244353;

int n, m, dp[19][(1 << 18) + 5], a[19], ans;
char s[19];

void write(int x) {
	if (!x) {
		putchar('0');
		return;
	}
	write(x >> 1);
	putchar((x & 1) + 48);
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s + 1);
	if (n > 18) {
		puts("0");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	dp[0][0] = 1;
	for (int i = 0; i < (1 << n) - 1; i++) {
		int num = __builtin_popcount(i);
		for (int j = 0; j <= num; j++) {
			for (int k = 1; k <= n; k++) {
				int pos = (1 << (k - 1));
				if (!(i & pos)) {
					if (s[num + 1] == '0')
						(dp[j][i | pos] += dp[j][i]) %= mod;
					else if (num - j < a[k])
						(dp[j + 1][i | pos] += dp[j][i]) %= mod;
					else (dp[j][i | pos] += dp[j][i]) %= mod;
				}
			}
		}
	}
	for (int i = m; i <= n; i++)
		(ans += dp[i][(1 << n) - 1]) %= mod;
	printf("%d", ans);
	return 0;
}
