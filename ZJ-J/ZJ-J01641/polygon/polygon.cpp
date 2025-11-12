#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353, N = 5100;
int n, a[N], ma, ans, sum;
int dp[5100][5010];
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	dp[0][0] = 1;
	for(int i = 1; i <= n; i ++) {
		sum += a[i];
		for(int j = i; j >= 1; j --) {
			
			for(int k = sum; k >= a[i]; k --) {
				if(k >= a[i])
				dp[j][k] += dp[j - 1][k - a[i]],
				dp[j][k] %= mod;
				if(k > a[i] * 2)
				ans += dp[j - 1][k - a[i]],
				ans %= mod;
				
			}
			
		}
	}
//	for(int i = 1; i <= n; i ++) for(int j = 1; j <= sum; j ++) cout << dp[n][i][j] << " \n"[j == sum];
	cout << ans;
	return 0;
}
