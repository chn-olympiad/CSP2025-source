#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=105;
int n,m;
int a[maxn];
int cnt;
int mp[maxn];
int read()
{
	int n=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')n=n*10+c-'0',c=getchar();
	return n*f;
}

signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;++i)
	{
		a[i]=read();
		++mp[a[i]];	
	}
	for(int i=100;i>=1;--i)
	{
		if(mp[i])++cnt;
		if(a[1]==i)break;
	}
	int ll=(cnt+n-1)/n;
	int rr;
	if(ll%2==1)rr=(cnt-1)%n+1;
	else rr=n+1-((cnt-1)%n+1);
	printf("%lld %lld\n",ll,rr);
	return 0;
}

