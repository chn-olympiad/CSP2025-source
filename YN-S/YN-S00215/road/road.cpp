// YN-S00215 T2 16PTS
#include <bits/stdc++.h>
using namespace std;
#define int long long
int trash;
int n, m, k;
priority_queue<tuple<int, int, int>,
               vector<tuple<int, int, int>>,
               greater<tuple<int, int, int>>> graph;
vector<int> dsu;

int find(int x) {
	if (x == dsu[x]) {
		return x;
	}
	return x = find(dsu[x]);
}

void join(int i, int j) {
	if (i > j)
		swap(i, j);

	dsu[j] = find(i);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	dsu.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		dsu[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph.push({w, u, v});
		// graph.emplace_back(w, v, u);
	}
//	for (int i = 1; i <= k; i++) {
//		for (int j = 0; j <= n; j++) {
//			if (j == 0) {
//				cin >> trash;
//			} else {
//				int w;
//				cin >> w;
//				graph.push({w, i, j});
//				// graph.emplace_back(w, j, i);
//			}
//		}
//	}

	int price = 0;
	int roads = 0;
	while (!graph.empty()) {
		auto [w, i, j] = graph.top();
		graph.pop();
		if (find(i) != find(j)) {
			price += w;
			roads++;
		}
		if (roads == n - 1) {
			break;
		}
	}
	cout << price << endl;
	return 0;
}