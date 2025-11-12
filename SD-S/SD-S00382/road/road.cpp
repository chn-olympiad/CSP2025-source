#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k,a[N];
long long ans;
struct edge
{
	int u,v,w;
	bool operator<(edge x)const
	{
		return w<x.w;
	}
};
vector<edge> E;
int fa[N];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		E.push_back(edge{u,v,w});
	}
	for(int i=1;i<=k;i++)
	{
		int c;scanf("%d",&c);
		int t=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==0)t=i;
		}
		for(int i=1;i<=n;i++)
		{
			if(i==t)continue;
			E.push_back(edge{i,t,a[i]});
		}
	}
	int cnt=0,now=0;
	sort(E.begin(),E.end());
	while(cnt<n-1)
	{
		int u=E[now].u,v=E[now].v,w=E[now].w;
		if(find(u)!=find(v))
		{
			fa[find(v)]=find(u);
			ans+=w;
			cnt++; 
		}
		now++;
	}
	printf("%lld\n",ans);
	return 0;
}

