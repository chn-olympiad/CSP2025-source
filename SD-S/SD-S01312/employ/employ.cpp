#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

namespace PTqwq {
	
int readqwq() {
	int x = 0;
	bool f = false;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) f |= (c == '-');
	for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c - '0');
	if (f) {
		x = -x;
	}
	return x;
}

ll readllqwq() {
	ll x = 0;
	bool f = false;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) f |= (c == '-');
	for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c - '0');
	if (f) {
		x = -x;
	}
	return x;
}

const ll mod = 998244353;

int n, m, a[571], b[571], ord[571];
char s[571];
ll binomQ[571][571], fac[571];
ll f[2][571][571];

void Solve() {
	fac[0] = 1;
	for (ll i = 1; i <= 516; ++ i) {
		fac[i] = fac[i - 1] * i % mod;
	}
	for (int i = 0; i <= 516; ++ i) {
		for (int j = 0; j <= 516; ++ j) {
			binomQ[i][j] = 0;
		}
	}
	binomQ[0][0] = 1;
	for (int i = 1; i <= 516; ++ i) {
		binomQ[i][0] = 1;
		for (int j = 1; j <= i; ++ j) {
			binomQ[i][j] = (binomQ[i - 1][j - 1] + binomQ[i - 1][j]) % mod;
		} 
	}
	
	n = readqwq();
	m = readqwq();
	scanf("%s", s + 1);
	for (int i = 0; i <= n; ++ i) {
		a[i] = 0;
	}
	for (int i = 1; i <= n; ++ i) {
		int x = readqwq();
		a[x] ++;
		ord[i - 1] = x;
	}
	for (int i = 0; i <= n; ++ i) {
		b[i] = a[i];
	}
	for (int i = 1; i <= n; ++ i) {
		b[i] += b[i - 1];
	}
	for (int i = 0; i < 2; ++ i) {
		for (int j = 0; j <= n; ++ j) {
			for (int k = 0; k <= n; ++ k) {
				for (int l = 0; l <= n; ++ l) {
					f[i][j][k] = 0;
				}
			}
		}
	}
	f[0][0][0] = 1;
	for (int i = 0; i < n; ++ i) {
		int ch = s[i + 1] - '0';
		ch ^= 1;
		for (int j = 0; j <= n; ++ j) {
			for (int k = 0; k <= n; ++ k) {
				for (int l = 0; l <= n; ++ l) {
					f[(i + 1) & 1][j][k] = 0;
				}
			}
		}
		for (int j = 0; j <= n; ++ j) {
			int pre = 0;
			for (int k = 0; k <= j; ++ k) {
				pre += a[k];
			}
			for (int k = 0; k <= n; ++ k) {
				for (int l = 0; l <= 0; ++ l) {
					if (f[i & 1][j][k] != 0) {
						for (int u = 0; u < 2; ++ u) {
							int curd = (u | ch);
							ll coefK = 1;
							if (u) {
								coefK = pre - (i - k);
							}
							if (coefK < 0) {
								continue;
							}
							if (!curd) {
								f[(i + 1) & 1][j][k + 1 - u] = (f[(i + 1) & 1][j][k + 1 - u] + f[i & 1][j][k] * coefK) % mod; 
							} else {
								coefK = coefK * f[i & 1][j][k] % mod;
								for (int v = 0; v <= a[j + 1] && v <= k + 1 - u; ++ v) {
									f[(i + 1) & 1][j + 1][k + 1 - u - v] = (f[(i + 1) & 1][j + 1][k + 1 - u - v] + 
									coefK * binomQ[k + 1 - u][v] % mod * binomQ[a[j + 1]][v] % mod * fac[v] % mod) % mod;
								}
							}
						}
					}	
				}
			}
		}
	}
	ll ans = 0;
	for (int i = m; i <= n; ++ i) {
		int cnt2 = 0;
		for (int j = n - i + 1; j <= n; ++ j) cnt2 += a[j];
		ans = (ans + f[n & 1][n - i][cnt2] * fac[cnt2]) % mod;
	}
	ans = (ans % mod + mod) % mod;
	ans %= mod;
	printf("%lld\n", ans);
}

}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	PTqwq::Solve();
	
	return 0;
}
