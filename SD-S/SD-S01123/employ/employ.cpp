#include <bits/stdc++.h>
#define ll long long
#define mid ((l + r) >> 1)
#define lowbit(x) (x & -x)

using namespace std;

constexpr int N = 25, M = 1e6 + 5, mod = 998244353;

int n, m;
int c[N], s[N];
ll f[M][N];
char str[N];

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> n >> m >> str + 1;
	for (int i = 1; i <= n; ++i) {
		s[i] = (str[i] == '1');
	}
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	
	f[0][0] = 1;
	for (int i = 1; i < (1 << n); ++i) {
		int x = __builtin_popcount(i);
		for (int j = 0; j <= x; ++j) {
			for (int k = 1; k <= n; ++k) {
				if (((i >> (k - 1)) & 1) == 0) continue;
				if (s[x] == 0 || (x - 1) - j >= c[k]) {
					f[i][j] += f[i ^ (1 << (k - 1))][j];
				} else if (x - j < c[k]) {
					f[i][j] += f[i ^ (1 << (k - 1))][j - 1];
				}
			}
			f[i][j] %= mod;
		}
	}
	
//	cerr << f[1][1] << ' ' << f[2][1] << ' ' << f[3][2] << '\n';
	
	ll ans = 0;
	for (int i = m; i <= n; ++i) {
		ans += f[(1 << n) - 1][i];
	}
	ans %= mod;
	cout << ans << '\n';
	
	return 0;
}
