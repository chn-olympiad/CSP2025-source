#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> edge;

int n, m, k;
vector<edge> lis[10001];
int dis[10001];
int ans = 0;

void dijkstra() {
	priority_queue<edge, vector<edge>, greater<edge> > pq;
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	pq.push({0, 1});
	while (!pq.empty()) {
		edge e1 = pq.top();
		pq.pop();
		long long u = e1.second;
		long long dic = e1.first;
		for (edge e2 : lis[u]) {
			if (dis[u] < dic) {
				continue;
			}
			if (dis[e2.first] > dic + e2.second) {
				dis[e2.first] = dic + e2.second;
				ans = max(ans, dis[e2.first]);
				pq.push({dis[e2.first], e2.first});
			}
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int a, b, k1;
		cin >> a >> b >> k1;
		lis[a].push_back({b, k1});
		lis[b].push_back({a, k1});
	}
	dijkstra();
	cout << ans;
	return 0;
}
