#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

const int N = 1e4 + 10;
const int P = 1e9 + 7;
const int MOD = 998244353;

vector<pair<int, int> > G[N];

int n, m, k;

bool vis[N];

void dfs(int u){
	vis[u] = 1;
	for(auto e: G[u]){
		int v = e.first;
		if(vis[v]) continue;
		dfs(v);
		vis[v] = 0;
	}
}

int val[N];

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	int ans = 0;
	for(int i=1; i<=m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		val[i] = w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	
	//MST
	
	sort(val+1, val+m+1);
	for(int i=1; i<=n-1; i++){
		ans += val[i];
	}
	
	cout << ans << endl;
	
	return 0;
}

