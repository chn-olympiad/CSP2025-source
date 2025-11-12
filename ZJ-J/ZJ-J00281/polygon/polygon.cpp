#include <bits/stdc++.h>
using uint = unsigned;
using lint = long long;
using pii = std::pair<int, int>;

namespace mtyt {
	constexpr int N = 5e3 + 10;
	constexpr int MOD = 998244353;
	
	lint ans;
	int n, a[N], f[N][N];
	
	lint qpow(lint a, lint b) {
		lint res = 1;
		for (; b; b >>= 1) {
			if (b & 1) (res *= a) %= MOD;
			(a *= a) %= MOD;
		}
		return res;
	}
	
	void main() {
		freopen("polygon.in", "r", stdin);
		freopen("polygon.out", "w", stdout);
		std::cin.tie(0)->sync_with_stdio(0);
		std::cin >> n, f[0][0] = 1;
		for (int i = 1; i <= n; ++i) std::cin >> a[i];
		std::sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; ++i) for (int j = 0; j <= a[n]; ++j) {
			f[i][j] = f[i - 1][j];
			if (j >= a[i]) (f[i][j] += f[i - 1][j - a[i]]) %= MOD;
		}
		for (int i = 1; i <= n; ++i) for (int j = 1; j <= a[n]; ++j) (f[i][j] += f[i][j - 1]) %= MOD;
		
		for (int i = 2; i <= n; ++i) {
			(ans += qpow(2, i - 1) - f[i - 1][a[i]]) %= MOD;
		}
		std::cout << (ans + MOD) % MOD << std::endl;
	}
}

int main() {
	mtyt::main();
	return 0;
}
