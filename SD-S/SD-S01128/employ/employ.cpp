#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;

const int N = 18;
int n, m, c[N];
long long dp[1 << N][N];
char s[N];

inline void solve() {
	scanf("%d%d%s", &n, &m, s);
	int cnt = 0;
	for (int i = 1; i <= n; i++) 
		cnt += s[i] == '0';
	for (int i = 0; i < n; i++) 
		scanf("%d", &c[i]);
	dp[0][0] = 1;
	for (int i = 0; i < 1 << n; i++) {
		int pop_count = 0;
		for (int j = 0; j < n; j++) 
			pop_count += (i >> j & 1);
		for (int j = 0; j <= pop_count; j++) {
			for (int k = 0; k < n; k++) 
				if (!(i >> k & 1)) {
					if (s[pop_count] == '0' || pop_count - j >= c[k]) {
						dp[i + (1 << k)][j] += dp[i][j];
						dp[i + (1 << k)][j] %= mod;
					}
					else {
						dp[i + (1 << k)][j + 1] += dp[i][j];
						dp[i + (1 << k)][j + 1] %= mod;
					}
				}
		}
	}
	long long ans = 0;
	for (int i = m; i <= n; i++) {
		ans += dp[(1 << n) - 1][i];
		ans %= mod;
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int t = 1;
//	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
