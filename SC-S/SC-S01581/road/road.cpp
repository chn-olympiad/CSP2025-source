#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m,k,cnt=0,ans=0;
ll minn=0x3f3f3f3f3f3f3f3f;
ll d[10005];
ll newc[15]={0};
int open[15]={0};
int vis[10005];
struct node
{
	ll v,w;
	int tag;
};
vector<node> g[10005];
void prim(int s)
{
	ans=0;
	cnt=0;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q;
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	d[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top().second; q.pop();
		if(vis[u]==1) continue;
		vis[u]=1;
		ans+=d[u]; cnt++;
		if((u-m)>0&&open[u-m]==1) ans+=newc[u-m];
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i].v;
			int w=g[u][i].w;
			int tag=g[u][i].tag;
			if(d[v]>w&&(open[tag]==1))
			{
				d[v]=w;
				q.push({d[v],v});
			}
		}
	}
	return ;
}
void add(int u,int v,int w,int t)
{
	g[u].push_back({v,w,t});
	g[v].push_back({u,w,t});
	return ;
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
	    add(u,v,w,0);
	}
	open[0]=1;
	if(k==0) 
	{
		prim(1);
		cout<<ans<<endl;
		return 0;
	}
	int idx=m;
	for(int i=1;i<=k;i++)
	{
		++idx;
		int c;
	    cin>>c;
	    newc[i]=c;
	    for(int j=1;j<=n;j++)
	    {
	    	int w;
	    	cin>>w;
	    	add(idx,j,w,i);
		}
	}
	for(int i=0;i<(1<<k);i++)
	{
		int tot=0;
		memset(open,0,sizeof(open));
		open[0]=1;
		for(int j=0;j<k;j++)
		{
			int t=(i>>j)&1;
			if(t==0) continue;
			open[j+1]=1;
			tot++;
		}
		prim(1);
		if(cnt>=n-1) minn=min(ans,minn);
	}
	cout<<minn;
	return 0;
}