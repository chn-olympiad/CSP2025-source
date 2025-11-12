#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
int dis[100010],n,m,k,s;
priority_queue<PII,vector<PII>,greater<PII>>q; 
int vis[100010];
vector<PII>G[1000010];
void dij()
{
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[s]=0;
	q.push({s,0});
	while(!q.empty())
	{
		PII now=q.top();
		q.pop();
		if(vis[now.first])
		{
			continue;
		}
		vis[now.first]=1;
		for(auto kkk:G[now.first])
		{
			int v=kkk.first,w=kkk.second;
			if(dis[v]>dis[now.first]+w)
			{
				dis[v]=dis[now.first]+w;
				q.push({v,w});
			 } 
		}
	}
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
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	if(k==0)
	{
		int now=0,ans=0x3f3f3f3f;
		for(int i=1;i<=n;i++)
		{
			s=i;
			dij();
			for(int j=1;j<=n;j++)
			{
				now+=dis[j];
			}
			ans=min(ans,now);
		}
		cout<<ans<<endl;
		
	}
	return 0;
}
