#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int fa[100015], vis[100015], first[100015], cnt, ans, coast, sum;

struct node {
	int to, w, next;
} edge[2000025];

inline int find(int x) {
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

inline void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		fa[x] = y;
	}
}

inline void add(int u, int v, int w) {
	cnt++;
	edge[cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].next = first[u];
	cnt++;

}

inline bool cmp(node x, node y) {
	return x.w < y.w;
}

int main() {
	//freopen("road.in", "r", stdin);
	//freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	for (int i = 1; i <= k; i++) {
		cin >> coast;
		for (int j = 1; j <= n; j++) {
			int w;
			cin >> w;
			add(n + i, j, w + coast);
			add(j, n + i, w + coast);
		}
	}
	sort(edge + 1, edge + n + k + 1, cmp);
	int u = 1;
	for (int i = first[u]; i != 0; i = edge[i].next) {
		int w = edge[i].w, v = edge[i].to;
		if (find(u) != find(v) ) {
			merge(u, v);
			ans += w;
			sum++;
		}
		if (sum >= n + k)
			break;
	}
	cout << ans;
	return 0;
}
