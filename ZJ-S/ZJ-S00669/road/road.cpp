#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5,M=1e6+5,K=15;
int n,m,k,cnt,fa[N+K],siz[N+K];
ll c[K],now,ans=1e18;
struct edge
{
	int u,v,t;
	ll w;
}f[M],g[M];
int find(int x)
{
	if (x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
inline bool merge(int x,int y)
{
	x=find(x),y=find(y);
	if (x==y)return 0;
	if (siz[x]<siz[y])swap(x,y);
	fa[y]=x,siz[x]+=siz[y];
	return 1;
}
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++)scanf("%d%d%lld",&f[i].u,&f[i].v,&f[i].w);
	for (int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
	sort(f+1,f+m+1,cmp);
	for (int i=1;i<=m;i++)if (merge(f[i].u,f[i].v))g[++cnt]=f[i];
	for (int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for (int j=1;j<=n;j++)cnt++,scanf("%lld",&g[cnt].w),g[cnt].u=j,g[cnt].v=n+i,g[cnt].t=i;
	}
	sort(g+1,g+cnt+1,cmp);
	for (int i=0;i<(1<<k);i++)
	{
		now=0;
		for (int j=1;j<=n+k;j++)fa[j]=j,siz[j]=1;
		for (int j=1;j<=k;j++)if (i&(1<<(j-1)))now+=c[j];
		for (int j=1;j<=cnt;j++)
		{
			if (g[j].t==0 || (g[j].t>=1 && (i&(1<<(g[j].t-1)))))
			{
				if (merge(g[j].u,g[j].v))now+=g[j].w;
			}
		}
		ans=min(ans,now);
	}
	printf("%lld",ans);
	return 0;
}
