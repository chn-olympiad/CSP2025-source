#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 505;
const int mod = 998244353;

inline void addmod(int &x) {
	(x >= mod) && (x -= mod);
}

int n, m, ans, a[N], b[N], C[N][N], fac[N], f[N][N][N];

string s;

int main() {
	assert(freopen("employ.in", "r", stdin));
	assert(freopen("employ.out", "w", stdout));
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; ++i) {
		int u;
		cin >> u;
		++a[u];
	}
	b[0] = a[0];
	for (int i = 1; i <= n; ++i) {
		b[i] = b[i - 1] + a[i];
	}
	s = "#" + s;
	for (int i = 0; i <= n; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			addmod(C[i][j] = C[i - 1][j] + C[i - 1][j - 1]);
		}
	}
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = (ll)fac[i - 1] * i % mod;
	}
	f[0][0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			for (int k = 0; k < i; ++k) {
				addmod(f[i][j][k + 1] += f[i - 1][j][k]);
			}
		}
		for (int j = 0; j <= n; ++j) {
			for (int k = 0; k < i; ++k) {
				for (int p = 0; p <= min(k, a[j + 1]); ++p) {
					addmod(f[i][j + 1][k - p] += (ll)f[i - 1][j][k] * (b[j] - (i - k - 1)) % mod * fac[p] % mod * C[k][p] % mod * C[a[j + 1]][p] % mod);
				}
			}
		}
	}
	for (int i = m; i <= n; ++i) {
		int cnt = 0;
		for (int j = n - i + 1; j <= n; ++j) {
			cnt += a[j];
		}
		addmod(ans += (ll)f[n][n - i][cnt] * fac[cnt] % mod);
	}
	cout << ans << "\n";
	return 0;
}