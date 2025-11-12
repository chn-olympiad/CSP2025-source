#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, x, y) for (int i = (x); i <= (y); i++)
#define per(i, x, y) for (int i = (x); i >= (y); i--)
int read() {
	int s = 0, f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) s = s * 10 + (c ^ 48), c = getchar();
	return s * f;
}
constexpr int N = 505, mod = 998244353;
int n, m, a[N], c[N], fac[N], ifac[N], inv[N], dp[19][19][1 << 18];
string s;
int A(int x, int y) {
	if (x < y || x < 0 || y < 0) return 0;
	return fac[x] * ifac[x - y] % mod;
}
int C(int x, int y) {
	if (x < y || x < 0 || y < 0) return 0;
	return fac[x] * ifac[x - y] % mod * ifac[y] % mod;
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m; cin >> s; s = '*' + s;
	fac[0] = ifac[0] = fac[1] = ifac[1] = inv[1] = 1;
	rep (i, 2, n) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
		ifac[i] = ifac[i - 1] * inv[i] % mod;
	}
	rep (i, 1, n) {
		a[i] = read();
		c[a[i]]++;
	}
	sort(a + 1, a + n + 1);
	if (m == n) {
		bool bl = 1;
		rep (i, 1, n) bl &= (s[i] == '1');
		if (a[1] != 0 && bl) cout << A(n, n) << '\n';
		else cout << 0;
		return 0;
	}
	int F = (1 << n) - 1;
	dp[0][0][0] = 1;
	rep (i, 0, n - 1) {
		rep (j, 0, i) {
			rep (S, 0, F) {
				if (__builtin_popcount(S) != i) continue;
				rep (k, 1, n) if (!((S >> (k - 1)) & 1)) {
					if (a[k] <= j || s[i + 1] == '0') {
						(dp[i + 1][j + 1][S ^ (1 << (k - 1))] += dp[i][j][S]) %= mod;
					} else {
						(dp[i + 1][j][S ^ (1 << (k - 1))] += dp[i][j][S]) %= mod;
					}
				}
			}
		}
	}
	int ans = 0;
	rep (i, 0, n - m) (ans += dp[n][i][F]) %= mod;
	cout << ans;
	return 0;
}
