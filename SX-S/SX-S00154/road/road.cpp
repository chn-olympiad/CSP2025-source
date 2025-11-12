#include <bits/stdc++.h>
using namespace std;
int n, m, k;

struct road {
	int to;
	long long ww;
};
long long h[15][10010];
bool vis[10010];
typedef pair<long long, int> lll;
const int hh = 1e9;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	vector < vector<road> > e(m + 10);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j <= n; j++) {
			cin >> h[i][j];
		}
	}
	priority_queue < lll, vector<lll>, greater<lll> > q;
	q.push({0, 1});
	long long ans = 0;
	int cnt = 0;
	while (!q.empty()) {
		int id = q.top().second;
		int we = q.top().first;
		q.pop();
		if (cnt == n) {
			break;
		}
		if (vis[id]) {
			continue;
		}

		ans += we;
		cnt++;
		vis[id] = 1;
		int y = e[id].size();
		for (int i = 0; i < y ; i++) {
			q.push({e[id][i].ww, e[id][i].to});
		}
		for (int i = 0; i < k; i++) {
			q.push({h[i][0] + h[i][id] + h[i][e[id][i].to], e[id][i].to});
		}

	}
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
