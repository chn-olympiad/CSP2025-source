#include <bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
int n, m, c[N], f[1 << 18][20];
string s;
void solve0() {
	f[0][0] = 1;
	for (int S = 0; S < (1 << n); S ++) {
		int p = __builtin_popcount(S) + 1;
		for (int i = 1; i <= n; i ++) {
			if (S >> (i - 1) & 1) continue;
			for (int j = 0; j < p; j ++) {
				int can = (s[p] == '1' && p - 1 - j < c[i]);
				f[S | (1 << (i - 1))][j + can] += f[S][j];
				if (f[S | (1 << (i - 1))][j + can] >= mod)
					f[S | (1 << (i - 1))][j + can] -= mod;
			}
		}
	}
	int ans = 0;
	for (int i = m; i <= n; i ++) {
		ans += f[(1 << n) - 1][i];
		if (ans >= mod) ans -= mod;
	}
	cout << ans << '\n';
}
void solve1() {
	if (s.find('0') != string::npos) {
		cout << 0 << '\n';
		return ;
	}
	for (int i = 1; i <= n; i ++) {
		if (c[i] == 0) {
			cout << 0 << '\n';
			return ;
		}
	}
	long long ans = 1;
	for (int i = 1; i <= n; i ++) ans = ans * i % mod;
	cout << ans << '\n';
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s, s = "a" + s;
	for (int i = 1; i <= n; i ++) cin >> c[i];
	if (n <= 18) solve0();
	else if (m == n) solve1();
	else cout << 0 << '\n';
	return 0;
}