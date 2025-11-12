#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 10001
#define maxm 2000003
#define maxk 11
int n, m, k, head[maxn], c[maxk], a[maxk][maxn], f[maxn * 10], cnt;

struct node {
	int u, v, w;
} edge[maxm];

inline void add(int u, int v, int w) {
	cnt++;

	edge[cnt] = {u, v, w};
}

inline bool cmp(node a, node b) {
	return a.w < b.w;
}

inline void init() {
	for (int i = 0; i <= n + k + 1; i++) {
		f[i] = i;
	}
}

inline int find(int x) {
	if (f[x] == x)
		return x;
	return f[x] = find(f[x]);
}

inline void hb(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx == fy)
		return;
	f[fx] = fy;
}

inline int count(int x) {
	int ans = 0;
	for (int i = 1; i <= n + k; i++) {
		if (find(i) == find(x))
			ans++;
	}
	return ans;
}

inline int kru() {
	int cost = 0;
	int tot = 1;
	sort(edge + 1, edge  + cnt + 1, cmp);
	int x = edge[1].u;
	hb(edge[1].u, edge[1].v);
	cost += edge[1].v;
	int i = 2;
//	cout << edge[1].u << ' ' << edge[1].v << '\n';
	while (tot < n - 1) {
		int u = edge[i].u, v = edge[i].v, w = edge[i].w;
		if (find(u) != find(v)) {
			hb(u, v);
//			cout << u << ' ' << v << '\n';
			tot++;
			cost += edge[i].w;
		}
		i++;
	}
	return cost;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	init();
	cout << kru();
	return 0;
}