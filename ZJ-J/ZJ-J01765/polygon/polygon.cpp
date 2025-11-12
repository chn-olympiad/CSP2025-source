#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e3+5,mod=998244353;
ll n,a[N],ans,dp[N][N];
bool f=1;
void Dfs(ll i,ll mx,ll cnt)
{
	if(i>n)
	{
		if(cnt>mx*2)
			ans++;
		if(ans==mod)
			ans=0;
		return ;
	}
	Dfs(i+1,mx,cnt);
	Dfs(i+1,max(mx,a[i]),cnt+a[i]);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			f=0;
	}
	sort(a+1,a+n+1);
	if(n<=30)
		Dfs(1,0,0);
	else if(f)
	{
		ll k=2,j=n*(n-1);
		for(ll i=3;i<=n;i++)
		{
			k=k*i%mod;
			j=j*(n-i+1)%mod;
			ans=(ans+j/k)%mod;
		}
	}
//	else
//	{
//		
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=0;j<=2*a[n]-1;j++)
//			{
//				dp[i][j]=max(dp[i-1][j],dp[0][j-a[i]]);
//				dp[i][j]%=mod;
//			}
//		}
//		for(int i=1;i<=n;i++)
//			ans=(ans+dp[i][a[i]*2-1])%mod;
//	}
	cout<<ans;
	return 0;
}
