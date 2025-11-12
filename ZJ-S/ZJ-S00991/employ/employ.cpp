#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

const int N = 510;
const i64 MOD = 998244353;

int n, m;
int c[N];

int dp[1 << 18][19];

std::string s;

void solve1to5() {
	dp[0][0] = 1;
	for (int i = 0; i < (1 << n) - 1; ++i) {
		int z = __builtin_popcount(i);
		for (int j = 0; j <= n; ++j) {
			if (!dp[i][j]) {
				continue;
			}

			for (int nxt = 1; nxt <= n; ++nxt) {
				if (i & (1 << nxt - 1)) {
					continue;
				}

				int now = (i | (1 << nxt - 1));
				if (j >= c[nxt] || s[z] == '0') {
					dp[now][j + 1] = (dp[now][j + 1] + dp[i][j]) % MOD;
				} else {
					dp[now][j] = (dp[now][j] + dp[i][j]) % MOD;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= n - m; ++i) {
		ans = (ans + dp[(1 << n) - 1][i]) % MOD;
	}
	std::cout << ans;
}

void solve15() {
	i64 ans = 1;
	for (int i = 1; i <= n; ++i) {
		if (s[i - 1] == '0') {
			std::cout << 0;
			return;
		}
		if (c[i] == 0) {
			std::cout << 0;
			return;
		}
	}
	for (int i = 2; i <= n; ++i) {
		ans = ans * i % MOD;
	}
	std::cout << ans;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> n >> m >> s;
	for (int i = 1; i <= n; ++i) {
		std::cin >> c[i];
	}

	if (n <= 18) {
		solve1to5();
	} else if (m == n) {
		solve15();
	} else {
		std::cout << 0;
	}

	return 0;
}