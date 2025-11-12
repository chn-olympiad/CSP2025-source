#include<bits/stdc++.h>
using namespace std;
int c[11],a[11][10001];
bool vis[10011];
struct edge{
	int end,val;
};
vector<edge>g[10011];
bool operator<(edge x,edge y)
{
	return x.val>y.val;
}
priority_queue<edge>que;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w;
	long long ans;
	edge e,t;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		e.val=w;
		e.end=v;
		g[u].push_back(e);
		e.end=u;
		g[v].push_back(e);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			e.val=a[i][j];
			e.end=j;
			g[n+i].push_back(e);
			e.end=n+i;
			g[j].push_back(e);
		}
	}
	t.end=1;
	t.val=0;
	ans=0;
	que.push(t);
	while(!que.empty())
	{
		t=que.top();
		que.pop();
		if(vis[t.end])
			continue;
		vis[t.end]=true;
		ans+=t.val;
		for(int i=0;i<g[t.end].size();i++)
			que.push(g[t.end][i]);
	}
	cout<<ans;
	return 0;
}
