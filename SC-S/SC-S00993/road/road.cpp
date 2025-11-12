#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
struct Edge
{
	int to,w,nxt;
}eg[1005];
struct Node
{
	int id,dis;
	bool operator < (const Node &x)const
	{
		return x.dis>dis;
	}
};
priority_queue<Node> Q;
int N,M,K,tot,head[1005],vist[1005];
int C[15],dis[1005],ans;
int ve[100005];
void addEdge(int u,int v,int w)
{
	eg[++tot]={v,w,head[u]};
	head[u]=tot;
}
void dijkstra(int st)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vist,0,sizeof(vist));
	dis[st]=0;
	Q.push({st,0});
	while(!Q.empty())
	{
		int u=Q.top().id;
		Q.pop();
		if(vist[u])
		{
			continue;
		}
		for(int i=head[u];i;i=eg[i].nxt)
		{
			int v=eg[i].to,w=eg[i].w;
			if(v>N)
			{
				w+=C[v-N];
			}
			if(vist[v])
			{
				continue;
			}
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				Q.push({v,dis[v]});
			}
		}
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>K;
	for(int i=1,u,v,w;i<=M;i++)
	{
		cin>>u>>v>>w;
		addEdge(u,v,w);
		addEdge(v,u,w);
	}
	for(int i=1,x;i<=K;i++)
	{
		cin>>C[i];
		for(int j=1;j<=N;j++)
		{
			cin>>x;
			addEdge(N+i,j,x);
			addEdge(j,N+i,x);
		}
	}
	tot=0;
	for(int i=1;i<=N;i++)
	{
		dijkstra(i);
		for(int j=i+1;j<=N;j++)
		{
			tot++;
			ve[tot]=dis[j];
		}
	}
	sort(ve+1,ve+tot+1);
	for(int i=1;i<N;i++)
	{
		ans+=ve[i];
	}
	cout<<ans<<endl;
	return 0;
}