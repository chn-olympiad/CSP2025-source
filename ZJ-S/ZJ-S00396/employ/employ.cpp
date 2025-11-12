#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define INF_LL 0x3f3f3f3f3f3f3f3f
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 500 + 5, P = 998244353;

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = 1ll * res * a % P;
		}
		a = 1ll * a * a % P;
		b >>= 1;
	}
	return res;
}
int fac[N], ifac[N];
void init(int len) {
	fac[0] = 1;
	for (int i = 0; i < len; ++i) {
		fac[i + 1] = 1ll * fac[i] * (i + 1) % P;
	}
	ifac[len] = qpow(fac[len], P - 2);
	for (int i = len; i > 0; --i) {
		ifac[i - 1] = 1ll * ifac[i] * i % P;
	}
}
int C(int n, int m) {
	return (n < m || m < 0 ? 0 : 1ll * fac[n] * ifac[m] % P * ifac[n - m] % P);
}

int n, m;

string str;

int dp[N][N][N];

int s[N], c[N], p[N];

int cnt[N], pre[N], suf[N];

void reduce(int &x, ll y) {
	x = (x + y) % P;
}

signed main() {
	assert(freopen("employ.in", "r", stdin));
	assert(freopen("employ.out", "w", stdout));

	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	cin >> str;
	int cur = 0;
	for (int i = 1; i <= n; ++i) {
		s[i] = str[i - 1] ^ '1';
		cur += s[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		++cnt[c[i]];
	}
	if (n <= 10) {
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			p[i] = i;
		}
		do {
			int cur = 0;
			for (int i = 1; i <= n; ++i) {
				if (c[p[i]] <= cur || s[i] == 1) {
					++cur;
				}
			}
			ans += (cur <= n - m);
		} while (next_permutation(p + 1, p + n + 1));
		cout << ans << '\n';
		return 0;
	}
	init(n);
	pre[0] = cnt[0];
	for (int i = 1; i <= n; ++i) {
		pre[i] = pre[i - 1] + cnt[i];
	}
	suf[n] = cnt[n];
	for (int i = n; i >= 0; --i) {
		suf[i] = suf[i + 1] + cnt[i];
	}

	for (int i = cur; i <= n - m; ++i) {
		dp[n + 1][i][0] = 1;
	}
	for (int i = n; i >= 1; --i) {
		for (int j = cur; j <= i; ++j) {
			for (int k = 0; k <= n - i + 1; ++k) {
				if (!dp[i + 1][j][k]) {
					continue;
				}
				// cout << i + 1 << ' ' << j << ' ' << k << ' ' << dp[i + 1][j][k] << '\n';
				if (s[i] == 1) {
					if (j == 0) {
						continue;
					}
					for (int p = 0; p <= k + 1; ++p) {
						int v1 = 1ll * max(0, (suf[j] - (n - i - k))) * C(cnt[j - 1], k - p) % P * C(k, k - p) % P;
						int v2 = 1ll * C(k, k - p) * C(cnt[j - 1], k - p + 1) % P;
						int v3 = C(cnt[j - 1], k - p + 1);
						reduce(dp[i][j - 1][p], (1ll * v1 + v2 + v3) * dp[i + 1][j][k]);
					}
				}
				else {
					reduce(dp[i][j][k], 1ll * max(0, (suf[j + 1] - (n - i - k))) * dp[i + 1][j][k]);
					// cout << 1ll * max(0, (suf[j + 1] - (n - i - k))) << '\n';
					if (j == 0) {
						continue;
					}
					for (int p = 0; p <= k + 1; ++p) {
						int v2 = 1ll * C(k, k - p) * C(cnt[j - 1], k - p + 1) % P;
						int v3 = C(cnt[j - 1], k - p + 1);
						// cout << i << ' ' << j << ' ' << k << ' ' << p << ' ' << v2 << ' ' << 1ll * (v2 + v3) * dp[i + 1][j][k] << '\n';
						reduce(dp[i][j - 1][p], 1ll * (v2 + v3) * dp[i + 1][j][k]);
					}
				}
			}
		}
		cur -= s[i];
	}
	cout << dp[1][0][0] << '\n';

	return 0;
}