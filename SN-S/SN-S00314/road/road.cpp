#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e4 + 10;

vector<vector<pair<int, int>>> e; 

int a[20][N], c[N], dis[N];

bool vis[N];

vector<int> state;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	e.resize(n + 1);
	for (int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}
	bool flag = true;
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		if (c[i] != 0) flag = false;
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	
	long long ans = 1e18;
	
	if (flag) {
		long long sum = 0;
		vector<vector<int>> go(n + 1, vector<int>(n + 1, 1e9));
		for (int x = 1; x <= k; ++x) {
			for (int i = 1; i <= n; ++i) {
				for (int j = i + 1; j <= n; ++j) {
					go[i][j] = go[j][i] = min(go[i][j], a[x][i] + a[x][j]);
				}
			}
		}
		memset(dis, 0x7f, sizeof dis);
		memset(vis, false, sizeof vis);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({0, 1});
		dis[1] = 0;
		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int u = it.second, d = it.first;
			if (d > dis[u]) continue;
			vis[u] = true;
			for (auto ed : e[u]) {
				int v = ed.first, w = ed.second;
				if (vis[v]) continue;
				if (w < dis[v]) {
					dis[v] = w;
					pq.push({w, v});
				}
			}
			for (int j = 1; j <= n; ++j) {
				if (j == u) continue;
				if (vis[j]) continue;
				if (go[u][j] < dis[j]) {
					dis[j] = go[u][j];
					pq.push({go[u][j], j});
				}
			}
		}
		for (int j = 1; j <= n; ++j) sum += dis[j];
		ans = min(ans, sum);
	}
	else for (int i = 0; i < (1 << k); ++i) {
		state.clear();
		long long sum = 0;
		for (int j = 1; j <= k; ++j) {
			if (i & (1 << (j - 1))) {
				state.push_back(j);
				sum += c[j];
			}
		}
		vector<vector<int>> go(n + 1, vector<int>(n + 1, 1e9));
		for (int x : state) {
			for (int i = 1; i <= n; ++i) {
				for (int j = i + 1; j <= n; ++j) {
					go[i][j] = go[j][i] = min(go[i][j], a[x][i] + a[x][j]);
				}
			}
		}
		memset(dis, 0x7f, sizeof dis);
		memset(vis, false, sizeof vis);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({0, 1});
		dis[1] = 0;
		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int u = it.second, d = it.first;
			if (d > dis[u]) continue;
			vis[u] = true;
			for (auto ed : e[u]) {
				int v = ed.first, w = ed.second;
				if (vis[v]) continue;
				if (w < dis[v]) {
					dis[v] = w;
					pq.push({w, v});
				}
			}
			if (i) {
				for (int j = 1; j <= n; ++j) {
					if (j == u) continue;
					if (vis[j]) continue;
					if (go[u][j] < dis[j]) {
						dis[j] = go[u][j];
						pq.push({go[u][j], j});
					}
				}
			}
		}
		for (int j = 1; j <= n; ++j) sum += dis[j];
		ans = min(ans, sum);
	}
	cout << ans << '\n';
	return 0;
}
