#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 505;
const int mod = 998244353;

inline void addmod(int &x) {
	(x >= mod) && (x -= mod);
}

int n, m, a[N], ans, f[1 << 18][19];

string s;

int main() {
	assert(freopen("employ.in", "r", stdin));
	assert(freopen("employ.ans", "w", stdout));
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m >> s;
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
	return 0;
}