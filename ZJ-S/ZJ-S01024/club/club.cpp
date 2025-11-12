#include<bits/stdc++.h>
using namespace std;
void fre()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
}
long long t;
long long n;
long long a[100005][4];
long long tmp[100005];
long long dp[205][205][205];
long long dp1[2][50005];
long long ans;
void work()
{
	bool flg1 = false;
	bool flg2 = false;
	memset(dp,0,sizeof(dp));
	ans = 0;
	cin>>n;
	for(long long i = 1; i<=n; i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]>0 || a[i][3]>0)
		{
			flg1 = true;
		}
		if(a[i][3]>0)
		{
			flg2 = true;
		}
	}
	if(!flg1)
	{
		for(long long i = 1; i<=n; i++)
		{
			tmp[i] = -a[i][1];
		}
		sort(tmp+1,tmp+n+1);
		for(long long i = 1; i<=n/2; i++)
		{
			ans-=tmp[i];
		}
		cout<<ans<<'\n';
		return ;
	}
	if(!flg2)
	{
		long long now = 1;
		long long pre = 0;
		for(long long i = 1; i<=n; i++)
		{
			now^=1;
			pre^=1;
			for(long long j = 0; j<=min(i,n/2); j++)
			{
				long long k = i-j;
				if(k>n/2)
				{
					continue;
				}
				if(j>0)
				{
					dp1[now][j] = max(dp1[now][j],dp1[pre][j-1]+a[i][1]);
				}
				if(k>0)
				{
					dp1[now][j] = max(dp1[now][j],dp1[pre][j]+a[i][2]);
				}
				ans = max(ans,dp1[now][j]);
			}
		}
		cout<<ans<<'\n';
		return ;
	}
	for(long long i = 1; i<=n; i++)
	{
		for(long long j = 0; j<=min(i,n/2); j++)
		{
			for(long long k = 0; k<=min(i-j,n/2); k++)
			{
				if(j>0)
				{
					dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
				}
				if(k>0)
				{
					dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
				}
				if(n-j-k>0)
				{
					dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
				}
				ans = max(ans,dp[i][j][k]);
			}
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	fre();
	cin>>t;
	while(t--)
	{
		work();
	}
	return 0;
}