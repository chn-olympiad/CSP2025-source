#include<bits/stdc++.h>
#define int long
using namespace std;
const int N = 5e3 + 10;
const int M = 5e4 + 10;
const int mod = 998244353;
int n, a[N], sum, ans, dp[510][M];
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i], sum += a[i];
	sort(a + 1, a + 1 + n);
	dp[0][0] = 1;
	for(int i = 1; i < n; i ++) {
		for(int j = 0; j <= sum; j ++) {
			dp[i][j] += dp[i - 1][j];
			dp[i][j] %= mod;
			if(j - a[i] >= 0){
				dp[i][j] += dp[i - 1][j - a[i]];
				dp[i][j] %= mod;
				
			}
//			cout << i << " " << j << " :" << dp[i][j] << "\n";
		}
	}
	for(int i = 3; i <= n; i ++) {
		for(int j = a[i] + 1; j <= sum; j ++) {
			ans += dp[i - 1][j];
			ans %= mod;
		}
	}
	cout << ans;
	return 0;
}

