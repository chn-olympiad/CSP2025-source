#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int n,m,k,f[N],c[N],a[N][11];
long long ans=0;
struct road
{
	int u,v;
	long long w;
}e[N];
int F(int x)
{
	if(f[x]==x) return x;
	return f[x]=F(f[x]);
}
bool cmp(road x,road y)
{
	return x.w<y.w;
}
void solve()
{
	int t=0;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n;i++)
	  f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int t1=F(e[i].u),t2=F(e[i].v);
		if(t==n) return;
		if(f[t1]!=f[t2])
		{
			t++;
			ans+=e[i].w;
			f[t1]=f[t2]; 
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		  scanf("%d",&a[i][j]);
	}
	for(int j=1;j<=k;j++)
	  for(int x=1;x<=n;x++)
	    for(int y=1;y<=n;y++)
	    if(x!=y)
	    {
	    	long long tem=c[j]+a[j][x]+a[j][y];
	    	e[++m].u=x; e[m].v=y; e[m].w=tem;
		}
	solve();
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
