#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 10005;
int fa[N];
int find(int x) {
	return (x == fa[x] ? x : x = find(fa[x]));
}
struct node {
	int u, v, w;
} edge[N];
int n, m, k;
bool cmp(node x, node y) {
	return x.w < y.w;
}
int kruskal() {
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		if (find(edge[i].v) != find(edge[i].u)) {
			fa[find(edge[i].u)] = fa[find(edge[i].v)];
			ans += edge[i].w;
		}
	}
	return ans;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		edge[i].w = LONG_LONG_MAX;
	}
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		edge[i] = {u, v, w};
	}
	stable_sort(edge + 1, edge + m + 1, cmp);
	cout << kruskal() << endl;
	return 0;
}