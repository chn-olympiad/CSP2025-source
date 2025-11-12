#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 10010;

int g[N][N];
int c[N];
int fa[N];
int n, m, k;

int find(int p) {
	return p == fa[p] ? p : fa[p] = find(fa[p]);
}

int ans = 0;
void prim() {
	for (int i = 1; i <= n; i++) {
		int t = 0;
		long long dis = 1e18;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (find(i) != find(j) && g[i][j] < dis) {
//				cout << i << ' ' << j << endl;
				t = j;
				dis = g[i][j];
			}
		}
		if (t) {
//			cout << i << ' ' << t << endl;
			ans += g[i][t];
			fa[i] = t;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			g[i][j] = 1e18;
		}
	}
	
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = g[v][u] = min(g[u][v], w);
	}
	
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	
	if (k == 0) {
		prim();
		cout << ans << '\n';
		return 0;
	}
	
	for (int i = 1; i <= k; i++) {
		int cj;
		cin >> cj;
		for (int j = 1; j <= n; j++) {
			cin >> c[j];
		}
		for (int u = 1; u <= n; u++) {
			for (int v = u + 1; v <= n; v++) {
//				cout << c[u] + c[v] << '\n';
				g[u][v] = g[v][u] = min(g[u][v], c[u] + c[v]);
			}
		}
	}
	
	prim();
	cout << ans << '\n';
	
	return 0;
}
