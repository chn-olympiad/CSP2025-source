#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int n,a[5005],dp[5005][3][5005];

inline void add(int &x,int y)
{
	x = (x+y)%mod;
}

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int mx = a[n];
	dp[0][0][0] = 1;
	int ans = 0;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j <= 2;j++)
		{
			for (int k = 0;k <= mx+1;k++)
			{
				if (dp[i][j][k] == 0) continue;
				if (j == 2 && k > a[i+1]) add(ans,dp[i][j][k]);
				add(dp[i+1][j][k],dp[i][j][k]);
				add(dp[i+1][min(j+1,2)][min(k+a[i+1],mx+1)],dp[i][j][k]);
			}
		}
	}
	cout << ans;
	return 0;
}
