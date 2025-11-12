#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int dis[100005];
int c[100005];

struct edge {
	int v, val;
};
int ans;
int vis[100005];

struct nodep {
	int dis, id;
	friend bool operator<(nodep x, nodep y) {
		return x.dis > y.dis;
	}
};
vector<edge>e[100005];
priority_queue<nodep>q;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n + k; i++) {
		dis[i] = 2e9;
	}
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		e[a].push_back({b, c});
		e[b].push_back({a, c});
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;
		}
	}
	dis[1] = 0;
	q.push({0, 1});
	while (!q.empty()) {
		nodep now = q.top();
		int u = now.id, d = now.dis;
		q.pop();
		if (d > dis[u]) {
			continue;
		}
		for (auto it : e[u]) {
			int v = it.v, w = it.val;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dis[i]);
	}
	cout << ans ;
	return 0;
}