#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int n, m;
int f[(1 << 18) + 10][20];
string s;
int c[510];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	
	if (m == n) {
		for (int i = 1; i <= n; ++i) {
			if (s[i - 1] == '0') {
				cout << 0 << endl;
				return 0;
			}
		}
		
		for (int i = 1; i <= n; ++i) {
			if (!c[i]) {
				cout << 0 << endl;
				return 0;
			}
		}
		
		int ans = 1;
		for (int i = 1; i <= n; ++i) ans = 1ll * ans * i % mod;
		
		cout << ans << endl;
		return 0;
	}
	
	f[0][0] = 1;
	for (int i = 0; i < (1 << n); ++i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) cnt += ((i >> j) & 1);
		for (int p = 0; p <= cnt; ++p) {
			if (!f[i][p]) continue;

			for (int j = 0; j < n; ++j) {
				if (!((i >> j) & 1)) {
					bool is = (p >= c[j + 1]) || (s[cnt] == '0');
					
					f[i | (1 << j)][p + is] += f[i][p];
//					cout << i << ' ' << p << ' ' << f[i][p] << endl;
					if (f[i | (1 << j)][p + is] >= mod) f[i | (1 << j)][p + is] -= mod;
				}
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i <= n - m; ++i) {
		ans += f[(1 << n) - 1][i];
		
		if (ans >= mod) ans -= mod;
	}
	
	cout << ans << endl;

	return 0;
}

