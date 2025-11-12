#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10;
int a[N], dist[N], f[N][N], c[15], used[N][N];
bool vis[N], turned[N];
struct node{
	int x, dis, id;
	bool operator < (const node &y) const{
		return y.dis<dis;
	}
};
struct node2{
	int x, dis, id;
};
vector<node2> graph[N];
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(dist, 0x3f, sizeof dist);
	memset(f, 0x3f, sizeof f);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, t;
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		f[u][v]=f[v][u]=min(f[u][v], w);
	}
	for(int i=1;i<=t;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[j];
		for(int j=1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				if(c[i]+a[j]+a[k]<f[j][k]) f[j][k]=f[k][j]=c[i]+a[j]+a[k], used[j][k]=used[k][j]=i;
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			node2 tmp1={j, f[i][j], used[i][j]}, tmp2={i, f[i][j], used[i][j]};
			graph[i].emplace_back(tmp1), graph[j].emplace_back(tmp2);
		}
	priority_queue<node> q;
	vis[1]=1;
	for(auto tmp:graph[1]) dist[tmp.x]=tmp.dis, q.push({tmp.x, tmp.dis, tmp.id});
	int ans=0;
	while(!q.empty())
	{
		node now=q.top();
		q.pop();
		int x=now.x, dis=now.dis, id=now.id;
		if(vis[x]) continue;
		vis[x]=1;
		ans+=dis;
		turned[id]=1;
		for(auto tmp:graph[x])
		{
			int tdis=tmp.dis;
			if(turned[tmp.id]) tdis-=c[tmp.id];
			if(!vis[tmp.x]&&tdis<dist[tmp.x]) dist[tmp.x]=tdis, q.push({tmp.x, tdis, tmp.id});
		}
	}
	cout<<ans;
	return 0;
}
