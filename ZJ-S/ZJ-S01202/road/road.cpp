#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
#define ll long long

using namespace std;

int n, m, k, graph[10008][10008];
ll ans = 0;
bool vis[10008];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	memset(graph, 0x3f, sizeof(graph));
	cin >> n >> m >> k;
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v; --u; --v;
		cin >> graph[u][v];
		graph[v][u] = graph[u][v];
	}
	
	for (int i = 0; i < k; i++) {
		int tmp, arr[10008];
		cin >> tmp;
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
			for (int ij = 0; ij < j; ij++) {
				graph[j][ij] = graph[ij][j] = min(graph[ij][j], arr[j] + arr[ij]);
			}
		}
	}
	
//	if (k == 0) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push({0, 0});
//	vis[0] = true;
	
	while (!pq.empty()) {
		pair<int, int> tp = pq.top(); pq.pop();
		if (vis[tp.second]) continue;
		vis[tp.second] = true;
		ans += tp.first;
		for (int x = 0; x < n; x++) {
			if (graph[tp.second][x] == 0x3f3f3f3f) continue;
//			cout << tp.second << " " << graph[tp.second][x] << " " << x << "\n";
			pq.push({graph[tp.second][x], x});
		}
	}
	
	cout << ans << "\n";
	//}
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}

