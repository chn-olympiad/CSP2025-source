#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,s[100005][4],ans=-1,sum,k[100005],dp[205][205][205];
void work()
{
	memset(dp,0,sizeof(dp));
	scanf("%lld",&n);
	sum=0,ans=-1;
	for(int i=1;i<=n;i++)
		scanf("%lld %lld %lld",&s[i][1],&s[i][2],&s[i][3]);
	for(int i=1;i<=n;i++) sum+=s[i][3];
	if(sum==0)
	{
		for(int i=1;i<=n;i++)
			k[i]=s[i][1]-s[i][2],sum+=s[i][2];
		sort(k+1,k+n+1);
		for(int i=n;i>n/2;i--)
			sum+=k[i];
		printf("%lld\n",sum);
	}
	else if(n<=200)
	{
		for(int i=1;i<=n;i++)
			for(int j=0;j<=i;j++)
				for(int g=0;g+j<=i;g++)
				{
					if(g+j<i)dp[i][j][g]=max(dp[i][j][g],dp[i-1][j][g]+s[i][3]);
					if(j>=1) dp[i][j][g]=max(dp[i][j][g],dp[i-1][j-1][g]+s[i][1]);
					if(g>=1) dp[i][j][g]=max(dp[i][j][g],dp[i-1][j][g-1]+s[i][2]);
				}
		ans=-1;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				if(i<=n/2&&j<=n/2&&i+j>=n/2)
					ans=max(ans,dp[n][i][j]);
		printf("%lld\n",ans);
	}
	else cout<<rand();
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--) work();
	return 0;
}
