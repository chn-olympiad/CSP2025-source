#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll n;
ll a[5010];
ll ans=0;
ll sum[5010];
const ll mod=998244353;

void dfs(ll k,ll maxn,ll tot,ll bian)
{
	if((bian>=3)&&(tot>(maxn*2)))
	{
		ans=(ans+1)%mod;
	}
	for(ll i=k;i>=1;--i)
	{
		if((sum[i]+tot)<=(maxn*2)) return;
		dfs(i-1,maxn,tot+a[i],bian+1);
	}
}

int main(void)
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;++i)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(ll i=n;i>=3;--i)
	{
		dfs(i-1,a[i],a[i],1);
	}
	cout<<(ans%mod);
	return 0;
}