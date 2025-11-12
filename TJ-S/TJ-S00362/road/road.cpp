#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
const int M = 3e6 + 10;

struct Edge {
	LL u, v, w;

	bool operator<(const Edge &o) const {
		return w < o.w;
	}
}; 

int n, m, k;
Edge es[M];
Edge used[M];
LL a[11][N];
LL c[N];
int fa[N];

int find(int x) {
	if (x == fa[x]) {
		return x;
	}
	return fa[x] = find(fa[x]);
} 

bool together(int x, int y) {
	return find(x) == find(y);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	fa[x] = y;
}

namespace subtask_1_to_4 {
	LL kruskal() {
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
		LL res = 0;
		sort(es + 1, es + m + 1);
		for (int i = 1; i <= m; i++) {
			LL u = es[i].u, v = es[i].v, w = es[i].w;
			if (!together(u, v)) {
				merge(u, v);
				res += w;
			}
		}
		return res;
	}
	
	
	void solve() {
		LL res = kruskal();
		cout << res << "\n";
	}	
};

namespace subtask_a {
	LL kruskal() {
		for (int i = 1; i <= n + k; i++) {
			fa[i] = i;
		}
		LL res = 0;
		for (int i = 1; i <= m; i++) {
			used[i] = es[i];
		}
		int idx = m;
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				Edge e;
				e.u = i + n;
				e.v = j;
				e.w = a[i][j];
				used[++idx] = e;
			}
		}
		sort(used + 1, used + idx + 1);
		for (int i = 1; i <= idx; i++) {
			LL u = used[i].u, v = used[i].v, w = used[i].w;
			if (!together(u, v)) {
				merge(u, v);
				res += w;
			}
		}
		return res;
	}
	
	
	void solve() {
		LL res = kruskal();
		cout << res << "\n";
	}	
};

namespace subtask_5_to_12 {
	LL w[1050][1050];
	LL dist[1050];
	const LL INFLL = 1e17;
	bool vis[11], in_tree[1050];
	LL res = INFLL;
	
	LL prim() {
		LL addition_node_cost = 0; 
		int node_cnt = n;
		for (int i = 1; i <= k; i++) {
			if (vis[i]) {
				node_cnt++;
				addition_node_cost += c[i];
				for (int j = 1; j <= n; j++) {
					w[i + n][j] = a[i][j];
					w[j][i + n] = a[i][j];
				}
			}
		}
		// cout << node_cnt << "\n";
		for (int i = 1; i <= n + k; i++) {
			dist[i] = INFLL;
			in_tree[i] = false;
		}
		dist[1] = 0;
		LL ans = 0;
		for (int rd = 1; rd <= node_cnt; rd++) {
			LL min_dist = INFLL, nd = -1;
			for (int u = 1; u <= n + k; u++) {
				if (in_tree[u]) continue;
				if (u <= n || vis[u - n]) {
					if (dist[u] < min_dist) {
						min_dist = dist[u];
						nd = u;
					}
				}
			}
			
			ans += min_dist;
			// cout << min_dist << " " << node << "\n"; 
			in_tree[nd] = true;
			
			int u = nd;
			for (int v = 1; v <= n + k; v++) {
				if (v <= n || vis[v - n]) {
					dist[v] = min(dist[v], w[u][v]);
				}
			}
		}
		
		for (int i = 1; i <= k; i++) {
			if (vis[i]) {
				for (int j = 1; j <= n; j++) {
					w[i + n][j] = INFLL;
					w[j][i + n] = INFLL;
				}
			}
		}
		
		return ans + addition_node_cost;
	}
	
	void dfs(int u) {
		if (u == k + 1) {
			LL ans = prim();
			res = min(res, ans);
			return;
		}
		
		dfs(u + 1);
		vis[u] = true;
		dfs(u + 1);
		vis[u] = false; 
	}
	
	void solve() {
		for (int i = 1; i <= n + k; i++) {
			for (int j = 1; j <= n + k; j++) {
				w[i][j] = INFLL;
			}
			w[i][i] = 0;
		}
		for (int i = 1; i <= m; i++) {
			LL u = es[i].u, v = es[i].v, ww = es[i].w;
			w[u][v] = min(w[u][v], ww);
			w[v][u] = min(w[v][u], ww);
		}
		
		memset(vis, 0, sizeof vis);
		dfs(1);
		cout << res << "\n";
	}
};

bool has_a() {
	for (int i = 1; i <= k; i++) {
		if (c[i] != 0) {
			return false;
		}
	}
	
	for (int i = 1; i <= k; i++) {
		bool has_zero = false;
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == 0) {
				has_zero = true;
			}
		}
		if (!has_zero) {
			return false;
		}
	}
	return true;
}

void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		LL u, v, w;
		cin >> u >> v >> w;
		es[i] = {u, v, w};
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}	
	}
	
	if (k == 0) {
		subtask_1_to_4::solve(); 
	} else {
		if (has_a()) {
			subtask_a::solve();
		} else {
			if (n <= 1000) {
				subtask_5_to_12::solve(); 
			} else {
				subtask_5_to_12::solve(); 
			}
		}
	}
}

int main() {
	#ifndef ZCX
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	#endif
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T = 1;
	// cin >> T;
	while (T--) {
		solve();
	} 
	
	return 0;
}
