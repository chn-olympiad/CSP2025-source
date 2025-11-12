#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define pii pair<int,int>

const int MAXN = 1e4+5,MAXM = 1e6+5;
int n,m,k,idx,ans;
int c[MAXN],vis[MAXN],cnt,d[MAXN],a[11][MAXN];

struct edge{
	int v,w;
};

vector<edge> e[MAXN];

void prims(int s){
	for(int i=1;i<=n;i++) d[i] = 1e18;
	priority_queue<pii> q;
	vis[s] = 1;
	q.push({0,s});
	while(q.size()){
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		ans += d[u];
		for(edge i:e[u]){
			int v = i.v, w = i.w;
			if(d[v]>d[u]+w){
				d[v] = d[u] + w;
				q.push({-d[v],v});
			}
		}
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin >> u >> v >> w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin >> c[i];
		for(int j=1;j<=n;j++) cin >> a[i][j];
	}
	prims(1);
	cout << ans;

	return 0;
}
