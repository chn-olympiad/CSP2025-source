#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,ans,now;
int a[5010];
int flag=0;
int fac[5010],inv[5010];
int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
		{
			res=res*a%mod;
		} 
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
void dfs(int rt,int x,int sum)
{
	if(sum>a[x])
	{
		now++;
		if(rt==x-1)return;
	}
	for(int i=rt+1;i<x;i++)
	{
		dfs(i,x,sum+a[i]);
	}
	return;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int maxx=-1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	if(maxx==1)
	{
		fac[0]=inv[0]=1;
		for(int i=1;i<=n;i++)
		{
			fac[i]=fac[i-1]*i%mod;
			inv[i]=inv[i-1]*qpow(i,mod-2)%mod;
		}
		for(int i=3;i<=n;i++)
		{
			ans+=fac[n]*inv[i]%mod*inv[n-i]%mod;
		}
		cout<<ans<<endl;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			dfs(0,i,0);
		}
		cout<<now<<endl;
	}
	return 0;
}
