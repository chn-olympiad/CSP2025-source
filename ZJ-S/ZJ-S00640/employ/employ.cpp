#include<bits/stdc++.h>

using namespace std;

#define ll long long

string s;
ll n,m;
ll sum[510];
ll c[510];
bool tf[510];
ll ans=0;
const ll mod=998244353;

void dfs(ll k)
{
	if(s[k-1]=='0') dfs(k+1);
	if(k==(n+1))
	{
		ans=(ans+1)%mod;
	}
	for(ll i=1;i<=n;++i)
	{
		if(tf[i]==true) return;
		if(sum[k]>c[i]) continue;
		tf[i]=true;
		dfs(k+1);
		tf[i]=false;
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(ll i=1;i<=n;++i)
	{
		cin>>c[i];
	}
	sort(&c[1],&c[n+1]);
	for(ll i=1;i<=n;++i)
	{
		if(s[i-1]=='0')
		{
			sum[i]=sum[i-1]+1;
		}
		else
		{
			sum[i]=sum[i-1];
		}
	}
	if(m==1)
	{
		ans=1;
		ll x=true;
		for(ll i=1;i<=n;++i)
		{
			if(s[i-1]=='0') continue;
			for(ll j=1;j<=n;++j)
			{
				if(c[j]>i)
				{
					x=false;
					ans*=(n-j+1);
					break;
				}
			}
		}
		if(x==true) printf("0");
		else printf("%lld",ans);
	}
	else if(sum[n]==0)
	{
		ans=1;
		for(ll i=n;i>=1;--i)
		{
			bool x=true;
			if(c[1]>=i)
			{
				ans*=i;
				continue;
			}
			for(ll j=i;j>=1;--j)
			{
				if(c[j]>=i)
				{
					x=false;
				}
				if(c[j]<i)
				{
					ans*=(i-j);
				}
			}
			if(x==true)
			{
				printf("0");
				return 0;
			}
		}
	}
	else if(n==m)
	{
		printf("0");
	}
	else
	{
		dfs(1);
		cout<<(ans/2);
	}
	return 0;
}