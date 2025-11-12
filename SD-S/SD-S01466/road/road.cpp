#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=3e6+5,INF=1e18;
inline int read()
{
	int x=1;
//	while()
}
struct node
{
	int to,nxt,val;
}e[N];
struct whx
{
	int pos,dis;
	bool operator<(const whx &x)const
	{
		return x.dis<dis;
	}
};
int n,m,k,cnt;
int head[N],dis[N],vis[N],co[N];
priority_queue<whx>q;
void add_edge(int u,int v,int w)
{
	e[++cnt].to=v;
	e[cnt].val=w;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
void dfs(int st)
{
	memset(dis,0x3f,sizeof dis);
//	cout<<dis[2]<<endl;
	dis[st]=0;
	co[st]=1;
	q.push((whx){st,0});
//	co[st]=1;
	while(!q.empty())
	{
		int u=q.top().pos;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to;
			if(u<=n&&co[v]<n)
			{
				dis[v]=dis[u]+e[i].val;
				co[v]=co[u];
				if(v<=n&&!vis[v])co[v]++;
			}
			else
			{
				if(dis[v]>dis[u]+e[i].val)dis[v]=dis[u]+e[i].val,co[v]=co[u]+(!vis[v]&&v<=n);
			}
			if(!vis[v])
				q.push((whx){v,dis[v]});
//			cout<<u<<" "<<v<<" "<<co[v]<<endl;
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
		scanf("%lld%lld%lld",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	for(int i=1;i<=k;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=n;j++)
		{
			int w;
			scanf("%lld",&w);
			add_edge(n+i,j,w);
			add_edge(j,n+i,w+x);
		}
	}
	dfs(1);
	int ans=INF;
	for(int i=2;i<=n;i++)
	{
		ans=min(ans,dis[i]);
//		if(dis[i]==505585650)
//		cout<<dis[i]<<" "<<co[i]<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
