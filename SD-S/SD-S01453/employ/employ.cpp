#include <cstdio>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 505;
char s[N];
int n, m, c[N], f[1 << 18][18];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d %d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	f[0][0] = 1;
	for (int S = 0; S < (1 << n); S++) {
		for (int i = 0; i <= n; i++) {
			if (f[S][i] == 0) {
				continue;
			}
			for (int j = 0; j < n; j++) {
				if (((S >> j) & 1) == 1) {
					continue;
				}
				int T = S | (1 << j);
				if (s[__builtin_popcount(T)] == '1' && i < c[j + 1]) {
					(f[T][i] += f[S][i]) %= mod;
				} else {
					(f[T][i + 1] += f[S][i]) %= mod;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n - m; i++) {
		(ans += f[(1 << n) - 1][i]) %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}
