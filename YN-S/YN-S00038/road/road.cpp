#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int a[N];
long long dis[N];
struct node {
	int v, w;
};
vector<node>e[N];

struct nodee {
	int u, v, w;
};
int n, m;

void dijkstra() {
	int ans;
	memset(dis, 0x3f, sizeof(dis));
	priority_queue<pair<int, int>>q;
	q.push({4, 0});
	dis[1] = 0;
	while (!q.empty()) {
		int u = q.top().first;
		q.pop();

		for (auto [v, w] : e[u]) {
			if (dis[v] + w < dis[u]) {
				dis[u] = dis[v] + w;
				q.push({v, dis[v] + w});
				//	cout << dis[u] << '\n';
			}
		}
	}

}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int ans = 0;
	int k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
		ans += w;
	}

	for (int i = 1; i <= k; i++) {
		int c;
		cin >> c;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
	}
	cout << ans;
//	dijkstra();
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