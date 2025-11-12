#include <bits/stdc++.h>
using namespace std;

int nd[10010][10010], n, m, k;

int dfs(int, int);

int main() {
	//freopen("road.in", "r", stdin);
	//freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	memset(nd, -1, sizeof(nd));
	cin >> n >> m >> k;
	int u, v, w;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		nd[u][v] = w;
		nd[v][u] = w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> nd[0][n + i];
		for (int j = 1; j <= n; j++) {
			cin >> w;
			nd[n + i][j] = w;
			nd[j][n + i] = w;
		}
	}

	long long s = dfs(1, 2147483647);
	cout << s;
	return 0;
}

int dfs(int x, int d) {
//	long long mi = LC_MIN;
	for (int i = 1; i <= n; i++) {
		if (nd[i][x] != -1)
			d = min(d, dfs(i, nd[i][x]) + d);
	}
	return d;
}