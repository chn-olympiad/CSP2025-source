#include<bits/stdc++.h>
#define ll int
#define fi(l) freopen(l".in","r",stdin)
#define fo(l) freopen(l".out","w",stdout)
using namespace std;
inline ll read()
{
	ll v=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
inline void out(ll x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	if(x<10)putchar(x+'0');
	else
	{
		out(x/10);
		putchar(x%10+'0');
	}
}
inline ll ksm(ll a,ll b,ll p)
{
	ll ans=1;
	for(;b;b>>=1,a=a*a%p)
	{
		if(b&1)ans=ans*a%p;
	}
	return ans;
}
ll ans,a[100020][5],fp[100020],xyz[100020];
inline void dfs(ll nw,ll cn1,ll cn2,ll cn3,ll n)
{
	if(nw==n+1)
	{
		ll mid=(n>>1),cnt=0;
		if(cn1>mid||cn2>mid||cn3>mid)return;
		for(ll i=1;i<=n;i++)
		{
			cnt+=a[i][fp[i]];
		}
		ans=max(ans,cnt);
		return;
	}
	fp[nw]=1;
	dfs(nw+1,cn1+1,cn2,cn3,n);
	fp[nw]=2;
	dfs(nw+1,cn1,cn2+1,cn3,n);
	fp[nw]=3;
	dfs(nw+1,cn1,cn2,cn3+1,n);
}
int main()
{
	fi("club");
	fo("club");
	ll t=read();
	while(t--)
	{
		ll n=read();
		bool f=true,f1=true;;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=3;j++)
			{
				a[i][j]=read();
			}
			if(a[i][1]+a[i][2]+a[i][3]!=a[i][1])f=false;
			if(a[i][1]+a[i][2]+a[i][3]!=0)f1=false;
		}
		if(f1)
		{
			out(0);
			cout<<'\n';
			continue;
		}
		if(f)
		{
			for(ll i=1;i<=n;i++)
			{
				xyz[i]=a[i][1];
			}
			sort(xyz+1,xyz+n+1);
			ll ans=0;
			for(ll i=n;i>(n>>1);i--)
			{
				ans+=xyz[i];
			}
			out(ans);
			cout<<'\n';
			continue;
		}
		ans=0;
		dfs(0,0,0,0,n);
		out(ans);
		cout<<'\n';
	}
	return 0;
}
