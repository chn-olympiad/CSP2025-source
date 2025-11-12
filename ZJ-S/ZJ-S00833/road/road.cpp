#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int n, m, k;
vector<int> g[10010], w[10010];
int vis[10010];
struct node {
	int u, sum;
};
bool operator < (node x, node y) {
	return x.sum > y.sum;
}
priority_queue<node, vector<node> > q;
void kruskal() {
	q.push({1, 0});
	int s = 0;
	while(!q.empty()) {
		node now = q.top(); q.pop();
		int u = now.u, sum = now.sum;
		if(vis[u]) continue;
		vis[u] = 1;
		s += sum;
		//cout << u << " " << s << '\n';
		for(int i = 0; i < int(g[u].size()); i ++) {
			int v = g[u][i];
			if(!vis[v]) 
				q.push({v, w[u][i]});
		}
	}
	cout << s << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	if(k == 0) {
		for(int i = 1; i <= m; i ++) {
			int u, v, z; cin >> u >> v >> z;
			g[u].push_back(v);
			g[v].push_back(u);
			w[u].push_back(z);
			w[v].push_back(z);
		}
		kruskal();
	}
	return 0;
}
/*
4 5 0
1 2 4
1 3 1
2 4 5
2 5 3
4 5 1
*/