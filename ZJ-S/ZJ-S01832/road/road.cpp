#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5,M=1e6+5;
struct node{
	int x,y,w;
}e[M];
int n,m,k,cnt,fa[N];
int c[N],a[20][N];

bool operator<(node x,node y)
{
	return x.w<y.w;
}

int find(int x)
{
	if(x==fa[x])
		return x;
	return fa[x]=find(fa[x]);
}

int kruskal()
{
	sort(e+1,e+1+m);
	int ans=0;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u=e[i].x,v=e[i].y,w=e[i].w;
		if(find(u)!=find(v))
			fa[find(u)]=find(v),ans+=w;
	}
	return ans;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%lld%lld%lld",&e[i].x,&e[i].y,&e[i].w);
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	}
	cout<<kruskal();
}
