#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 998244353;
int n, m, c[505], f[2][1 << 18][19], dp[505][505];
char s[505];
inline void upd(int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
}
inline void solve() {
	int ans = 0;
	
	
	cout << ans << '\n';
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> (s + 1);
	int cc = 0;
	for (int i = 1; i <= n; i++) 
		cc += (s[i] == '1');
	for (int i = 0; i < n; i++)
		cin >> c[i];
//	if (cc == n) {
//		solve();
//		return 0;
//	}
	f[0][0][0] = 1;
	for (int k = 0; k < n; k++) {
		memset(f[k & 1 ^ 1], 0, sizeof f[k & 1 ^ 1]);
		for (int t = 0; t <= k; t++) {
			for (int i = 0; i < (1 << n); i++) {
				if (!f[k & 1][i][t])
					continue;
				int ct = __builtin_popcount(i);
				if (k != ct)
					continue;
				for (int j = 0; j < n; j++) {
					if (!(i >> j & 1)) {
						int g = ct - t;
						if (g >= c[j] || s[ct + 1] == '0')
							upd(f[k & 1 ^ 1][i | (1 << j)][t], f[k & 1][i][t]);
						else
							upd(f[k & 1 ^ 1][i | (1 << j)][t + 1], f[k & 1][i][t]);
					}
				}
			}
//			cout << t << ':';
//			for (int i = 0; i < (1 << n); i++) {
//				for (int j = 0; j < 3; j++)
//					cout << (i >> j & 1);
//				cout << ' ' << f[k & 1][i][t] << " \n"[i == (1 << n) - 1];
//			}
		}
	}
	int ans = 0;
	for (int i = m; i <= n; i++) {
		upd(ans, f[n & 1][(1 << n) - 1][i]);
	}
	cout << ans << '\n';
	return 0;
}