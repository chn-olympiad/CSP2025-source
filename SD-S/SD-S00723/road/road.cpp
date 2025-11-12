#include<bits/stdc++.h>
using namespace std;
struct P
{
	long long v,w;
};
const long long N=1e6+50;
vector<P> g[N];
long long dis[N],vis[N],c[N];
struct node
{
	long long pos,dis;
	bool operator <(const node&a)const{return dis>a.dis;}
};
priority_queue<node> q;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++)
	{
		long long u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	long long cnt=1;
	cout<<"\n---------\n";
	for(long long i=1;i<=k;i++)
	{
		cin>>c[i];
		for(long long i=1;i<=k;i++)
		{
			long long a;
			cin>>a;
			g[n+cnt].push_back({i,a});
			g[i].push_back({n+cnt,a});
		}
	}
	cout<<"\n---------\n";
	memset(dis,0x3f,sizeof dis);
	q.push({1,0});
	dis[1]=0;
	long long ans=0;
	while(q.size())
	{
		node now=q.top();
		long long u=now.pos;
			q.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(auto nxt:g[u])
			{
				long long v=nxt.v,w=nxt.w;
				if(dis[v]>dis[u]+w)
				{
					dis[v]=dis[u]+w;
					q.push({v,dis[v]});
					ans+=w;
				}
			}
		}
		cout<<ans;
    return 0;
}


