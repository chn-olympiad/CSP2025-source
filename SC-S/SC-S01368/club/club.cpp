#include<bits/stdc++.h>
using namespace std;
int t, n;
int dp[205][105][105];
int con[205][3], ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--)
	{
		memset(dp, 0, sizeof dp);
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> con[i][0] >> con[i][1] >> con[i][2];
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= n / 2; j++)
			{
				for (int k = 0; k <= n / 2; k++)
				{
					if (j > 0)
					{
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + con[i][0]);
					}
					if (k > 0)
					{
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + con[i][1]);
					}
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + con[i][2]);
					if (i == n && j <= n / 2 && k <= n / 2 && j + k >= n / 2)
					{
						ans = max(ans, dp[i][j][k]);
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}