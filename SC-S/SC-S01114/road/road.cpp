#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+20,N=1e4+20;
int n,m,k,val[N];
struct Node
{
	int u,v,w;
};
vector<Node> e;
int a[N][11];
vector<vector<pair<int,int>>> G;
int vis[N];
int minn=LONG_LONG_MAX;
void dfs(int st,vector<Node> v,int valh)
{
	if(st>k)
	{
		memset(vis,0,sizeof(vis));
		int sum=valh;
		sort(v.begin(),v.end(),[](Node &x,Node &y){return x.w<y.w;});
		for(auto no:v)
		{
			int u=no.u,v=no.v,w=no.w;
			if(vis[u]==1&&vis[v]==1)
				continue;
			else
			{
				vis[u]=vis[v]=1;
				sum+=w;
			}
		}
		minn=min(minn,sum);
		return;
	}
	dfs(st+1,v,valh);
	for(int i=1;i<=n;i++)
		v.push_back({n+st,i,a[i][st]});
	dfs(st+1,v,valh+val[st]);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	G.resize(n+1);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
		e.push_back({u,v,w});
	}
	sort(e.begin(),e.end(),[](Node& x,Node& y){return x.w<y.w;});
	for(int i=1;i<=k;i++)
	{
		cin>>val[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[j][i];
		}
	}
	dfs(1,e,0);
	cout<<minn;
    return 0;
}