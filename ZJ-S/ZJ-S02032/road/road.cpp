#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1005, M = 1e7, MAXN = 1e4 + 5;
const LL INF = 1e15;
int n, m, k, vis[MAXN];
LL a[MAXN], cost[15];
LL dis[MAXN], ans = 0;
LL mp[N][N];
int idx = 0, h[MAXN], e[M], ne[M];
LL w[M];
void add(int u, int v, LL c) {
	e[++idx] = v, ne[idx] = h[u], w[idx] = c, h[u] = idx;
}
void prim() {
	for(int i = 0; i <= n; i++) dis[i] = INF;
	memset(vis, 0, sizeof(vis));
	dis[1] = 0;
	for(int cur = 1; cur <= n; cur++) {
		int u = 0;
		for(int i = 1; i <= n; i++) {
			if(!vis[i] && dis[u] > dis[i]) u = i;
		}
		vis[u] = 1;
		ans += dis[u];
		int cnt = 0;
		for(int v = 1; v <= n; v++) {
			if(vis[v]) continue;
			dis[v] = min(dis[v], mp[u][v]);
		}
	}
}
void spe_case_1_4() {
	for(int i = 0; i <= n; i++) dis[i] = INF;
	memset(vis, 0, sizeof(vis));
	dis[1] = 0;
	for(int cur = 1; cur <= n; cur++) {
		int u = 0;
		for(int i = 1; i <= n; i++) {
			if(!vis[i] && dis[u] > dis[i]) u = i;
		}
		vis[u] = 1;
		ans += dis[u];
		for(int i = h[u]; i; i = ne[i]) {
			int v = e[i];
			if(vis[v]) continue;
			dis[v] = min(dis[v], w[i]);
		}
	}
	printf("%lld\n", ans);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	
	if(k == 0) {
		for(int i = 1; i <= m; i++) {
			int u, v;
			LL c;
			scanf("%d %d %lld", &u, &v, &c);
			add(u, v, c);
			add(v, u, c);
		}
		spe_case_1_4();
		return 0;
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) mp[i][j] = INF;
	}
	for(int i = 1; i <= m; i++) {
		int u, v;
		LL c;
		scanf("%d %d %lld", &u, &v, &c);
		mp[u][v] = mp[v][u] = min(mp[v][u], c);
	}
	for(int i = 1; i <= k; i++) {
		scanf("%lld", &cost[i]);
		for(int j = 1; j <= n; j++) scanf("%lld", &a[j]);
		for(int u = 1; u <= n; u++) {
			for(int v = u + 1; v <= n; v++) {
				mp[u][v] = mp[v][u] = min(mp[u][v], a[u] + a[v] + cost[i]);
			}
		}
	}
	prim();
	printf("%lld", ans);
	return 0;
}
