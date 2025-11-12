#include <bits/stdc++.h> 
using namespace std;
const int MAXN=1e4+20;
int n,k,m,fa[MAXN],c[12];
long long ans=1e18;
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
struct edge{
	int u,v,w;
	friend bool operator <(edge x,edge y)
	{
		return x.w<y.w;
	}
}e[MAXN*200],p[12][MAXN],t[MAXN*20],q[MAXN*20];
int read()
{
	int x=0;char ch=getchar() ;
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	}
	sort(e+1,e+m+1);
	e[m+1].w=INT_MAX;
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
		{
			p[i][j]={i+n,j,read()};
		}
		sort(p[i]+1,p[i]+n+1);
		p[i][n+1].w=INT_MAX;
	}
	for(int s=0;s<(1<<k);s++)
	{
		int cnt=0,qw=n-1;long long sum=0;
		t[1].w=INT_MAX;
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=k;i++)
		{
			if(s>>(i-1)&1)
			{
				sum+=c[i];
				int tr=0;++qw;
				for(int w=1,j=1;w<=cnt || j<=n;)
				{
					if(t[w].w<p[i][j].w) q[++tr]=t[w],++w;
					else q[++tr]=p[i][j],++j;
				}
				for(int j=1;j<=tr;j++) t[j]=q[j];
				cnt=tr;
				t[cnt+1].w=INT_MAX;
			}
		}
		int tot=0;
		for(int i=1,j=1;i<=m || j<=cnt;)
		{
			edge x;
			if(e[i].w<t[j].w) x=e[i],++i;
			else x=t[j],++j;
			int u=find(x.u),v=find(x.v);
			if(u!=v)
			{
				++tot,sum+=x.w;
				fa[u]=v;
				if(tot==qw) break;
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans;
}