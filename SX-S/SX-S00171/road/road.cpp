#include <bits/stdc++.h>
using namespace std;
vector<pair<int, long long> >vec[10010];
long long n, m, k;
long long c[15];
long long a[15][10010];
long long mn[10010];

void dij() {
	mn[1] = 0;
	queue<pair<int, long long> >q;
	q.push({1, 0});
	while (!q.empty()) {
		pair p = q.front();
		q.pop();
		int u = p.first, w = p.second;
		for (auto v : vec[u]) {
			if (mn[v.first] > w + v.second) {

				mn[v.first] = w + v.second;
			}
			q.push({v.first, mn[v.first]});

		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> k;
	int u, v;
	long long w;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		if (u == v) {
			continue;
		}
		vec[u].push_back({v, w});
//		vec[v].push_back({u, w});
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
//	for (int h = 1; h <= k; h++) {
//		for (int i = 1; i < n; i++) {
//			for (int j = i; j <= n; j++) {
//				vec[i].push_back({j, c[h] + a[h][i] + a[h][j]});
//				vec[j].push_back({i, c[h] + a[h][i] + a[h][j]});
//			}
//		}
//	}
	memset(mn, 27, sizeof mn);
	dij();
	cout << mn[n];
	return 0;
}