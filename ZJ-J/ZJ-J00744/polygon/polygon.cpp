#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7,N=5005;
int n,mx,ans,a[N],sum[N],fac[N],inv[N];
void dfs(int x,int mx,int sum,int gs)
{
	if(x==n+1)
	{
		if(gs>=3&&sum>mx*2)
			ans=(ans+1)%mod;
		return;
	}
	dfs(x+1,mx,sum,gs);
	dfs(x+1,max(mx,a[x]),sum+a[x],gs+1);
}
int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
void init(int n)
{
	fac[0]=1;
	inv[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2)%mod;
	for(int i=n-1;i>=1;i--)
		inv[i]=inv[i+1]*(i+1)%mod;
}
int C(int n,int k)
{
	if(k>n)
		return 0;
	return fac[n]*inv[k]%mod*inv[n-k]%mod;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+1+n);
	if(n<=20)
	{
		dfs(1,0,0,0);
		cout<<ans;
	}
	else
	{
		ans=0;
		init(N-5);
		for(int i=3;i<=n;i++)
			(ans+=C(n,i))%=mod;
		cout<<ans;
	}
}