#include <iostream>
#include <algorithm>

#define MOD 998244353

long long num[5005] = {};
long long dp[5005][10005] = {};

long long fpow(long long x, long long power) {
	long long res = 1;
	long long tmp = x;
	while (power) {
		if (power & 1) {
			res = (res * tmp) % MOD;
		}
		tmp = (tmp * tmp) % MOD;
		power >>= 1;
	}
	
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n = 0;
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> num[i];
	}
	std::sort(num + 1, num + n + 1);
	num[n + 1] = -1;
	
	if (num[n] == num[1]) {
		std::cout << (fpow(2, n) - (n * (n - 1) / 2 + n) % MOD + MOD) % MOD;
		return 0;
	}
	
	dp[0][0] = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 10005; ++j) {
			dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
			dp[i][j + num[i]] = (dp[i][j + num[i]] + dp[i - 1][j]) % MOD;
		}
	}
	
	long long ans = 0;
	int sum = 1;
	for (int i = 3; i <= n; ++i) {
		if (num[i + 1] == num[i]) {
			++sum;
			continue;
		}
		for (int j = num[i] + 1; j < 10005; ++j) {
			ans = (ans + (sum * dp[i - 1][j]) % MOD) % MOD;
		}
		sum = 1;
	}
	
	std::cout << ans;
	
	return 0;
}
