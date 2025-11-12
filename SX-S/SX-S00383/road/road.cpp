#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4, M = 1e6, K = 10, W = 1e9, C = 1e9, A = 1e9;

struct Edge {
	int from, to, weight, nxt;

	friend bool operator<(Edge u, Edge v) {
		return u.weight < v.weight;
	}
} edge[M * 2 + 5];

int cnt, head[N + 5], a[K + 5][N + 5], fa[N + 5];

int find(int now) {
	return now == fa[now] ? now : fa[now] = find(fa[now]);
}

void add(int from, int to, int weight) {
	edge[++cnt] = {from, to, weight, head[from]};
	head[from] = cnt;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
	}
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= k; i++)
		for (int j = 0; j <= n; j++)
			cin >> a[i][j];
	bool flag = true;
	for (int i = 1; i <= k; i++)
		if (a[i][0])
			flag = false;
	if (flag && k)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i != j) {
					int mn = INT_MAX;
					for (int l = 1; l <= k; l++)
						mn = min(mn, a[l][i] + a[l][j]);
					add(i, j, mn);
				}
	sort(edge + 1, edge + cnt + 1);
	int ans = 0;
	for (int i = 1; i <= cnt; i++) {
		int ffrom = find(edge[i].from), fto = find(edge[i].to);
		if (ffrom == fto)
			continue;
		fa[ffrom] = fto;
		ans += edge[i].weight;
	}
	cout << ans << '\n';
	return 0;
}
