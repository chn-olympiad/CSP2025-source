#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
using namespace std;
const int MAXN=1e4+5,MAXM=1e6+5;
int n,m,k;
bool vis[MAXN];
int ans=INT_MAX;
struct Edge
{
	int v,w;
};
vector<Edge> edge[MAXM];
//int c[MAXN],a[MAXN][MAXN];
inline void dfs(int u,int co)
{
	if(vis[u])
	{
		for(int i=1;i<=n;i++)
		{
			if(!vis[u]) return; 
		}
		ans=min(ans,co);
		return;
	}
	vis[u]=1;
	for(auto i:edge[u])
	{
		dfs(i.v,co+i.w);
	}
	vis[u]=0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		edge[u].push_back({v,w});
		edge[v].push_back({u,w});
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
/*
我好像有点死了
我上早八
能不能给个省2 
*/ 

