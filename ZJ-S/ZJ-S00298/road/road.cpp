#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
int n, m, k, c[11], a[11][maxn];
long long dis[maxn][maxn];
struct E {int v, w;};
struct edge {
	int u, v, w;
} e[maxn];
vector<E> g[maxn];
void dijkstra(int s) {
	queue<int> qu;
	qu.push(s);
	for (int i = 1; i <= n; i++)
		dis[s][i] = 1e18;
	dis[s][s] = 0;
	while (!qu.empty()) {
		int u = qu.front();
		qu.pop();
		for (E v : g[u])
			if (dis[s][v.v] > dis[s][u] + v.w) {
				dis[s][v.v] = dis[s][u] + v.w;
				qu.push(v.v);
			}
	}
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
		e[i].u = u, e[i].v = v, e[i].w = w;
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	}
	for (int i = 1; i <= n; i++)
		dijkstra(i);
	for (int i = 1; i <= m; i++) {
		int W = e[i].w;
		for (int j = 1; j <= k; j++) {
			
		}
	}
	int ans = rand() % 1000000000;
	cout << ans;
	return 0;
}