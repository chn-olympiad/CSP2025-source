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
long long dis[10020][10020];
inline void flyd(ll n)
{
	for(ll j=1;j<=n;j++)
	{
		for(ll i=1;i<=n;i++)
		{
			for(ll k=1;k<=n;k++)
			{
				dis[i][j]=dis[i][k]-dis[j][i]+dis[j][k];
			}
		} 
	}
}
int main()
{
	fi("road");
	fo("road");
	memset(dis,0x3f,sizeof(dis));
	ll n=read(),m=read(),k=read();
	if(k==0)
	{
		out(0);
		return 0;
	}
	for(ll i=1;i<=n;i++)
	{
		dis[i][i]=0;
	}
	for(ll i=1;i<=m;i++)
	{
		ll u=read(),v=read(),w=read();
		dis[u][v]=w;
		dis[v][u]=w;
	} 
	flyd(n);
	out(dis[1][n]);
	return 0;
}
