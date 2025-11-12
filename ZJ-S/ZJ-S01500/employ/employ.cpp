// 直至遥远的彼方
// Think twice, code once.
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define eputchar(c) putc(c, stderr)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eputs(str) fputs(str, stderr), putc('\n', stderr)
using namespace std;

const int mod = 998244353;

inline int pls(int x, int y) {return min<unsigned>(x + y, x + y - mod);}
inline int mns(int x, int y) {return min<unsigned>(x - y, x - y + mod);}
inline int &inc(int &x, int y) {return x = min<unsigned>(x + y, x + y - mod);}
inline int &dec(int &x, int y) {return x = min<unsigned>(x - y, x - y + mod);}

int n, m, s[505], cnt[505], dp[505][505][505], fac[505], ans;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = (long long)fac[i - 1] * i % mod;
	m = n - m;
	for (int i = 1; i <= n; i++) scanf("%1d", &s[i]);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
	dp[1][0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= min(m, i - 1); j++)
			for (int k = 0; k < i; k++) {
				int c = cnt[j] - (i - 1 - k);
				if (!s[i]) {
					inc(dp[i + 1][j + 1][k + 1], dp[i][j][k]);
					continue;
				}
				// if (i + 1 == 4 && j == 1 && k == 2) eprintf("c = %d\n", c);
				inc(dp[i + 1][j + 1][k], (long long)dp[i][j][k] * c % mod);
				dec(dp[i + 1][j][k], (long long)dp[i][j][k] * c % mod);
				inc(dp[i + 1][j][k + 1], dp[i][j][k]);
			}
	// eprintf("%d\n", dp[1][0][0]);
	// eprintf("%d\n", dp[2][0][1]);
	// eprintf("%d\n", dp[3][1][2]);
	// eprintf("%d\n", dp[4][1][2]);
	// eprintf("%d\n", dp[4][1][3]);
	// eprintf("%d\n", dp[4][2][2]);
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= n; j++) {
			inc(ans, (long long)dp[n + 1][i][j] * fac[j] % mod);
			// eprintf("%d %d %d %lld\n", i, j, dp[n + 1][i][j], (long long)dp[n + 1][i][j] * fac[j] % mod);
		}
	printf("%d\n", ans);
	return 0;
}
// 17:24 取之。