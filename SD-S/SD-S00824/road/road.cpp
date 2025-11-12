#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e4+100;
struct node
{
	int u,v;
	LL w;
}e[N*100],ne[N*10],me[N*10];
int n,m,kt,tot;
int fa[N<<1];
LL ans,c[20],a[20][N];
int gf(int u)
{
	if(fa[u]==u) return u;
	else 
	{
		fa[u]=gf(fa[u]);
		return fa[u];
	}
}
bool com(int u,int v)
{
	int fau=gf(u);
	int fav=gf(v);
	if(fau!=fav) 
	{
		fa[fau]=fav;
		return 1;
	}
	return 0;
}
bool cmp(const node &ft,const node &lt)
{
	return ft.w<lt.w;
}
int readi()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';	
		ch=getchar();
	}
	return x;
}
LL readl()
{
	LL x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';	
		ch=getchar();
	}
	return x;
}
bool ck()
{
	for(int i=1;i<=kt;i++) if(c[i]!=0) return 0;
	return 1;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=readi();m=readi();kt=readi();
	for(int i=1;i<=n+kt;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		e[i].u=readi();e[i].v=readi();
		e[i].w=readl();
	}
	for(int i=1;i<=kt;i++)
	{
		c[i]=readl();
		for(int j=1;j<=n;j++) a[i][j]=readl();
	}
	if(ck())
	{
		tot=m;
		for(int i=1;i<=kt;i++)
		{
			for(int j=1;j<=n;j++) 
			{
				e[++tot].u=n+i;
				e[tot].v=j;
				e[tot].w=a[i][j];
			}
		}
		sort(e+1,e+1+tot,cmp);
		for(int i=1;i<=tot;i++)
		{
			if(com(e[i].u,e[i].v))
			{
				ans+=e[i].w;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(com(e[i].u,e[i].v)) 
		{
			ne[++tot].u=e[i].u;
			ne[tot].v=e[i].v;
			ne[tot].w=e[i].w;
			ans+=e[i].w;
		}
	}
	
	for(int i=0;i<(1<<kt);i++)
	{
		tot=n-1;LL sumn=0;
		for(int j=1;j<=n-1;j++) me[j]=ne[j];
		for(int j=1;j<=n+kt;j++) fa[j]=j;
		for(int j=1;j<=kt;j++)
		{
			if(i&(1<<j-1))
			{
				for(int k=1;k<=n;k++) 
				{
					me[++tot].u=n+j;
					me[tot].v=k;
					me[tot].w=a[j][k];
				}
				sumn+=c[j];
			}
		}
		sort(me+1,me+1+tot,cmp);
		for(int j=1;j<=tot;j++)
		{
			if(com(me[j].u,me[j].v))
			{
				sumn+=me[j].w;
			}
		}
		ans=min(ans,sumn);
	}
	printf("%lld",ans);
	
	return 0;	
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
