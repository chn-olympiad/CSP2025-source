#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int w[10005];
struct node
{
	int v,w;
}a[1000005];
int cmp(node x,node y)
{
	return x.w<y.w;
}
priority_queue<node> q;
bool operator<(node x,node y)
{
	return x.w>y.w;
}
vector<node> vc[10005];
int vis[10005];
long long ans;
void p()
{
	q.push({1,0});
	for(int i=1;i<=n;i++)
	{
		node now=q.top();q.pop();
		int u=now.v;
		if(vis[u])
		{
			i--;
			continue;
		}
		ans+=now.w;
		vis[u]=1;
		for(int j=0;j<vc[u].size();j++)
		{
			int v=vc[u][j].v,w=vc[u][j].w;
			if(vis[v]) continue;
			q.push({v,w});
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
		int u,v,w;
		cin>>u>>v>>w;
		vc[u].push_back({v,w});
		vc[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++) 
	{
		int c;
		cin>>c;
		int free=0;
		for(int j=1;j<=n;j++)
		{
			cin>>w[j];
			if(w[j]==0) free=j;
		}
		for(int j=1;j<=n;j++)
		{
			if(j==free) continue;
			vc[j].push_back({free,w[j]});
			vc[free].push_back({j,w[j]});
		}
	}
	p();
	cout<<ans<<endl;
	return 0;
}
