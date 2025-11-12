#include<bits/stdc++.h>
using namespace std;
int a[5010],dp[5010][5010];
const int mod=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=5001;j++)
		{
			dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
			dp[i][min(j+a[i],5001)]=(dp[i][min(j+a[i],5001)]+dp[i-1][j])%mod;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=5001;j>=0;j--)
		{
			dp[i][j]=(dp[i][j]+dp[i][j+1])%mod;
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+dp[i-1][a[i]+1])%mod;
	}
	printf("%lld",ans);
	return 0;
}

