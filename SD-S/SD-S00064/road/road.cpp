#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e4+10,INF=1e18+10;
int n,m,k;
vector<pair<int,int>>g[N];
int a[11][N];
int t[11];
int szz[N];
int dis[N],vis[N];
int z[N];
int c[N];
int ans=INF;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q; 
void prim()
{
	while(!q.empty())
	{
		q.pop();
	}
	int res=0;
	for(int i=1;i<=n+k;i++)
	{
		z[i]=szz[i];
		vis[i]=0;
		dis[i]=INF;
	}
	int cnt=0;
	for(int i=1;i<=k;i++)
	{
		if(t[i])
		{
			res+=c[i];
			for(int j=1;j<=n;j++)
			{
				g[j][z[j]++]={n+i,a[i][j]};
				g[n+i][z[n+i]++]={j,a[i][j]};
			}
			cnt++;
		}
	}
	q.push({0,1});
	dis[1]=0;
	while(!q.empty())
	{
		auto o=q.top();
		q.pop();
		if(vis[o.second])
		{
			continue;
		}
		vis[o.second]=1;
		cnt++;
		res+=o.first;
		for(int j=0;j<z[o.second];j++)
		{
			int e=g[o.second][j].first,vv=g[o.second][j].second;
			if(!vis[e]&&dis[e]>vv)
			{
				dis[e]=vv;
				q.push({dis[e],e});
			}
		}
	}
	ans=min(ans,res);
	return;
}

void dfs(int K)
{
	if(K>k)
	{
		prim();
		return;
	}
	dfs(K+1);
	t[K]=1;
	dfs(K+1);
	t[K]=0;
	return;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=n;i++)
	{
		szz[i]=g[i].size();
		for(int j=szz[i];j<=szz[i]+25;j++)
		{
			g[i].push_back({0,0});
		}
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++)
	{
		szz[i+n]=0;
		for(int j=1;j<=n+2;j++)
		{
			g[i+n].push_back({0,0});
		}
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
} 
