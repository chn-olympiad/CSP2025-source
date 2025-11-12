#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,head[4000005],tot=0,ans=0,mx=0,cnt=0;
int w[45],dis[15][1000005],vis[4000005],dp[4000005];
priority_queue<pair<int,int>>q;
struct node
{
	int v,w,nxt;
}eg[4000005];
void add(int u,int v,int w)
{
	eg[++tot]={v,w,head[u]};
	head[u]=tot;
}
void dfs(int sta)
{
	for(int i=1;i<=n;i++) dp[i]=INT_MAX;
	q.push({0,sta});
	dp[sta]=0;
	while(!q.empty())
	{
		int now=q.top().second;
		q.pop();
		if(vis[now]) continue;
		vis[now]=1;
		for(int i=head[now];i;i=eg[i].nxt)
		{
			int v=eg[i].v;
			if(eg[i].w+dp[now]<=dp[v])
			{
				if(eg[i].w+dp[now]<dp[v]&&dp[v]!=INT_MAX) cnt=cnt-dp[v]+eg[i].w+dp[now];
				else cnt+=eg[i].w;
				dp[v]=dp[now]+eg[i].w;
				cnt=max(cnt,dp[v]);
				q.push({-dp[v],v});
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
		int u,v,W;
		cin>>u>>v>>W;
		add(u,v,W);
		add(v,u,W);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>w[i];
		if(w[i]==0)
		{
			for(int j=1,W;j<=n;j++)
			{
				cin>>W;
				add(n+i,j,W);
				add(j,n+i,W);
			}
		}
		else
		{			
			for(int j=1;j<=n;j++)
				cin>>dis[i][j];
		}
	}
	dfs(1);
	cout<<cnt;
	return 0;
}