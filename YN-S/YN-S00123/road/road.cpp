#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 120212;
int n, m, k;
int fa[N];
int c[12][N];

struct Edge {
	LL u, v, w;
	LL cnt;
};
Edge edges[N];

bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}

int find(int u) {
	if (fa[u] != u)
		return find(fa[u]);
	return u;
}
bitset<N> vis = 0;

LL kruskal() {

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= k; j++) {
			if (edges[i].w > c[j][edges[i].u] + c[j][edges[i].v]) {
				edges[i].w = c[j][edges[i].u] + c[j][edges[i].v];
				vis[edges[i].u] = true;
				vis[edges[i].v] = true;
				edges[i].cnt = c[j][0];
			}
		}
	}
	sort(edges + 1, edges + 1 + m, cmp);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	LL res = 0, cnt = 0;
	for (int i = 1; i <= m; i++) {
		int u = edges[i].u, v = edges[i].v, w = edges[i].w;
		u = find(u);
		v = find(v);
		if (u != v) {
			fa[u] = v;
			res += w;
			if (vis[u] && vis[v]) {
				res += edges[i].cnt;
				vis[u] = false;
				vis[v] = false;
			}
			cnt++;
		}
		if (cnt == n - 1)
			break;
	}

	return res;
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	}
	for (int j = 1; j <= k; j++) {
		for (int i = 0; i <= n; i++) {
			cin >> c[j][i];
			c[i][j] = c[j][i];
		}
	}
	cout << kruskal();
	return 0;
}