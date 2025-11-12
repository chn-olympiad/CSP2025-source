#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+5,maxm=2e6+5;
ll read()
{
	ll ans=0;
	char c=getchar();
	while(c>'9'||c<'0')
		c=getchar();
	while(c>='0'&&c<='9')
	{
		ans=(ans<<1)+(ans<<3)+c-48;
		c=getchar();
	}
	return ans;
}
int n,m,k,fa[maxn],e2cnt;
ll c[11][maxn];
struct edge{
	ll u,v,w;
	bool operator<(const edge &b)const{
		return w<b.w;
	}
}e1[maxm],e2[maxm];
int find(int x)
{
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	fa[find(y)]=find(x);
}
int getDig(int x,int p)
{
	return (x>>p)&1;
}
void kruskal1()
{
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		ll u=e1[i].u,v=e1[i].v,w=e1[i].w;
		if(find(u)!=find(v))
		{
			e2[++e2cnt]=e1[i];
			merge(u,v);
		}
	}
}
ll kruskal2(int s)
{
	ll ans=0;
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	for(int i=1;i<=e2cnt;i++)
	{
		ll u=e2[i].u,v=e2[i].v,w=e2[i].w;
		if(u>n)
		{
			if(!getDig(s,u-n-1))
				continue;
		}
		if(find(u)!=find(v))
		{
			merge(u,v);
			ans+=w;
		}
	}
	return ans;
}
void solveA()
{
	printf("%lld\n",kruskal2((1<<k)-1));
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		e1[i].u=read(),e1[i].v=read(),e1[i].w=read();
	}
	e2cnt=0;
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			c[i][j]=read();
			if(j!=0)
				e2[++e2cnt]={n+i,j,c[i][j]};
		}
	}
	ll ans=1e18,tmp=0;
	sort(e1+1,e1+m+1);
	kruskal1();
	sort(e2+1,e2+e2cnt+1);
	for(int s=0;s<(1<<k);s++)
	{
		tmp=0;
		for(int i=1;i<=k;i++)
		{
			if(getDig(s,i-1))
			{
				tmp+=c[i][0];
			}
		}
		ans=min(ans,kruskal2(s)+tmp);
	}
	printf("%lld\n",ans);
	return 0;
}
