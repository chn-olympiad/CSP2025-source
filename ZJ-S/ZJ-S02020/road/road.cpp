#include<bits/stdc++.h>
using namespace std;
const int N=10010,M=1000010;
struct Edge{
	long long u,v,w;
}edge[M];
int n,m,k,a[15][M];
vector<pair<int,int> > g[N];
vector<pair<int,int> > gnew[N];
bool cmp(pair<int,int> x,pair<int,int> y)
{
	return x.second<y.second;
}
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
bool vis[N];
int main()
{
//	freopen("road3.in","r",stdin);
//	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
		g[edge[i].u].push_back(make_pair(edge[i].w,edge[i].v));
		g[edge[i].v].push_back(make_pair(edge[i].w,edge[i].u));
	}
	if(k==0)
	{
		long long ans=0;
		Edge small;
		small.u=0,small.v=0,small.w=1000000007;
		for(int i=1;i<=m;i++)if(small.w>edge[i].w)small=edge[i];
		ans=small.w;
		vis[small.u]=1;
		vis[small.v]=1;
		for(auto i:g[small.u])if(!vis[i.second])q.push(i);
		for(auto i:g[small.v])if(!vis[i.second])q.push(i);
		while(!q.empty())
		{
			pair<int,int> Top=q.top();
			q.pop();
			int W=Top.first,V=Top.second;
			if(vis[V])continue;
			vis[V]=1;
			ans+=W;
			for(auto i:g[V])if(!vis[i.second])q.push(i);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++)for(int j=0;j<=n;j++)cin>>a[i][j];
	bool ly=1;
	for(int i=1;i<=k;i++)if(a[i][0]!=0)ly=0;
	if(ly==1)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)continue;
				g[i].push_back(make_pair(a[i][j],j));
				g[j].push_back(make_pair(a[i][j],i));
			}
		}
		long long ans=0;
		Edge small;
		small.u=0,small.v=0,small.w=1000000007;
		for(int i=1;i<=m;i++)if(small.w>edge[i].w)small=edge[i];
		ans=small.w;
		vis[small.u]=1;
		vis[small.v]=1;
		for(auto i:g[small.u])if(!vis[i.second])q.push(i);
		for(auto i:g[small.v])if(!vis[i.second])q.push(i);
		while(!q.empty())
		{
			pair<int,int> Top=q.top();
			q.pop();
			int W=Top.first,V=Top.second;
			if(vis[V])continue;
			vis[V]=1;
			ans+=W;
			for(auto i:g[V])if(!vis[i.second])q.push(i);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
