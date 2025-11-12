#include<bits/stdc++.h>
using namespace std;
#define INF 98888888
struct ED
{
	int nxt;
	int u;
	int v;
	long long w;
	int rc;
}edge[2100100];

int head[10100],fa[10100];

int n,m,k,cnt;
long long Ans=INF;
long long f[12];
int ot(int x)
{
	if(x%2==1)return x-1;
	else return x+1;
}
void add_edge(int u,int v,long long w,int ro)
{
	edge[++cnt].u=u;
	edge[cnt].v=v;
	edge[cnt].w=w;
	edge[cnt].rc=ro;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}

bool vis[11000],idx[11100];
queue<int> q;

long long krusal()
{
	long long ans=0;
	for(int i=1;i<=n;++i)vis[i]=idx[i]=0;
	for(int i=head[1];i;i=edge[i].nxt)
	{
		if(!edge[i].rc)continue;
		q.push(edge[i].v);
		idx[edge[i].v]=1;
	}
	vis[1]=1;
	idx[1]=1;
	
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		long long t=INF;
		for(int i=head[x];i;i=edge[i].nxt)
		{
			if(!edge[i].rc)continue;
			int v=edge[i].v;
			long long w=edge[i].w;
			if(vis[v]){t=min(w,t);}
			if(!vis[v]&&!idx[v])
			{
				q.push(v);
				idx[v]=1;
			}
		}
		vis[x]=1;
		ans+=t;
	}
	return ans;
}

void dfs(int x,long long cost)
{
	if(x==k+1)
	{
		Ans=min(Ans,krusal()+cost);
		return;
	}
	
	dfs(x+1,cost);
	for(int i=head[n+x];i;i=edge[i].nxt)
	{
		if(edge[i].rc==0)
		{
			edge[i].rc=1;
			edge[ot(i)].rc=1;
		}
	}
	dfs(x+1,cost+f[x]);
	for(int i=head[n+x];i;i=edge[i].nxt)
	{
		if(edge[i].rc==1)
		{
			edge[i].rc=0;
			edge[ot(i)].rc=0;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;++i)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add_edge(u,v,w,2);
		add_edge(v,u,w,2);
	}
	

	for(int i=1;i<=k;++i)
	{
		cin>>f[i];
		for(int j=1;j<=n;++j)
		{
			int w;
			cin>>w;
			add_edge(i+n,j,w,0);
			add_edge(j,i+n,w,0);
		}
	}
	
	dfs(0,0);
	
	cout<<Ans;
	return 0;
} 
