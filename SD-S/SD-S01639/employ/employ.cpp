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
const ll mod=998244353;
ll c[520];
int main()
{
	fi("employ");
	fo("employ");
	ll n=read(),m=read();
	ll ans=1;
	for(ll i=1;i<=n;i++)
	{
		ans=((long long)ans*i)%mod;
	}
	out(ans);
	return 0;
}
