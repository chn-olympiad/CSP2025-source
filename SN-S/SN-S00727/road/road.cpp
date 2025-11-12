//SN-S00727  menkeming xi'anfulunzhongxue
#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,m,k,c[10010],a[15][10010],fa[10010],tot;
vector<pair<int,pair<int,int> > >G;
int find(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	tot=n;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		G.push_back({w,{u,v}});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(k==0)
	{
		int ans=0;
		sort(G.begin(),G.end());
		for(int i=0;i<m;i++)
		{
			int u=G[i].second.first,v=G[i].second.second,w=G[i].first;
			if(find(u)!=find(v))
			{
				fa[find(u)]=find(v);
				ans+=w;
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
