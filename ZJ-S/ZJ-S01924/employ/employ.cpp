#include<bits/stdc++.h>
using namespace std;
const int N = 19, p = 998244353;
int dp[1 << N][N], n, m, c[N];
string s;
inline void Add(int &x, int y) {
	x += y; if(x >= p) x -= p;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> n >> m >> s;
	for(int i = 0; i < n; i++) cin >> c[i];
	dp[0][0] = 1;
	for(int i = 1; i < (1 << n); i++) {
		int k = __builtin_popcount(i);
		for(int j = 0; j < n; j++) if(i & (1 << j)) {
			if(s[k - 1] == '0') {
				for(int o = 0; o < k; o++) {
					Add(dp[i][o], dp[i - (1 << j)][o]);
				}
			}
			else {
				if(k - 1 >= c[j]) for(int o = 0; o < k - c[j]; o++) Add(dp[i][o], dp[i - (1 << j)][o]);
				for(int o = max(1, k - c[j] + 1); o <= k; o++) Add(dp[i][o], dp[i - (1 << j)][o - 1]);
			}
		}
	}
	int ans = 0;
	for(int i = m; i <= n; i++) Add(ans, dp[(1 << n) - 1][i]);
	cout << ans << '\n';
	return 0;
}
