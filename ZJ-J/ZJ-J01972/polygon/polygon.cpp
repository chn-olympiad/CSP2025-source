#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod=998244353;
ll n;
ll ans=0;
ll a[5010],C[5010],f[5010];
bool cmp(ll A,ll B)
{
	return A>B;
}
//ll ksm(ll x,ll y)
//{
//	ll z=0;
//	while(y)
//	{
//		if(y&1)
//		{
//			z=z*x%mod;
//		}
//		x=x*x%mod;
//		y>>=1;
//	}
//	return z;
//}
//void init()
//{
//	f[1]=1;
//	for(ll i=2;i<=n;i++)
//	{
//		f[i]=f[i-1]*i%mod;
//	}
//	for(ll i=1;i<=n;i++)
//	{
//		C[i]=1;
//		for(ll j=1;j<=i;j++)
//		{
//			C[i]=(C[i]+f[i]*ksm(f[j],mod-1)%mod*ksm(f[i-j],mod-1)%mod)%mod;
//		}
//		cout<<C[i]<<"\n";
//	}
//}
void dfs(ll k,ll cnt,ll s,ll ma)
{
	if(k==n+1)
	{
		if(cnt>2&&s>ma*2)
		{
			ans=(ans+1)%mod;
		}
		return;
	}
	if(cnt>2&&s>ma*2)
	{
		ans=(ans+1)%mod;
	}
	for(ll i=k;i<=n;i++)
	{
		dfs(i+1,cnt+1,s+a[i],max(ma,a[i]));
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
//	init();
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(n<=20)
	{
		dfs(1,0,0,0);
		cout<<ans;
	}
	return 0;
}
