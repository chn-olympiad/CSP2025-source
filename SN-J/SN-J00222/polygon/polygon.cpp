//tyy tyz 8z03
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n , a[5005] , dp[5005] , ans;
signed main ()
{
	freopen ("polygon.in" , "r" , stdin);
	freopen ("polygon.out" , "w" , stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	cin >> n;
	for (int i = 1;i <= n;i ++) cin >> a[i];
	sort (a + 1 , a + n + 1);
	dp[0] = 1;
	for (int i = 1;i <= n;i ++)
	{
		for (int j = a[i] + 1;j <= 5001;j ++) (ans += dp[j]) %= mod;
		(dp[5001] += dp[5001]) %= mod;
		for (int j = 5001 - a[i];j <= 5000;j ++) (dp[5001] += dp[j]) %= mod;
		for (int j = 5000;j >= a[i];j --) (dp[j] += dp[j - a[i]]) %= mod;
	}
	cout << ans;
	return 0;
}
