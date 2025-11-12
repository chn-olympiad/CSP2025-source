#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector<pair<int, int>> e[maxn];
bool q[10000];
int n, m, k;

dfs(int x) {
	for (const  e[x] : i) {

	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k ;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}
	for (int i = 1; i <= k; i++) {
		cin >> q[i];
		for (int j = 1; j <= n; j++) {
			int w;
			cin >> w;
			e[i + n].push_back({j, w});
			e[j].push_back({i + n, w});
		}
	}
	return 0;
}