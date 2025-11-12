#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 505;
const int mod = 998244353;

inline void addmod(int &x) {
	(x >= mod) && (x -= mod);
}

inline void addmod(ll &x) {
	(x >= mod) && (x -= mod);
}

int n, m, a[N], ans;

string s;

namespace sub1 {
	int f[1 << 18][19];

	inline void solve() {
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		f[0][0] = 1;
		for (int i = 0; i < (1 << n); ++i) {
			for (int j = 0; j < n; ++j) {
				if ((i >> j) & 1) {
					continue;
				}
				for (int k = 0; k <= n; ++k) {
					int p = (s[__builtin_popcount(i)] == '0') || (a[j] <= k);
					addmod(f[i | (1 << j)][k + p] += f[i][k]);
				}
			}
		}
		for (int i = m; i <= n; ++i) {
			addmod(ans += f[(1 << n) - 1][n - i]);
		}
		cout << ans << "\n";
	}
}

namespace sub2 {
	int a[N];

	inline void solve() {
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for (auto c: s) {
			if (c == '0') {
				cout << "0\n";
				return;
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (a[i] == 0) {
				cout << "0\n";
				return;
			}
		}
		ll ans = 1;
		for (int i = 1; i <= n; ++i) {
			ans = ans * i % mod;
		}
		cout << ans << "\n";
	}
}

namespace sub3 {
	int a[N], b[N];

	inline void solve() {
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			for (int j = a[i]; j <= n; ++j) {
				++b[j];
			}
		}
		ll ans = 1, cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (s[i - 1] == '0') {
				++cnt;
				continue;
			}
			if (b[i - 1] <= i - 1 - cnt) {
				ans = 0;
			} else {
				ans = ans * (b[i - 1] - (i - 1 - cnt)) % mod;
			}
		}
		for (int i = 1; i <= cnt; ++i) {
			ans = ans * i % mod;
		}
		ll ans0 = 1;
		for (int i = 1; i <= n; ++i) {
			ans0 = ans0 * i % mod;
		}
		addmod(ans0 += mod - ans);
		cout << ans0 << "\n";
	}
}

int main() {
	assert(freopen("employ.in", "r", stdin));
	assert(freopen("employ.out", "w", stdout));
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m >> s;
	if (n <= 18) {
		sub1::solve();
	} else if (m == n) {
		sub2::solve();
	} else if (m == 1) {
		sub3::solve();
	}
	return 0;
}