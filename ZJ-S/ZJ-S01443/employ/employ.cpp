#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 510;
const ll mod = 998244353;
int n, m, c[N];
char s[N];
namespace sub1 {
	const int N = 20, T = 270000;
	ll dp[T][N];
	void main () {
		dp[0][0] = 1;
		for (int S = 0; S < (1 << n) - 1; S++) {
			int u = __builtin_popcount (S) + 1;
			for (int i = 0; i <= n; i++) {
				if (dp[S][i] == 0) {
					continue;
				}
				for (int j = 1; j <= n; j++) {
					if (S >> (j - 1) & 1) {
						continue;
					}
					(dp[S | (1 << (j - 1))][i + (s[u] == '0' || i >= c[j])] += dp[S][i]) %= mod;
				}
			}
		}
		ll ans = 0;
		for (int i = 0; i <= n - m; i++) {
			(ans += dp[(1 << n) - 1][i]) %= mod;
		}
		printf ("%lld\n", ans);
	}
}
namespace sub2 {
	void main () {
	}
}
int main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	scanf ("%d%d%s", &n, &m, s + 1);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &c[i]);
	}
	if (n <= 18) {
		sub1::main ();
	} else {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '1') {
				cnt++;
			}
		}
		if (cnt <= 18) {
			sub2::main ();
		}
	}
	return 0;
}