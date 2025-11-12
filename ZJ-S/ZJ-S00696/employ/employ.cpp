#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 17;
const int Mod = 998244353;
int f[20][1 << 18];
int n, m, ans, s[N], c[N];
void _2solve() {
	for(int i = 0; i < n; ++i) c[i] = c[i + 1];
	ans = 0;
	f[0][0] = 1;
	for(int i = 0; i <= n; ++i)
		for(int S = 0; S < (1 << n); ++S) {
			int t = __builtin_popcount(S);
			for(int j = 0; j < n; ++j)
				if(S >> j & 1) {
					int ni = i + ((1 - s[t]) | (c[j] <= i));
					f[ni][S] = (f[ni][S] + f[i][S ^ (1 << j)]) % Mod;
				}
		}
			
	for(int i = 0; i <= n - m; ++i) ans = (ans + f[i][(1 << n) - 1]) % Mod;
	cout << ans << '\n';
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		char c; cin >> c;
		s[i] = c - '0';
	}
	for(int i = 1; i <= n; ++i) cin >> c[i];
	if(n == m) {
		for(int i = 1; i <= n; ++i)
			if(s[i] == 0 || c[i] == 0) {
				cout << 0 << '\n';
				return 0;
			}
		int fr = 1;
		for(int i = 1; i <= n; ++i) fr = 1ll * fr * i % Mod;
		cout << fr << '\n';
		return 0;
	}
	_2solve();
	return 0;
}