#include<bits/stdc++.h>
using namespace std;
long long q[10005];
int f[10005];
int t[10005];
queue<int> p;
vector < pair< int , int > > adj[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,n,k;
	long long ans1=0; 
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)
	{
		q[i]=-1;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		ans1+=w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
	{
		int c,u=n+i;
		cin>>c;
		q[u]=-1;
		for(int j=1;j<=n;j++)
		{
			int v,w;
			cin>>v>>w;
			adj[u].push_back({v,w});
			adj[v].push_back({u,w});
		}
	}
	p.push(1);
	long long ans=0;
	while(!p.empty())
	{
		int u=p.front();p.pop();
		int s_n=0;
		for(auto o:adj[u])
		{
			int v=o.first,w=o.second;
			if(q[v]==-1)
			{
				p.push(v);
				q[v]=q[u]+w;
				continue;
				f[v]=u;
			}
			if(q[v]>q[u]+w)
			{
				p.push(v);
				q[v]=q[u]+w;
				f[v]=u;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		t[f[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(t[i]==0)
		{
			ans+=q[i];
		}
	}
	cout<<min(ans1,ans);
	return 0;
}
