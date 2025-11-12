#include <bits/stdc++.h>
using namespace std;

const int N = 505, mod = 998244353;
int C[N][N], cnt[N], pre[N], suf[N], fac[N];
int f[N][N][N];
char s[505];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	scanf("%d%d%s", &n, &m, s + 1);
	for (int i = 0; i <= n; i ++ ) C[i][0] = 1;
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 1; j <= i; j ++ ) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
	}
	fac[0] = 1;
	for (int i = 1; i <= n; i ++ ) fac[i] = 1ll * fac[i - 1] * i % mod;
	for (int i = 1, c; i <= n; i ++ ) {
		scanf("%d", &c);
		cnt[c] ++ ;
	}
	for (int i = n; i >= 0; i -- ) suf[i] = suf[i + 1] + cnt[i];
	pre[0] = cnt[0];
	for (int i = 1; i <= n; i ++ ) pre[i] = pre[i - 1] + cnt[i];
	f[0][0][0] = 1;
	for (int i = 0; i <= n; i ++ ) {
		if (s[i + 1] == '0') {
			for (int j = 0; j <= i; j ++ ) {
				for (int k = 0; k <= i && k <= suf[j + 1]; k ++ ) {
					for (int p = 0; p <= k && p <= cnt[j + 1]; p ++ )
						(f[i + 1][j + 1][k - p] += 1ll * f[i][j][k] * C[k][p] % mod * C[cnt[j + 1]][p] % mod * fac[p] % mod * (pre[j + 1] - (i - (k - p))) % mod) %= mod,
						(f[i + 1][j + 1][k - p + 1] += 1ll * f[i][j][k] * C[k][p] % mod * C[cnt[j + 1]][p] % mod * fac[p] % mod) %= mod;
				}
			}
		} else {
			for (int j = 0; j <= i; j ++ ) {
				for (int k = 0; k <= i && k <= suf[j + 1]; k ++ ) {
					(f[i + 1][j][k + 1] += f[i][j][k]) %= mod;
					for (int p = 0; p <= k && p <= cnt[j + 1]; p ++ )
						(f[i + 1][j + 1][k - p] += 1ll * f[i][j][k] * C[k][p] % mod * C[cnt[j + 1]][p] % mod * fac[p] % mod * (pre[j] - (i - k)) % mod) %= mod;
				}
			}			
		}
	}
	int ans = 0;
	for (int j = 0; j <= n - m; j ++ )
		for (int k = 0; k <= suf[j + 1]; k ++ )
			(ans += 1ll * C[suf[j + 1]][k] * fac[k] % mod * f[n][j][k] % mod) %= mod;
	printf("%d\n", ans);
	return 0;
}
/*
3 1
011
2 2 1
*/