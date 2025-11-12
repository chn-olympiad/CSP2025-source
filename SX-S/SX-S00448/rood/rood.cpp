#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int w, u, v;
};

vector<Edge> edge(100100);
vector<int> newEdge(100100);
vector<int> jiShu(100100);
vector<vector<pair<int, int>>> G(100100);
vector<bool> vis(100100);
map<pair<int, int>, int> hashMap;

void dijs(int s, int e) {
	priority_queue<int> pq;
	pq.push(s);
	vis[s] = true;

	while (!pq.empty()) {
		int u = pq.top();

		if (u == e) {
			return ;
		}

		int minL = 114514;
		int minId = 0;
		for (auto nextP : G[u]) {
			int v = nextP.first;
			int w = nextP.second;
			if (!vis[v]) {
				pq.push(v);
				vis[v] = true;
				if (minL > w) {
					minL = w;
					minId = v;
				}
			}
		}

		auto it = hashMap.find({u, minId});
		if (it != hashMap.end()) {
			jiShu[*it] ++;
		}
	}
}

int main() {
	// 新建乡镇等同于新加城市，其边的权值为本身+路
	// 先假设所有路都建，那么只要枚举

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge[i] = {w, u, v};
		hashMap[ {u, v}] = i;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	for (int i = 1; i <= k; i ++) {
		int zhen;
		cin >> zhen;
		for (int j = 1; j <= n; j ++) {
			cin >> newEdge[i];
		}

		for (int x = 1; x <= n; x ++) {
			for (int y = x; y <= n; y ++) {
				edge[m + i] = {newEdge[x] + newEdge[y] + zhen, x, y};
				hashMap[ {x, y}] = i;
			}
		}
	}

	for (int i = 1; i <= n; i ++) {
		for (int j = i; j <= n; j ++) {
			dijs(i, j);
		}
	}

	int ans = 0;
	for (auto i : jiShu) {
		if (i != 0) {
			ans += edge[i].w;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}