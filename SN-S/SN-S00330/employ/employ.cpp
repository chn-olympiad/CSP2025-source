#include <bits/stdc++.h>

using namespace std;
constexpr int mod = 998244353;
int n, m;
basic_string<char> s;
array<int, 505> c;
array < array < array<int, 25>, (1 << 18) + 5 > , 2 > dp;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> s;
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}

	dp[0][0][0] = 1;
	for (int day = 1; day <= n; ++day) {
		for (int state = 0; state < (1 << n); ++state) {
			const int cnt = __builtin_popcount(state);
			for (int i = 0; i <= cnt + 1; ++i) {
				dp[day & 1][state][i] = 0;
			}
		}
		
		for (int state = 0; state < (1 << n); ++state) {
			const int cnt = __builtin_popcount(state);

			if (cnt == day - 1) {
				for (int j = 0; j <= cnt; ++j) {
					for (int i = 0; i < n; ++i) {
						if (!((state >> i) & 1)) {
							if (s[day - 1] == '0' || j >= c[i]) {
								dp[day & 1][state | (1 << i)][j + 1] += dp[(day - 1) & 1][state][j];

								if (dp[day & 1][state | (1 << i)][j + 1] >= mod) {
									dp[day & 1][state | (1 << i)][j + 1] -= mod;
								}
							} else {
								dp[day & 1][state | (1 << i)][j] += dp[(day - 1) & 1][state][j];

								if (dp[day & 1][state | (1 << i)][j] >= mod) {
									dp[day & 1][state | (1 << i)][j] -= mod;
								}
							}
						}
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= n - m; ++i) {
		ans += dp[n & 1][(1 << n) - 1][i];

		if (ans >= mod) {
			ans -= mod;
		}
	}
	cout << ans;
	return 0;
}
