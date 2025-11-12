#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int a[5010];
int dp[5010][5010];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%lld",&n);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		dp[i][a[i]]=1ll;
		for(int j=sum;j>=a[i];j--)
		{
			dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%mod;
		}
		for(int j=sum;j>=0;j--)
		{
			dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=2*a[i]+1;j<=sum;j++)
		{
			ans=(ans+dp[i][j])%mod;
		}
	}
	printf("%lld",ans);
	return 0;
}