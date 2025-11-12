#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+50,I=INT_MAX;
int n,m,k,vil[15][N],vis[15],sum,ans=I,dis[N];//vis's for vil
struct edge
{
	int v,val;
	bool used;
};
edge e;
vector<edge>g[N];
vector<edge>::iterator it;
struct point
{
	int id,dis;
	friend bool operator<(point p1,point p2)
	{
		return p1.dis>p2.dis;
	}
};
point now,tmp;
priority_queue<point>q;
bool flaga=1;
bool cmp(edge e1,edge e2)
{
	return e1.val<e2.val;
}
int bfs()
{
	int res=0;
	while(!q.empty())
	{
		now=q.top();
		q.pop();
		int u=now.id;
		if(now.dis>dis[u]) continue;
		for(it=g[u].begin();it!=g[u].end();it++)
		{
			e=*it;
			int v=e.v,w=e.val;
			if(now.dis+w<dis[v])
			{
				if(!e.used) res+=e.val,e.used=1;
				dis[v]=now.dis+w;
				tmp.id=v,tmp.dis=dis[v];
//				cout<<"!\n";
				q.push(tmp);
			}
		}
	}
//	cout<<'\n';
//	while(!q.empty()) q.pop();
	return res;
}
void dfs(int dth)
{
	if(dth>k)
	{
		for(int i=1;i<=n;i++)
		{
			sort(g[i].begin(),g[i].end(),cmp);
		}
		for(int i=n+1;i<=n+k;i++)
		{
			sort(g[i].begin(),g[i].end(),cmp);
		}
		sum=0;
		for(int i=1;i<=k;i++)
		{
			if(vis[i]) 
			{
//				cout<<"!\n";
				sum+=vil[i][0];
				for(int j=1;j<=n;j++)
				{
					e.v=n+i,e.val=vil[i][j];
					g[j].push_back(e);
					e.v=j;
					g[n+i].push_back(e);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j==i) dis[j]=0;
				else dis[j]=I;
			}
			now.id=i,now.dis=0;
			q.push(now);
			ans=min(ans,sum+bfs());
		}
		for(int i=1;i<=k;i++)
		{
			if(vis[i])
			{
				for(int j=1;j<=n;j++)
				{
					if(j==n+i) dis[j]=0;
					else dis[j]=I;
				}
				now.id=n+i,now.dis=0;
				q.push(now);
				ans=min(ans,sum+bfs());
			}
		}
		for(int i=1;i<=k;i++)
		{
			if(vis[i]) 
			{
				for(int j=1;j<n;j++)
				{
					it=g[j].end()-1;
					g[j].erase(it);
				}
				it=g[n+i].begin();
				while(g[n+i].size())
				{
					g[n+i].erase(it);
				}
			}
		}
		return ;
	}
	vis[dth]=1;
	dfs(dth+1);
	vis[dth]=0;
	dfs(dth+1);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e.v=v,e.val=w;
		g[u].push_back(e);
		e.v=u;
		g[v].push_back(e);
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)//0's build cost
		{
			cin>>vil[i][j];
			if(j==0 and vil[i][j]) flaga=0;
		}
	}
	if(flaga)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				e.v=i+n,e.val=vil[i][j];
				g[j].push_back(e);
				e.v=j;
				g[i+n].push_back(e);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		sort(g[i].begin(),g[i].end(),cmp);
	}
	if(flaga)
	{
		for(int i=n+1;i<=n+k;i++)
		{
			sort(g[i].begin(),g[i].end(),cmp);
		}
	}
	dfs(1);
	cout<<ans<<'\n';
	
	
	return 0;
}