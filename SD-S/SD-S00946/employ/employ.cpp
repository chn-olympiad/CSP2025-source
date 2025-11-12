#include <cstdio>
#include <iostream>
namespace {
using namespace std;
const int N = 20, P = 998244353;
int n, m, c[N], f[1 << 18][N], ans;
char s[N];
} // namespace
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> (s + 1), f[0][0] = 1;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 0; i < 1 << n; i++) {
		int p = __builtin_popcount(i);
		for (int j = 0; j <= p; j++)
			for (int k = 1; k <= n; k++)
				if (!(i & (1 << (k - 1))))
					f[i | (1 << (k - 1))][j + (s[p + 1] == '1' && p - j < c[k])] += f[i][j];
	}
	for (int i = m; i <= n; i++) ans += f[(1 << n) - 1][i];
	cout << ans;
}
