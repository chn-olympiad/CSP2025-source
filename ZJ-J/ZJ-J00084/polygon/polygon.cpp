#include <bits/stdc++.h>

using namespace std;

#define int unsigned long long

int _;
inline int read() {int s = 0, w = 1;char ch = getchar();while (ch < '0' || ch > '9') {if (ch == '-') w *= -1;ch = getchar();}while (ch >= '0' && ch <= '9') {s = (s << 3) + (s << 1) + (ch ^ 48);ch = getchar();}return s * w;}
inline void write(int x) {if (x < 0) x = -x, putchar('-');if (x > 9) write(x / 10);putchar(x % 10 + '0');}

const int N = 5005;
const int mod = 998244353;
int n, a[N];
int ans = 0, fac[N];

inline int qp(int c, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * c % mod;
		b >>= 1;
		c = c * c % mod;
	}
	return res;
}

inline void init(int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = (fac[i - 1] * i) % mod; 
	}
}

inline int C(int r, int k) {
	return fac[r] * qp(fac[r - k], mod - 2) % mod * qp(fac[k], mod - 2) % mod;
}

void dfs(int x, int sum, int mx, int cnt) {
//	cout << x << ' ' << sum << ' ' << mx << ' ' << cnt << '\n';
	if (x == n + 1) {
		if (sum > mx * 2 && cnt > 2) {
			ans = (ans + 1) % mod;
		}
		return;
	}
	dfs(x + 1, sum + a[x], max(mx, a[x]), cnt + 1);
	dfs(x + 1, sum, mx, cnt);
}

inline void solve() {
	n = read();
	int mx = 0;
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		mx = max(mx, a[i]);
	}
	if (mx == 1) {
		init(n);
		for (int i = 3; i <= n; ++i) {
			ans = (ans + C(n, i)) % mod;
		}
		write(ans);
		return ;
	}
	
	dfs(1, 0, 0, 0);
	write(ans % mod);
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
//	_ = read();
	_ = 1;
	for (int i = 1; i <= _; ++i) solve();
	return 0;
}
