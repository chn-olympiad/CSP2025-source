#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3+5;
int g[N][N],ag[N][N],vis[N];
int n,m,k,ans=0;
int a[15][N];
int c[N];
struct Edge
{
	int u,v,w;
	bool operator <(const Edge &oth)
	{
		return w<oth.w;
	};
};
vector<int>vec;
void floyd1()
{
	for(int l=1;l<=n;l++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				ag[i][j]=min(ag[i][j],ag[i][l]+ag[l][j]);
}
void floyd2()
{
	for(int l=1;l<=n;l++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][l]+g[l][j]);
}
int kruskal()
{
	memset(vis,0,sizeof vis); 
	vector<Edge> edges;
	for(int j=1;j<=n;j++)
	{
		for(int l=1;l<=n;l++)
		{
			if(j==l) continue;
			edges.push_back({j,l,g[j][l]});
		}
	}
	sort(edges.begin(),edges.end());
	int t=0,sum=0;
	for(int i=1;i<=edges.size();i++)
	{
		if(i==1)
		{
			vis[edges[t].u]=1;
			vis[edges[t].v]=1;
			sum+=edges[t].w;
//			cout<<edges[t].u<<' '<<edges[t].v<<' '<<edges[t].w<<'\n';
		}
		if((vis[edges[t].u]==0||vis[edges[t].v]==0)&&vis[edges[t].u]!=vis[edges[t].v])
		{
			vis[edges[t].u]=1;
			vis[edges[t].v]=1;
			sum+=edges[t].w;
//			cout<<edges[t].u<<' '<<edges[t].v<<' '<<edges[t].w<<'\n';
		}
		t++;
	}
//	cout<<'\n';
	return sum;
}
void solve()
{
	memset(g,0x1f,sizeof g);
	int sum=0;
	for(int i=1;i<=k;i++)
	{
		if(vec[i]==0) continue;
		sum+=c[i];
		for(int j=1;j<=n;j++)
		{
			for(int l=1;l<=n;l++)
			{
				g[j][l]=min(ag[j][l],a[i][j]+a[i][l]);
			}
		}
	}
	floyd2();
	sum+=kruskal();
	ans=min(ans,sum);
}
void dfs(int now)
{
	if(now>k)
	{
		solve();
//		for(int i=1;i<vec.size();i++)	cout<<vec[i]<<' ';
//		cout<<'\n'; 
		return;
	}
	dfs(now+1);
	vec[now]=0;
	dfs(now+1);
	vec[now]=1;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(ag,0x1f,sizeof ag);
	ans=1e15;
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		ag[u][v]=ag[v][u]=w;
	}
	floyd1();
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	vec.push_back(1);
	for(int i=1;i<=k;i++)
		vec.push_back(1);
	dfs(1);
	cout<<ans;
	return 0;
}
/*
4 2 
l a
al aa
a b
c d
ll la
la lb

*/
