#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 100, M = 1e7;
struct Edge {
	int v, nxt, w, u, t;
} edge[M];
int n, m, k, ans, tot, head[N], xiu[N], fa[N], use_n[N], use_m[N];
void add(int u, int v, int w, int t) {
	edge[++tot].v = v;
	edge[tot].u = u;
	edge[tot].w = w;
	edge[tot].t = t;
	edge[tot].nxt = head[u];
	head[u] = tot;
}
bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}
void bing(int a, int b) {
	fa[a] = fa[b];
}
bool pan_h(int a, int b) {
	return fa[a] == fa[b];
}
void wanla() {
	int cai = n;
	while (cai --) {
		int i = 1;
		int u = edge[i].u, v = edge[i].v, t = edge[i].t, w = edge[i].w;
		if (pan_h(u, v) && !use_n[i]) continue;
		if (!use_m[t]) {
			use_m[t] = 1;
			for (int j = 1; j <= tot; j++) {
				if (edge[j].t == t) edge[j].w -= xiu[t];
			}
			sort(edge + 1, edge + 1 + tot, cmp);
			i --;
		}
		ans += w;
		i ++;
	}
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i ++) head[i] = -1, fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w, 0), add(v, u, w, 0);
	}
	for (int i = 1; i <= k; i++) {
		int x;
		scanf("%d", &x);
		xiu[i] = x;
		for (int j = 1; j <= n; j++) {
			int y;
			scanf("%d", &y);
			for (int p = 1; p <= n; p++) {
				if (j == p) continue;
				add(j, p, y + x, i), add(p, j, x + y, i);
			}
		}
	}
	sort(edge + 1, edge + 1 + tot, cmp);
//	for(int i=1;i<=tot;i++){
//		cout << edge[i].w << ' ' << edge[i].u << ' ' << edge[i].v << endl;
//	}
	//wanla();
	cout << 0;

	return 0;
}