#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+10,mod=998244353;
int n;
int dp[2][N][N<<1];
int f;
int a[N];
int mx;
ll ans=1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]),ans=(ans*2)%mod;
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=mx;j++)
			for(int k=0;k<=mx*2;k++)
				dp[f^1][j][k]=dp[f][j][k];
		for(int j=0;j<=mx;j++)
			for(int k=0;k+a[i]<=mx*2;k++)
				dp[f^1][max(j,a[i])][k+a[i]]=(dp[f^1][max(j,a[i])][k+a[i]]+dp[f][j][k])%mod;
		f^=1;
	}
	for(int i=0;i<=mx;i++)
		for(int j=0;j<=i*2;j++)
			ans=(ans-dp[f][i][j]+mod)%mod;
	cout<<ans;
	return 0;
}
