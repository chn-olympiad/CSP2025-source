#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool o1;
const ll P = 998244353;
inline ll qpw(ll x, ll y) {
	ll ans = 1;
	while (y) {
		if (y & 1) ans = ans * x % P;
		x = x * x % P, y >>= 1;
	}
	return ans;
}

const int N = 510;
ll f[N][N], fac[N], ifac[N], g[N][N];
int n, m, c[N], s[N], cnt[N];
string str;
inline ll C(int x, int y) { return x < y ? 0 : fac[x] * ifac[y] % P * ifac[x - y] % P; }
inline ll A(int x, int y) { return x < y ? 0 : fac[x] * ifac[x - y] % P; }
inline void soft(int j, int k, ll val) {
	if (j == n) return;
	for (int i = 0; i <= min(cnt[j + 1], k); i++)
		f[j + 1][k - i] = (f[j + 1][k - i] + A(cnt[j + 1], i) * C(k, i) % P * val) % P;
}
bool o2;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	// cerr << (&o2 - &o1) / 1048576. << endl;
	cin >> n >> m >> str, str = " " + str;
	for (int i = 1; i <= n; i++) cin >> c[i], ++s[c[i]], ++cnt[c[i]];
	for (int i = 1; i <= n; i++) s[i] += s[i - 1];
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % P;
	ifac[n] = qpw(fac[n], P - 2);
	for (int i = n - 1; ~i; i--) ifac[i] = ifac[i + 1] * (i + 1) % P;
	f[0][0] = 1;
	// cerr << "find fac:" << fac[n] << ' ' << ifac[2] << ' ' << ifac[n] << endl;
	// for (int i = 0; i <= n; i++) cerr << cnt[i] << ' ' << s[i] << endl;
	for (int i = 1; i <= n; i++) {
		memcpy(g, f, sizeof(g));
		memset(f, 0, sizeof(f));
		// f[i][j] j ge > i, i - j ge <= i
		if (str[i] == '0') {
			for (int j = 0; j <= i; j++)
				for (int k = 0; k <= i; k++) if (g[j][k]) {
					// f[j + 1][k] += g[j][k] * (s[j] - (i - k)); <= i 
					// f[j + 1][k + 1] += g[j][k]; > i
					// cerr << "find val0:" << i << ' ' << j << ' ' << k << endl;
					if (s[j] - (i - 1 - k) > 0) soft(j, k, g[j][k] * (s[j] - (i - 1 - k)) % P);
					soft(j, k + 1, g[j][k]);
				}
		} else {
			for (int j = 0; j <= i; j++)
				for (int k = 0; k <= i; k++) if (g[j][k]) {
					// cerr << "find val:" << i << ' ' << j << ' ' << k << endl;
					if (s[j] - (i - 1 - k) > 0) soft(j, k, g[j][k] * (s[j] - (i - 1 - k)) % P);
					f[j][k + 1] = (f[j][k + 1] + g[j][k]) % P;
				}
		}
	}
	ll ans = 0;
	for (int i = 0; i <= n - m; i++) ans += f[i][s[n] - s[i]] * fac[s[n] - s[i]] % P;
	// cerr << ans % P << endl;
	cout << (ans % P + P) % P << endl;
	// cerr << double(clock()) / CLOCKS_PER_SEC << endl;
	return 0;
}