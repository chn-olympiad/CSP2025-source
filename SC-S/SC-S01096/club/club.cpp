#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int T,n;
int a[3];
int dp[205][205][205];
void ock()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
}
void solve()
{
	
	scanf("%lld",&n);
	for(int j=0;j<=n/2;j++)
	{
		for(int k=0;k<=n/2;k++)
		{
			for(int l=0;l<=n/2;l++)
			{
				dp[j][k][l]=0;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			scanf("%lld",&a[j]);
		}
		for(int j=0;j<=n/2;j++)
		{
			for(int k=0;k<=n/2;k++)
			{
				int l=i-j-k;
				if(l>=0&&l<=n/2)
				{
					if(j>0)
					{
						dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+a[1]);
					}
					if(k>0)
					{
						dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+a[2]);
					}
					if(l>0)
					{
						dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+a[3]);
					}
					ans=max(ans,dp[j][k][l]);
				}
			}
		}
	}
	printf("%lld\n",ans);
	
}
signed main()
{
	ock();
	scanf("%lld",&T);
	while(T--)
	{
		solve();
	}
	return 0;
}
/*


*/