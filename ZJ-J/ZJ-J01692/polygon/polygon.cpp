#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
vector<vector<ll> >dp;
ll n,i,a[6000],j,sum[6000],ans,rp;
void RP()
{while(rp<=1e5)rp++;}
void print()
{cout<<"RP++!";}
inline ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}while(c<='9'&&c>='0')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f*x;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+1+n);
	for(i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
	dp.resize(n+1);
	for(i=0;i<=n;++i)dp[i].resize(sum[n]+20);
	rp++;
	if(n*sum[n]<=1e8)
	{
		dp[0][0]=1;
		for(i=1;i<=n;++i)
		{
			for(j=sum[i];j>=0;--j)
			{
				dp[i][j]=dp[i-1][j];
				if(j>=a[i])dp[i][j]+=dp[i-1][j-a[i]];
				dp[i][j]%=mod;
			}
		}
		for(i=1;i<=n;i++)
			for(j=sum[i];j>=0;--j)
				dp[i][j]=(dp[i][j]+dp[i][j+1])%mod;
		for(i=3;i<=n;++i)
			(ans+=dp[i-1][a[i]+1])%=mod;
		cout<<ans;
		return 0;
	}
	rp=0;
	dp[0][0]=1;
	for(i=1;i<=n;++i)
	{
		for(j=sum[i];j>=0;--j)
		{
			dp[i][j]=dp[i-1][j];
			if(j>=a[i])dp[i][j]+=dp[i-1][j-a[i]];
			dp[i][j]%=mod;
			rp++;
			if(rp%10000==0)break;
		}
	}
	for(i=1;i<=n;++i)
		for(j=sum[i];j>=0;--j)
			dp[i][j]=(dp[i][j]+dp[i][j+1])%mod;
	for(i=3;i<=n;++i)
		(ans+=dp[i-1][a[i]+1])%=mod;
	cout<<ans;
	return 0;
}
