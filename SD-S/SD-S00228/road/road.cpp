#include <bits/stdc++.h>
#define x first
#define y second
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<long,long> PLL;
const int N=1e4+10;
vector<PII> vec[N];
int vis[N],cnt,dis[N];
int n,m,k,c[11];
int dfs(int u)
{
	if(!vis[u])
	{
		if(u<=n)
			cnt++;
		vis[u]=1;
	}
	if(cnt>n)
	{
		return dis[u];
	}
	for(auto x:vec[u])
	{
		int v=x.first;
		int w=x.second;
		if(dis[u]+w<dis[v])
		{
			dis[v]=dis[u]+w;
			if(v>n&&!vis[v])
			{
				dis[v]+=c[v-n-1];
			}
			dfs(v);
		}
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		vec[u].push_back({v,w});
		vec[v].push_back({u,w});
	}
	fill(dis+1,dis+n+k+2,1e18);
	for(int i=1;i<=k;i++)
	{
		bool f=0;
		int c0;
		cin>>c[i];
		if(c0!=0)
		{
			f=1;
		}
		for(int j=1;j<=n;j++)
		{
			cin>>c0;
			if(c0!=0)
			{
				f=1;
			}
			vec[i+n+1].push_back({j,c0});
			vec[j].push_back({i+n+1,c0});
		}
		if(!f)
		{
			cout<<0<<endl;
			return 0;
		}
	}
	dis[1]=0;
	
	cout<<dfs(1);
	return 0;
}


