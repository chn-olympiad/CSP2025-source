#include <bits/stdc++.h>
using namespace std;
long long n, m, d, k;
typedef pair<int, int>pii;

vector<int>idd (int ee, vector<vector<pii>> &gp, int start) {
	vector<int> dis(ee, INT_MAX);
	dis[start] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, start});
	while (!pq.empty()) {
		int cd = pq.top().first, u = pq.top().second;
		pq.pop();
		if (cd > dis[u])
			continue;
		for (auto& edge : gp[u]) {
			int v = edge.first;
			int ww = edge.second;
			if (dis[v] > dis[u] + ww) {
				dis[v] = dis[u] + ww;
				pq.push({dis[v], v});
			}
		}
	}
	return dis;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	vector<vector<pii>> gp(n);
	for (int i = 1; i <= m; i++) {
		int u, v, h;
		cin >> u >> v >> h;
		gp[u].push_back({u, h});
		gp[v].push_back({v, h});
	}
	for (int i = 1; i <= k; i++) {
		int s;
		cin >> s;
		for (int j = 1; j <= n; j++) {
			int qq;
			cin >> qq;
			gp[s].push_back({s, qq});
			gp[j + n].push_back({j + n, qq});
		}
	}
	vector<int> dt = idd(n, gp, 0);
	cout << dt[n];
	return 0;
}
