#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
long long int dp[5010][5010];
long long int mod=998244353;
long long ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	dp[1][0]=2;
	for(int i=1;i<=a[1];i++)
		dp[1][i]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=5000;j++)
		{
			dp[i][j]=dp[i-1][max(0,j-a[i])]+dp[i-1][j];
			dp[i][j]%=mod;
		}
	}
	for(int i=3;i<=n;i++)
		ans=(ans+dp[i-1][a[i]+1])%mod;
	printf("%lld",ans);
	return 0;
}
