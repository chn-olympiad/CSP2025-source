#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>

#define int long long
#define endl "\n"
#define lowbit(x) x&-x;

using namespace std;

struct node
{
	int u,v,w;
	bool operator<(const node &x) const
	{
		return w<x.w;
	}
}e[1000010];

const int N=1e4+10;
int n,k,c[N],tot,m,a[11][N],dis[N],fa[N*2];
bool vis[N],chose[N];
vector<vector<pair<int,int>>> g,g1; 
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]); 
}
void prim()
{
	sort(e+1,e+1+tot);
	for(int i=1;i<=n+k;i++) fa[i]=i; 
	int cnt=0;
	for(int i=1;i<=tot;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)==find(v)) continue;
		fa[find(u)]=find(v);
		g1[u].push_back({v,w});
		g1[v].push_back({u,w});
		cnt++;
		if(cnt==n-1) break;
	}
}

int prim2(int chosen)
{
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n+k;i++) dis[i]=1e18;
	priority_queue<pair<int,int>> q;
	q.push({0,1});
	dis[1]=0;
	int cnt=0,ans=0;
	while(cnt<n+chosen)
	{
		int u=q.top().second;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		ans+=dis[u];
		cnt++;
		for(auto e:g1[u])
		{
			int v=e.first,w=e.second;
			if(v>n&&!chose[v-n]) continue;
			if(dis[v]>w)
			{
				dis[v]=w;
				q.push({-dis[v],v});
			}
		}
	}
	return ans;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	g.resize(n+k+1);
	g1.resize(n+k+1);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[++tot]={u,v,w};
	}
	prim();
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) 
		{
			cin>>a[i][j];
			g1[n+i].push_back({j,a[i][j]});
			g1[j].push_back({n+i,a[i][j]});
		}
	}
	if(k==0)
	{
		cout<<prim2(0);
		return 0;
	}
	int ans=2e18; 
	for(int i=0;i<(1<<k);i++)
	{
		int cost=0,cnt1=0;
		for(int j=0;j<k;j++) cnt1+=(i&(1<<j)?1:0),chose[j+1]=(i&(1<<j)?1:0),cost+=c[j+1]*(i&(1<<j)?1:0);
		ans=min(ans,cost+prim2(cnt1));
	}
	cout<<ans<<endl;
	return 0;
}

