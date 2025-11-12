#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;
const int K = 15;
const int N = 10005;
const int M = 1000005;
int n, m, k, a[K][N], c[K], ans = INF;
bool vis[N + K];
vector < pair < int, int > > vt[N];
struct edge{
	int u, v, w;
} e[M];
int Prim(vector < vector < pair < int, int > > > g){
	memset(vis, 0, sizeof(vis));
	vis[1] = 1;
	priority_queue < pair < int, int > > q;
	for(int i = 0; i < g[1].size(); i++){
		q.push({-g[1][i].second, g[1][i].first});
	}
	int res = 0;
	while(!q.empty()){
		int u = q.top().second, w = -q.top().first;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		res += w;
		if(res >= ans) return res;
		for(int i = 0; i < g[u].size(); i++){
			int v = g[u][i].first, dis = -g[u][i].second;
			if(vis[v]) continue;
			q.push({dis, v});
		}
	}
	return res;
}
int F(int s){
	vector < vector < pair < int, int > > > g(n + k + 1);
	for(int i = 1; i <= n; i++) g[i] = vt[i];
	int res = 0;
	for(int i = 1; i <= k; i++){
		if(s & (1 << (i-1))){
			res += c[i];
			for(int j = 1; j <= n; j++){
				g[j].push_back({i+n, a[i][j]});
				g[i+n].push_back({j, a[i][j]});
			}
		}
	}
	if(res >= ans) return ans;
	return res + Prim(g);
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> e[i].u >> e[i].v >> e[i].w;
		vt[e[i].u].push_back({e[i].v, e[i].w});
		vt[e[i].v].push_back({e[i].u, e[i].w});
	}                                  
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	for(int s = 0; s < (1 << k); s++){
		ans = min(ans, F(s));
	}
	cout << ans << "\n";
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/