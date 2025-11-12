#include <bits/stdc++.h>
using namespace std;

const int N = 510, mod = 998244353;
int f[20][1 << 18], g[20][1 << 18];
int n, m, c[N]; char s[N];

void Add (int &x, int y) {
	(x += y) >= mod && (x -= mod);
}

signed main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s + 1);
	if (n <= 18) {
		for (int i = 0; i < n; i++) scanf("%d", &c[i]);
		f[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			memset (g, 0, sizeof g);
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < (1 << n); k++) {
					if (!f[j][k]) continue;
					for (int a = 0; a < n; a++) {
						if (k >> a & 1) continue;
						int add = (s[i] == '1') && (i - 1 - j < c[a]);
						Add (g[j + add][k | (1 << a)], f[j][k]);
					}
				}
			}
			memcpy (f, g, sizeof g);
		}
		int ans = 0;
		for (int i = m; i <= n; i++)
			Add (ans, f[i][(1 << n) - 1]);
		printf("%d\n", ans);
	} else if (m == n) {
		bool fl = 1;
		for (int i = 1; i <= n; i++)
			if (s[i] == '0') fl = 0;
		for (int i = 1, c; i <= n; i++) {
			scanf("%d", &c);
			if (c == 0) fl = 0;
		}
		if (!fl) {
			puts ("0");
			return 0;
		}
		int ans = 1;
		for (int i = 1; i <= n; i++)
			ans = 1ll * ans * i % mod;
		printf("%d\n", ans);
	}
	return 0;
}