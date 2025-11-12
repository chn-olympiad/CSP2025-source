#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL ans = INT_MAX, w[10020][10020], a[10020], tong[10020], n, m, k, vv;
vector<int> ve[10020];

void dfs(int u, int sum, LL now) {
	if (now >= ans)
		return;
	if (sum == n) {
		ans = min(ans, now);
		return;
	}
	for (int i = 0; i < ve[u].size(); i++) {
		int v = ve[u][i];
		if (tong[v] == 0) {
			tong[v] = 1;
			dfs(v, sum + (v <= n), now + w[u][v] + a[v]);
			tong[v] = 0;
		}
	}
}

int main() {
	freopen("road2.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, ww;
		cin >> u >> v >> ww;
		ve[u].push_back(v);
		ve[v].push_back(u);
		w[u][v] = w[v][u] = ww;
	}
	for (int i = 1; i <= k; i++) {
		cin >> a[n + i];
		for (int j = 1; j <= n; j++) {
			cin >> vv;
			ve[n + i].push_back(j);
			ve[j].push_back(n + i);
			w[n + i][j] = w[j][n + i] = vv;
		}
	}
	tong[1] = 1;
	dfs(1, 1, 0);
	cout << ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/