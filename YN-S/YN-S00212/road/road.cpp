#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans;
vector<pair<int> > g[1010];
int v[11];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "r", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
		ans += m;
	}
	for (int i = 1; i <= k; ++i) {
		cin >> v[i];
		int v, w;
		g[i + n].push_back({v, w});
		g[v].push_back({i + n, w});
	}
	cout << ans << endl;
	return 0;
}