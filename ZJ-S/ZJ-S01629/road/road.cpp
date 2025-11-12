#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+1;
struct edge{int v,w;};
struct data
{
	int u,d;
	bool operator<(const data &x)const{return x.d<d;}
};
int n,m,k,res=0x3f3f3f3f;
int dis[N];
int c[11],a[11][N];
vector<edge>e[N];
bool vis[N];
priority_queue<data>q;
void dij(int st)
{
	memset(vis,0,sizeof vis);
	memset(dis,0x3f3f3f3f,sizeof dis);
	dis[st]=0;
	q.push({st,0});
	while(!q.empty())
	{
		int u=q.top().u;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<e[u].size();++i)
		{
			int v=e[u][i].v,w=e[u][i].w;
			if(vis[v]) continue;
			if(dis[v]>w) dis[v]=w,q.push({v,dis[v]});
		}
		for(int i=1;i<=n;++i)
		{
			if(vis[i]) continue;
			for(int j=1;j<=k;++j)
			{
				int w=c[j]+a[j][i]+a[j][u];
				if(dis[i]>w) dis[i]=w,q.push({i,dis[i]});
			}
		}
	}
	int ans=0;
//	for(int i=1;i<=n;++i) cout<<dis[i]<<" ";
//	cout<<"\n\n";
	for(int i=1;i<=n;++i) ans+=dis[i];
	res=min(res,ans);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)
	{
		int x,y,w;
		cin>>x>>y>>w;
		e[x].push_back({y,w});
		e[y].push_back({x,w});
	}
	for(int i=1;i<=k;++i)
	{
		cin>>c[i];
		for(int j=1;j<=n;++j) cin>>a[i][j];
	}
	for(int i=1;i<=n;++i) dij(i);
	cout<<res;
}
