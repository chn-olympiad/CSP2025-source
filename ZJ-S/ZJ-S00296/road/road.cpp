#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+5;
int n,m,k,ans;
int cost[N],a[15][N];
bool vis[N];
int dis[N];
struct node {
	int x,u;
	friend bool operator < (node xx,node yy) {
		return xx.x>yy.x;
	}
};
vector<node> g[N];
void bfs(int x) {
	priority_queue<node> pq;
	pq.push({0,1});
	while(!pq.empty()) {
		auto tmp = pq.top();
		pq.pop();
		int u=tmp.u;
		vis[u]=1;
		if(u==x) {
			dis[u]=tmp.x;
			break;
		}
		for(auto v:g[u]) {
			if(!vis[v.u]) {
				pq.push({tmp.x+v.x,v.u});
			}
		}
	}
}
signed main() {
	cin.tie(0)->sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({w,v});
		g[v].push_back({w,u});
	}
	for(int i=1; i<=k; i++) {
		cin>>cost[i];
		for(int j=1; j<=n; j++) {
			cin>>a[i][i];
		}
	}
	for(int i=2; i<=n; i++) {
		memset(vis,0,sizeof(vis));
		bfs(i);
	}
	for(int i=1; i<=n; i++) {
		ans=max(ans,dis[i]);
	}
	cout<<ans;
	return 0;
}

