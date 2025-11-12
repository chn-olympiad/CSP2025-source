#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5010,mod=998244353;
ll n,maxx,ans,a[N],dp[N][N],pw[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	maxx++;
	sort(a+1,a+n+1);
	pw[0]=1;
	for(int i=1;i<=n;i++)
		pw[i]=pw[i-1]*2%mod;
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<a[i];j++)
			dp[i][j]=(dp[i-1][j]+pw[i-1])%mod;
		for(int j=a[i];j<=maxx;j++)
			dp[i][j]=(dp[i-1][j]+dp[i-1][j-a[i]])%mod;
	}
	for(int i=3;i<=n;i++)
		ans=(ans+dp[i-1][a[i]+1])%mod;
	cout<<ans<<"\n";
}
