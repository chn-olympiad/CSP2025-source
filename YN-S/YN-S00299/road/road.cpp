#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 5, M = 1e6 + 5;
int n, m, k, res;
int fa[N];

struct Edge {
	int u, v, w;
};
Edge edge[M];

int find(int rt) {
	if (fa[rt] == rt)
		return rt;
	return fa[rt] = find(fa[rt]);
}

void merge(int x, int y) {
	fa[find(x)] = find(y);
}

bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}
int c[15], a[15][N], cnt;

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++) {
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	sort(edge + 1, edge + 1 + m, cmp);
	for (int i = 1; i <= m; i++) {
		if (cnt == n - 1)
			break;
		int u = edge[i].u, v = edge[i].v, w = edge[i].w;
		if (find(u) != find(v)) {
			merge(u, v);
			res += w;
			cnt++;
		}
	}
	cout << res;
	return 0;
}