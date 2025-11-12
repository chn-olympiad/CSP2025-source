#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
	ll u,v,w;
};
node e[1000005];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
ll n,m,k,cnt=0;
ll f[10005],sz[10005],c[15];
ll a[15][10005];
int find(int x)
{
	if(f[x]==x)
	{
		return x; 
	}
	return f[x]=find(f[x]);
}
void merge(int x,int y)
{
	f[find(x)]=find(y);
}
ll kruskal()
{
	sort(e+1,e+1+m,cmp);
	ll ans=0;
	int tot=0;
	for(int i=1;i<=m;i++)
	{
		if(find(e[i].u)!=find(e[i].v))
		{
			merge(e[i].u,e[i].v);
			ans+=e[i].w;
			tot++;
		}
		if(tot==n-1)
		{
			return ans;
		}
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		ll u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		cnt++;
		e[i].u=u;
		e[i].v=v;
		e[i].w=w;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	if(k==0)
	{
		printf("%lld",kruskal());
	}
	return 0;
}
