#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MX = 1e5 + 10;
ll dp[MX][10];
int a[MX][10];
int cnt[10][10];
int cnt2[10][10];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		memset(cnt,0,sizeof(cnt));
		int i,j;
		int n;
		cin >> n;
		for(i = 1;i <= n;i++)
		{
			for(j = 1;j <= 3;j++)
			{
				cin >> a[i][j];
			}
		}
		for(i = 1;i <= n;i++)
		{
			for(j = 1;j <= 3;j++)
			{
				ll mx = -1,q;
				for(int k = 1;k <= 3;k++)
				{
					if(cnt[j][k] == n / 2)
					{
						continue;
					}
					if(mx < dp[i - 1][k])
					{
						q = k;
					}
					mx = max(mx,dp[i - 1][k]);
				}
				dp[i][j] = a[i][j] + mx;
				for(int k = 1;k <= 3;k++)
				{
					cnt2[j][k] = cnt[q][k];
				}
				cnt2[j][j]++;
			}
			for(int x = 1;x <= 3;x++)
			{
				for(int y = 1;y <= 3;y++)
				{
					cnt[x][y] = cnt2[x][y];
				}
			}
		}
		ll ans = -1;
		for(i = 1;i <= 3;i++)
		{
			ans = max(dp[n][i],ans);
		}
		cout << ans << '\n';
	}
	return 0;
}
