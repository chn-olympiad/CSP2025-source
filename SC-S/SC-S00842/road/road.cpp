//Just Sayori!!!
//csp 2025 rp++
//祝学长全部进 WC！
//祝大家全员一等奖！
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
#include <queue>
#define ll long long
#define rnt register int
#define gr getchar
#define pr putchar
#define N 2000005
#define M 1000000007
using namespace std;
inline ll read()
{
	ll x=0,f=1;
	char ch=gr();
	while (ch<'0' || ch>'9') ch=='-'?f=-1,ch=gr():ch=gr();
	while (ch>='0' && ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=gr();
	return x*f;
}
void write(ll x)
{
	int top=0,stack[39];
	if (x<0) pr('-'),x=-x;
	do stack[++top]=x%10,x/=10;
	while (x);
	while (top) pr(stack[top--]^48);
}
struct node
{
	int u,v,w;
	bool operator <(node o)
	{
		return w<o.w;
	}
}s[N];
int n,m,k,cnt;
ll ans;
bool f;
int c[N],fa[N];
int a[11][10005];
int find(int a)
{
	return fa[a]==a?a:fa[a]=find(fa[a]);
}
void work()
{
	ans=0x3f3f3f3f3f3f3f3f;
	for (rnt sk=0;sk<(1<<k);sk++)
	{
		cnt=m;
		ll sum=0;
		for (rnt i=1;i<=k;i++)
			if (sk>>(i-1)&1)
			{
				sum+=c[i];
				for (rnt j=1;j<=n;j++) s[++cnt].u=n+i,s[cnt].v=j,s[cnt].w=a[i][j];
			}
		sort(s+1,s+cnt+1);
		for (rnt i=1;i<=n+k;i++) fa[i]=i;
		for (rnt i=1;i<=cnt;i++)
		{
			int fu=find(s[i].u),fv=find(s[i].v);
			if (fu==fv) continue;
			sum+=s[i].w,fa[fv]=fu;
		}
		ans=min(ans,sum);
	}
	write(ans),pr(10);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read(),cnt=m;
	for (rnt i=1;i<=m;i++) s[i].u=read(),s[i].v=read(),s[i].w=read();
	for (rnt i=1;i<=k;i++)
	{
		c[i]=read();
		if (c[i]>0) f=1;
		for (rnt j=1;j<=n;j++) a[i][j]=read();
	}
	if (f) work();
	else
	{
		for (rnt i=1;i<=n+k;i++) fa[i]=i;
		for (rnt i=1;i<=k;i++)
			for (rnt j=1;j<=n;j++)
				s[++cnt].u=n+i,s[cnt].v=j,s[cnt].w=a[i][j];
		sort(s+1,s+cnt+1);
		for (rnt i=1;i<=cnt;i++)
		{
			int fu=find(s[i].u),fv=find(s[i].v);
			if (fu==fv) continue;
			ans+=s[i].w,fa[fv]=fu;
		}
		write(ans);
	}
	return 0;
}