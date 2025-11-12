#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, k;
int u, v, w;
int c;
struct node {
	int u, v, w;
} edge[1010000];
int idx = 0;
bool cmp(node a, node b) {
	return a.w < b.w;
}
int fa[10020];
int ans;
void add(int u, int v, int w) {
	idx++;
	edge[idx].u = u;
	edge[idx].v = v;
	edge[idx].w = w;
}
int find(int x) {
	if (fa[x] != x) {
		return fa[x] = find(fa[x]);
	}
	return x;
}
void K() {
	for (int i = 1; i <= n + k; i++) {
		fa[i] = i;
	}
	int cnt = 0;
	for (int i = 1; i <= idx; i++) {
		int u = edge[i].u;
		int v = edge[i].v;
		int w = edge[i].w;
		int fu = find(u);
		int fv = find(v);
		if (fu == fv) {
			continue;
		}
		fa[fu] = fv;
		ans += w;
		cnt++;
		if (cnt == n + 1) {
			return;
		}
	}
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	for (int i = 1; i <= k; i++) {
		cin >> c;
		for (int j = 1; j <= n; j++) {
			cin >> w;
			add(n + i, j, w);
			add(j, n + i, w);
		}
	}
	sort(edge + 1, edge + idx + 1, cmp);
	K();
	cout << ans;
	return 0;
}
