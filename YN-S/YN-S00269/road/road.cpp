#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;

struct node {
	int v, w;
};

struct nodep {
	int dis, id, fa;
	friend bool operator<(nodep x, nodep y) {
		return x.dis > y.dis;
	}
};
priority_queue<nodep> q;
vector<node> e[N];
int dis[N], c[N], ans = INT_MAX, n, m, k, vis[N], che[N], flag[11][N];

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		e[x].push_back({y, z});
		e[y].push_back({x, z});
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[n + i];
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			che[i + n] = 1;
			e[j].push_back({n + i, x });
			e[n + i].push_back({j, x});
		}
	}
	memset(dis, 0x7f, sizeof(dis));
	dis[1] = 0;
	int tmp = 0;
	q.push({0, 1, 0});
	while (!q.empty()) {
		nodep now = q.top();
		q.pop();
		int u = now.id, d = now.dis;
		if (d > dis[u])
			continue;
		for (auto it : e[u]) {
			int v = it.v, w = it.w;
			if (dis[v] > dis[u] + w ) {
				dis[v] = dis[u] + w;
				if (che[v]) {
					vis[v] = w;
					q.push({dis[v], v, w});
				}
				if (che[u]) {
					flag[u - n][v] = 1;
					vis[v] = w + now.fa;
					q.push({dis[v], v, 0});
				}
			}
			if (dis[v] <= dis[u] + w ) {
				if (che[u]) {
					flag[u - n][v] = 0;
				}
			}
		}
	}
	int Max = 0;
	for (int i = 1; i <= n ; i++) {
		Max += vis[i];
	}
	ans = min(ans, Max);
	cout << ans;
	return 0;
}
