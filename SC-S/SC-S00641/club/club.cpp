#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005],b[100005],c[100005],dp[205][205][205];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		bool flag1=0,flag2=0;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(c[i]!=0)
			{
				flag2=1;
			}
			if(b[i]!=0)
			{
				flag1=1;
			}
		}
		if(flag1==0&&flag2==0)
		{
			sort(a+1,a+n+1);
			long long ans=0;
			for(long long i=n;i>=n/2+1;i--)
			{
				ans+=a[i];
			}
			cout<<ans<<endl;
			continue;
		}
		memset(dp,0,sizeof(dp));
		for(long long i=0;i<=n/2;i++)
		{
			for(long long j=0;j<=n/2;j++)
			{
				for(long long k=0;k<=n/2;k++)
				{
					if(i+j+k>n) break;
					if(i>=1)
					{
						dp[i][j][k]=max(dp[i-1][j][k]+a[i+j+k],dp[i][j][k]);
					}
					if(j>=1)
					{
						dp[i][j][k]=max(dp[i][j-1][k]+b[i+j+k],dp[i][j][k]);
					}
					if(k>=1)
					{
						dp[i][j][k]=max(dp[i][j][k-1]+c[i+j+k],dp[i][j][k]);
					}
				}
			}
		}
		long long ans=0;
		for(long long i=0;i<=n/2;i++)
		{
			for(long long j=0;j<=n/2;j++)
			{
				long long k=n-i-j;
				ans=max(ans,dp[i][j][k]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}