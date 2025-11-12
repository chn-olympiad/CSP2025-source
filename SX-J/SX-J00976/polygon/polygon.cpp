#include <bits/stdc++.h>
using namespace std;

#define For(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<=(y);++i)
#define foR(i,x,y,...) for(int i=(x),##__VA_ARGS__;i>=(y);--i)
#define Rep(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<(y);++i)
typedef long long ll;
#define fi first
#define se second
#define me(s,x) memset(s,x,sizeof s)
#define pb emplace_back
const int mod = 998244353, N = 5005, M = 5e4+5, N1 = 505, M1 = 10005;
ll a[N], s[N];
ll f[N1][M1];
ll fac[N], inv[N];
ll n;
ll ans;

ll Pow(ll x, ll y) {
	ll t = 1;
	for (; y; y >>= 1, x = x * x % mod)
		if (y & 1)
			t = t * x % mod;
	return t;
}

void calc() {
	fac[0] = fac[1] = 1;
	For(i, 2, 5000) fac[i] = fac[i - 1] * i % mod;
	inv[5000] = Pow(fac[5000], mod - 2);
	foR(i, 4999, 0) inv[i] = inv[i + 1] * (i + 1) % mod;
}

ll C(int n, int m) {
	if (n < m)
		return 0;
	return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

void MAIN() {
	cin >> n;
	For(i, 1, n) cin >> a[i];
	if (*max_element(a + 1, a + n + 1) == 1) {
		For(i, 3, n) {
			ans += C(n, i);
			ans %= mod;
		}
		cout << ans << endl;
		return;
	}
	sort(a + 1, a + n + 1);
	For(i, 1, n) s[i] = s[i - 1] + a[i];
	f[1][a[1]] = 1;
	f[2][a[2]] = 1;
	f[2][a[1] + a[2]] = 1;
	For(i, 3, n) f[i][a[i]] = 1;
	For(i, 3, n) {
		For(j, a[i], s[i]) {
			Rep(k, 1, i) {
				(f[i][j] += f[k][j - a[i]]) %= mod;
			}
		}
	}
	For(i, 3, n) {
		For(j, a[i] * 2 + 1, s[i]) {
			ans += f[i][j];
			ans %= mod;
		}
	}
	cout << ans << endl;
}

signed main() {
	freopen("polygon.in", "r", stdin), freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(nullptr);
	calc();
	int t = 1;
	while (t--) {
		MAIN();
	}
	return 0;
}
