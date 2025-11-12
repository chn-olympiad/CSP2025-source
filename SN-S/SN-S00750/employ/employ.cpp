#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505, M = 18, mod = 998244353;
int fac[N];
void add(int &x, int y) {
	x = x + y >= mod ? x + y - mod : x + y;
}
int n, m;
int w[N], c[N];
namespace s1 {
	int dp[2][(1 << M) + 2][M + 1];
	int main() {
		int nw = 0;
		dp[0][0][0] = 1;
		for (int i = 1; i <= n; i++) {
			nw ^= 1;
			for (int s = 0; s < (1 << n); s++)
				for (int j = 0; j <= m; j++)
					dp[nw][s][j] = 0;
			for (int s = 0; s < (1 << n); s++)
				for (int j = 0; j <= m; j++) {
					if (!dp[nw ^ 1][s][j]) continue;
					for (int k = 0; k < n; k++)
						if (!((s >> k) & 1)) {
							if (w[i] == 0 || j >= c[k + 1]) add(dp[nw][s | (1 << k)][j + 1], dp[nw ^ 1][s][j]);
							else add(dp[nw][s | (1 << k)][j], dp[nw ^ 1][s][j]);
						}
				}
		}
		int ans = 0;
		for (int i = 0; i <= n - m; i++) add(ans, dp[nw][(1 << n) - 1][i]);
		cout << ans << '\n';
		return 0;
	}
}
namespace s2 {
	int cnt[N];
	int main() {
		for (int i = 1; i <= n; i++) cnt[c[i]]++;
		for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
		int ans = 1, ct = 0;
		for (int i = 1; i <= n; i++) 
			if (w[i] == 1) {
				if (cnt[i - 1] <= ct) {
					ans = 0;
					break;
				}
				ans = ans * (cnt[i - 1] - ct) % mod;
				++ct;
			}
		ans = ans * fac[n - ct] % mod;
		cout << (fac[n] - ans + mod) % mod << '\n';
		return 0;
	}
}

namespace s3 {
	int main() {
		for (int i = 1; i <= n; i++)
			if (w[i] == 0 || c[i] == 0) return cout << "0\n", 0;
		cout << fac[n] << '\n';
		return 0;
	}
}

signed main() {
	fac[0] = 1;
	for (int i = 1; i< N; i++) fac[i] = fac[i - 1] * i % mod;
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char cc;
		cin >> cc;
		if (cc == '1') w[i] = 1;
	}
	for (int i = 1; i <= n; i++) cin >> c[i];
	if (n <= 18) return s1::main();
	if (m == 1) return s2::main();
	return s3::main();
}
