#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int n,m,k,fa[maxn],u,v,w,ls[maxn],c,ans;
inline int find(int x)
{
	if(fa[x]==x)return x;else return fa[x]=find(fa[x]);
}
struct edge
{
	int u,v,w;
};
inline bool cmp(edge xx,edge yy)
{
	return xx.w<yy.w;
}
vector<edge>ed;
void Kruskal()
{
	int cnt=0,j=0;
	while(cnt<n-1&&j<ed.size())
	{
		if(find(ed[j].u)!=find(ed[j].v))
		{
			cnt++;
			fa[find(ed[j].u)]=fa[find(ed[j].v)];
			ans+=ed[j].w;
		}
		j++;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		ed.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++)
	{
		int mk;
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			cin>>ls[j];
			if(ls[j]==0)mk=j;
		}
		for(int j=1;j<=n;j++)
		{
			if(j!=mk)ed.push_back({mk,j,ls[j]});
		}
	}
	sort(ed.begin(),ed.end(),cmp);
	Kruskal();
	cout<<ans;
	return 0;
}