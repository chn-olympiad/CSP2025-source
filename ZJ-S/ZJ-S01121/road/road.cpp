#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e5+5;
priority_queue<vector<pii>,greater<pii>,pii> q;
void dijk()
{
	dis[1][0]=0;
	q.push({1,0});
	while(!q.empty())
	{
		
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		V[v].push_back({v,w});d[u][v]=w;
		V[u].push_back({u,w});d[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{	
		cin>>f;
		for(int j=1;j<=n;j++)
		{
			cin>>wi;
			if(d[i][j]==1e18)
			{
				V[i].push_back({j,wi+f});
				V[j].push_back({i,wi+f});
				d[i][j]=wi+f;d[j][i]=wi+f;
			}
			else
			{
				if(d[i][j]<wi+f) continue;
				else d[i][j]=wi+f,d[j][i]+=wi+f;
			}
		}
	}
	dijk();
	return 0;
}