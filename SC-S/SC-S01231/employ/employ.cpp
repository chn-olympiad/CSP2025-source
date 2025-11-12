#include <cstdio>
#define Mod 998244353
using namespace std;

int read() {
	int num = 0;
	char c = getchar();
	while (c < '0' || c > '9') {
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		num = num * 10 + (c & 15), c = getchar(); 
	}
	return num;
}

int get() {
	char c = getchar();
	while ((c ^ '0') && (c ^ '1')) {
		c = getchar();
	}
	return (c == '1');
}

int n, m, suf[501], f[501][501], g[501][501], a[500];

void init() {
	n = read(), m = n - read();
	for (int i = 0; i < n; i ++) {
		a[i] = get();
	}
	for (int i = 0; i < n; i ++) {
		suf[read()] ++;
	}
	for (int i = n; i; i --) {
		suf[i - 1] += suf[i];
	}
	return;
}

void calculate() {
	for (int i = 0; i <= m; i ++) {
		f[i][0] = 1;
	}
	for (int i = n - 1; ~i; i --) {
		for (int j = 0; j < m; j ++) {
			for (int k = 0; k <= n; k ++) {
				g[j][k] = f[j + 1][k];
			}
		}
		if (a[i]) {
			for (int j = 0; j < m; j ++) {
				for (int k = 1; k <= n; k ++) {
					g[j][k] = (
						g[j][k] - 1ll * (suf[j + 1] - k + 1) * f[j + 1][k - 1] % Mod + Mod
					) % Mod;
				}
			}
			for (int j = 0; j <= m; j ++) {
				for (int k = 1; k <= n; k ++) {
					g[j][k] = (g[j][k] + 1ll * (suf[j + 1] - k + 1) * f[j][k - 1]) % Mod;
				}
			}
		}
		for (int j = 0; j <= m; j ++) {
			for (int k = 0; k <= n; k ++) {
				f[j][k] = g[j][k], g[j][k] = 0;
			}
		}
	}
	int ans = 0, fac = 1;
	for (int i = n; ~i; i --) {
		ans = (ans + 1ll * fac * f[0][i]) % Mod, fac = 1ll * (n - i + 1) * fac % Mod;
	}
	printf("%d\n", ans);
	return;
}

void solve() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	init(), calculate();
	return;
}

int main() {
	solve();
	return 0;
}