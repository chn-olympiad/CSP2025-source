#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10009
#define M 10000009
ll n,m,k,pos,ans,a[N],fa[N];
struct edge{ll u,v,w;}dis[M];
ll read()
{
	char ch=getchar();ll sum=0;
	while(ch>'9'||ch<'0') ch=getchar();
	while('0'<=ch&&ch<='9') sum=(sum<<3)+(sum<<1)+ch-'0',ch=getchar();
	return sum;
}
void write(ll tmp)
{
	if(tmp>9) write(tmp/10);
	putchar(tmp%10+'0');
}
bool cmp(edge xx,edge yy)
{
	return xx.w<yy.w;
}
int check(int x)
{
	if(fa[x]==x) return x;
	else
	{
		fa[x]=check(fa[x]);
		return fa[x];
	}
}
void merge(int x,int y)
{
	fa[check(fa[x])]=fa[y];
}
void kruskal()
{
	sort(dis+1,dis+m+1,cmp);
	ll cnt=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		if(cnt>=n) break;
		int u=dis[i].u,v=dis[i].v,w=dis[i].w;
		if(check(u)==check(v)) continue;
		else
		{
			merge(u,v);
			cnt++,ans+=w;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		ll u,v,w;
		u=read(),v=read(),w=read();
		dis[i]={u,v,w};
	}
	for(int i=1;i<=k;i++)
	{
		pos=read();
		ans+=pos;
		for(int j=1;j<=n;j++) a[j]=read();
		for(int j=1;j<=n;j++)
		{
			if(a[j]==0)
			{
				for(int k=1;k<=n;k++) dis[++m]={j,k,a[k]};
				break;
			}
		}
	}
	//for(int i=1;i<=m;i++) printf("%lld %lld %lld\n",dis[i].u,dis[i].v,dis[i].w);
	kruskal();
	write(ans);
	return 0;
}