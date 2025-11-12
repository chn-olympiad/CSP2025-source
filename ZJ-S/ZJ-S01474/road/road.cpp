#include <bits/stdc++.h>

using namespace std;

struct Node {
	int u, v, w;
};
int n, m, k;
Node edge[1000005];
int c[15];
int fw[15][10005];
int fa[10005];
int find(int x) {
	if (x == fa[x]) {
		return x;
	}
	fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int x, int y) {
	fa[x] = y;
}
bool cmp(Node x, Node y) {
	return x.w < y.w;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> fw[i][j];
		}
	}
//	if (k == 0) {
		int ans = 0;
		sort(edge + 1, edge + m + 1, cmp);
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
		for (int i = 1; i <= m; i++) {
			int x = find(edge[i].u);
			int y = find(edge[i].v);
			if (x != y) {
				merge(x, y);
				ans += edge[i].w;
			}
		}
		cout << ans << "\n";
//	}
	return 0;
}
/*
4 5 0
1 2 2
1 4 1
4 2 3
4 3 5
2 3 4

*/