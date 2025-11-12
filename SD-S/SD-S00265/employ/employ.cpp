#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using i64 = long long;
using pii = pair<int, int>;

const int N = 18, mod = 998244353;

int n, m;
string s;
int c[N];
int dp[1 << N][N];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m >> s;
	
	for (int i = 0; i < n; i ++)
		cin >> c[i];
		
	dp[0][0] = 1;
	for (int i = 0; i < 1 << n; i ++) {
		int t = __builtin_popcount(i);
//		cout << i << ": ";
//		for (int j = 0; j < n; j ++) cout << dp[i][j] << ' ';
//		cout << '\n';
		for (int j = 0; j < n; j ++)
			if (~i >> j & 1) {
				for (int k = 0; k <= n; k ++)
					(dp[i | (1 << j)][k + (s[t] == '0' || k >= c[j])] += dp[i][k]) %= mod;
			}
	}
	
	int res = 0;
	for (int i = 0; i <= n - m; i ++)
		(res += dp[(1 << n) - 1][i]) %= mod;
		
	cout << res << '\n';
	
	return 0;
}
