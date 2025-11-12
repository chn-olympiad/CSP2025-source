#include <cstdint>
#include <iostream>
#define madd(__A__, __B__) (((__A__) += (__B__)) >= mod && ((__A__) -= mod))

using namespace std;

constexpr int N = 510, M = 1 << 18, mod = 998244353;
int n, m, s[N], c[N], f[M][N], cc[M];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char t; cin >> t;
		s[i] = (t == '1');
	}
	for (int i = 1; i <= n; i++) cin >> c[i];
	cc[0] = 0;
	for (int i = 1; i < (1 << n); i++)
		cc[i] = cc[i ^ (i & -i)] + 1;
	f[0][0] = 1;
	for (int i = 0; i < (1 << n) - 1; i++) {
		for (int j = 0; j <= cc[i]; j++) {
			for (int k = 1; k <= n; k++) if (!(i >> (k - 1) & 1)) {
				if (cc[i] - j >= c[k] || !s[cc[i] + 1])
					madd(f[i | (1 << (k - 1))][j], f[i][j]);
				else madd(f[i | (1 << (k - 1))][j + 1], f[i][j]);
			}
		}
	}
	int ans = 0;
	for (int i = m; i <= n; i++)
		madd(ans, f[(1 << n) - 1][i]);
	cout << ans << endl;
	return 0;
}
