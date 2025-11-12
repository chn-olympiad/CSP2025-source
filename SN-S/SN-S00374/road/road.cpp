#include <iostream>
using namespace std;

const int N = 1e4 + 10;
const long long INF = 3e9 + 10;

int n, m, k, need_c[N];
long long e[N][N], c[20], a[20][N];
long long dis[N];
bool vis[N], is_c[20];

long long Prim() {
	long long ans = 0, mindis;
	for (int i = 1; i <= n; ++i) dis[i] = INF;
	dis[1] = 0;
	is_c[0] = 1;
	int u;
	while (true) {
		mindis = INF;
		for (int i = 1; i <= n; ++i) if (! vis[i] && dis[i] < mindis) u = i, mindis = dis[i];
		if (mindis == INF) break;
		vis[u] = 1;
		ans += mindis;
		if (! is_c[need_c[u]]) is_c[need_c[u]] = 1;
		for (int v = 1; v <= n; ++v) {
			if (! vis[v] && e[u][v] < dis[v]) dis[v] = e[u][v], need_c[v] = 0;
			if (! vis[v]) for (int i = 1; i <= k; ++i) {
				if (! is_c[i]) {
					if (c[i] + a[i][u] + a[i][v] < dis[v]) dis[v] = c[i] + a[i][u] + a[i][v], need_c[v] = i;
				} else {
					if (a[i][v] < dis[v]) dis[v] = a[i][v], need_c[v] = 0;
				}
			}
		}
	}
	return ans;
}

signed main(void) {
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) e[i][j] = INF;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		long long w;
		cin >> u >> v >> w;
		e[u][v] = min(e[u][v], w);
		e[v][u] = min(e[v][u], w);
	}
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j) cin >> a[i][j];
	}
	cout << Prim();
}
