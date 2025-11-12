#include<bits/stdc++.h>
using namespace std;
struct abc{
	int a,b;
};
int n,m,k,o=0;
vector<abc>p[100005];
int d[100005],vis[100005],inf=1<<31-1;
int di(int s)
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		d[i]=inf;
	}
	d[s]=0;
	priority_queue<pair<int,int> >q;
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		for(auto t:p[u])
		{
			int v=t.a,w=t.b;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				if(v<=n&&u<=n)
				{
					o+=d[u];
				}
				q.push({-d[v],v});
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		p[x].push_back({y,z});
		p[y].push_back({x,z});
	}
	int ans=n+1;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int x;
			cin>>x;
			p[ans].push_back({j,x});
			p[j].push_back({ans,x});
		}
		ans++;
	}
	int l=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		o=0 ;
		di(i);
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			cnt+=d[j];
		}
		l=min(l,cnt-o);
	}
	cout<<l<<endl;
	return 0;
}
