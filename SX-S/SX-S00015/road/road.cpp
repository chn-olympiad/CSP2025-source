#include <bits/stdc++.h>
using namespace std;

int n, m, k, a, b, c, cnt, head[3109023], dist[2489021];
bool f[3480912];

struct Edge {
	int nxt, to, w;
} edges[9129514];

void create(int u, int v, int w) {
	cnt++;
	edges[cnt].to = v;
	edges[cnt].w = w;
	edges[cnt].nxt = head[u];
	head[u] = cnt;
}

void dijkstra(int s) {
	memset(dist, 0x3f, sizeof dist);
	memset(f, 0, sizeof f);

	dist[s] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		int cur = pq.top().second;
		pq.pop();
		f[cur] = 1;

		for (int i = head[cur]; i; i = edges[i].nxt) {
			int y = edges[i].to;
			if (f[y] == 0 && dist[y] > dist[cur] + edges[i].w) {
				dist[y] = dist[cur] + edges[i].w;
				pq.push(make_pair(-dist[y], y));
			}
		}
	}

	return;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		create(a, b, c);
		create(b, a, c);
	}

	int ans = 0;
	for (int i = 1; i < n; i++) {
		dijkstra(i);
		ans += dist[i + 1];
	}

	cout << ans << endl;
	return 0;
}