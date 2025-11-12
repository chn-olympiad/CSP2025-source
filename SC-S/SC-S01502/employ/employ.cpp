#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 18, P = 998244353;
int n, m, s[N + 1], c[N + 1];
int dp[1 << N][N + 1];

int main() {
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		char ch; cin >> ch, s[i] = ch - '0';
	}
	for (int i = 1; i <= n; i ++) cin >> c[i];
	
	dp[0][0] = 1;
	for (int i = 0; i < (1 << n); i ++) {
		int ppc = __builtin_popcount(i);
		for (int j = 0; j <= ppc; j ++) if (dp[i][j]) {
			for (int k = 0; k < n; k ++) if (!(i >> k & 1)) {
				int aft = j;
				if (s[ppc + 1] == 1 && ppc - j < c[k + 1]) aft ++;
				(dp[i + (1 << k)][aft] += dp[i][j]) %= P;
			}
		}
	}
	
	int ans = 0;
	for (int i = m; i <= n; i ++) (ans += dp[(1 << n) - 1][i]) %= P;
	cout << ans << "\n";
	
	return 0;
}