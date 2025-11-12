#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct edge{
	int v,w;
};
const int inf=INT_MAX;
int n,m,k,c[15],vl[15][10005],dis[10005],vis[10005],ans,loc[10005];
vector<vector<edge> > mp;
void add(int u,int v,int w)
{
	edge x;
	x.v=v;x.w=w;
	mp[u].push_back(x);
	return;
}
void dij()
{
	int mx=inf,fd;
	dis[1]=0;
	while(1)
	{
		bool x=0;
		for(int i=1;i<=n;i++)
		{
			if(dis[i]<mx&&vis[i]==0)
			{
				fd=i;
				x=1;
			}
		}
		if(x==0)
			break;
		vis[fd]=1;
		ans+=dis[fd];
		for(int i=0;i<mp[fd].size();i++)
		{
			if(vis[mp[fd][i].v]==1)
				continue;
			if(dis[fd]+mp[fd][i].w<dis[mp[fd][i].v])
			loc[mp[fd][i].v]=mp[fd][i].w;
			dis[mp[fd][i].v]=min(dis[mp[fd][i].v],dis[fd]+mp[fd][i].w);
		}
	}
	for(int i=1;i<=n;i++)
	ans+=loc[i];
	cout<<ans;
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=0;i<=n+3;i++)
	{
		mp.push_back(vector<edge>());
		dis[i]=inf;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>vl[i][j];
		}
	}
	dij();
	return 0;
}
