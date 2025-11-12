#include<bits/stdc++.h>
using namespace std;

const int MAXM = 1e6 + 50;

vector < pair<int, int> > G[MAXM];
int dis[MAXM];

void add(int u, int v, int w) {
	G[u].push_back({v, w});
	G[v].push_back({u, w});
}

dfs(int u, int f) {
	for(int i = 0; i < G[u].size(); i++) {
		int v = G[u][i].first;
		int w = G[u][i].second;
		if(v == f) continue;
		dis[v] = min(dis[v], dis[u] + v);
		dfs(v, u);
	}
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		dis[i] = 0x3f3f3f3f;
	}
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
	}
	
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= n + 1; j++){
			int temp;
			cin>>temp;
		}
	}
	dis[0] = 0;
	dfs(0, 0);
	int ans = 0x3f3f3f3f;
	for(int i = 1; i < m; i++){
		ans = max(ans, dis[i]);
	}
	cout << ans;

	return 0;
}
