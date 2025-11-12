#include <bits/stdc++.h>
#define int long long
#define xc(x) (n+x)
#define id(x) (x-n)
using namespace std;
const int N = 1e4+10, M = 1e6+10;
int fe[N][15], n, m, k, cnt, head[N];
bool vis[N + 10], vis_ct[N];

struct edge {
	int u, v, w, nxt;
	bool operator<(const edge &b) const {
		return w > b.w;
	}
} edges[M << 4];

void insert(int u, int v, int w) {
	cnt++;
	edges[cnt].nxt = head[u];
	head[u] = cnt;
	edges[cnt].u = u;
	edges[cnt].v = v;
	edges[cnt].w = w;
}

int dijsktra(int start) {
	priority_queue<edge> q;
	int ans = 0;
	for (int i = head[start]; i; i = edges[i].nxt) {
		q.push(edges[i]);
	}
	for (int i = 1; i <= k; i++) {
		q.push({start, xc(i), fe[0][i] + fe[start][i]});
	}
	vis[start] = true;
	int cc = 1;
	while (!q.empty() && cc < n) {
		edge tgt = q.top();
		q.pop();
		if (vis[tgt.v])
			continue;
		vis[tgt.v] = true;
		if (tgt.v <= n) { //已有城市点
			cc++;
			ans += tgt.w;
			for (int i = head[tgt.v]; i; i = edges[i].nxt) {
				if (!vis[edges[i].v])
					q.push(edges[i]);
			}
			for (int i = 1; i <= k; i++) {
				if (!vis[xc(i)])
					q.push({tgt.v, xc(i), fe[0][i] + fe[tgt.v][i]});
			}
		} else { //改造城市点
			ans += tgt.w;
			for (int i = 1; i <= n; i++) {
				if (!vis[i])
					q.push({tgt.v, i, fe[i][id(tgt.v)]});
			}
		}

	}
	return ans;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		insert(u, v, w);
		insert(v, u, w);
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {//0表示改造费用
			cin >> fe[j][i];
		}
	}
	cout << dijsktra(1);
	return 0;
}
