#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int a[5010];
long long dp[510][50010];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	sort(a + 1,a + 1 + n);
	
	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;
		
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 50000; j++)
		{
			dp[i][j] = dp[i - 1][j];
			dp[i][j] %= MOD;
			
			if (j >= a[i])
			{
				dp[i][j] += dp[i - 1][j - a[i]];
				dp[i][j] %= MOD;
			}
		}
	}
			
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = a[i] + 1; j <= 50000; j++)
		{
			ans += dp[i - 1][j];
			ans %= MOD;
		}
	}
	
	cout << ans;
	
	return 0;
}