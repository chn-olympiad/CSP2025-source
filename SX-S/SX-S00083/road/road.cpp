#include <bits/stdc++.h>
using namespace std;
#define N 10110
#define M 2001000
typedef long long ll;
int n, m, k, head[N], tmph[N], cnt, tmpc, c[12]
, link[12][N], vis[N], pre[N], mcj = 0;
ll ans = 0, mia = 0x3f3f3f3f3f3f3f3f, dist[N];

struct node {
	int to, nxt;
	ll w;
} edge[M << 1];

inline void addedge(int u, int v, ll w) {
	edge[++cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].nxt = head[u];
	head[u] = cnt;
}

struct no2 {
	int to;
	ll dis;
	bool operator <(const no2 &b)const {
		return dis > b.dis;
	}
};
priority_queue<no2> q;

inline void Prim() {
	memset(dist, 0x3f, sizeof dist);
	memset(vis, 0, sizeof vis);
	dist[1] = 0;
	q.push(no2{1, 0});
	while (!q.empty()) {
		no2 nd = q.top();
		q.pop();
		if (vis[nd.to])
			continue;
		int u = nd.to;
		vis[u] = 1;
		ans += dist[u];
		for (int i = head[u]; i; i = edge[i].nxt) {
			if (!vis[edge[i].to] && edge[i].w < dist[edge[i].to]) {
				dist[edge[i].to] = edge[i].w;
				q.push(no2{edge[i].to, dist[edge[i].to]});
			}
		}
	}
	while (!q.empty())
		q.pop();
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1, u, v, w; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		addedge(u, v, w);
		addedge(v, u, w);
	}
	for (int i = 0; i < k; i++) {
		scanf("%d", c + i);
		mcj = max(mcj, c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%d", link[i] + j);
		}
	}
	memcpy(tmph, head, sizeof head);
	tmpc = cnt;//
	for (int S = (mcj == 0 ? (1 << k) - 1 : 0); S < (1 << k); S++) {
		memcpy(head, tmph, sizeof head);
		cnt = tmpc;
		ans = 0;
		for (int i = 0; i < k; i++)
			if ((S >> i) & 1) {
				ans += c[i];
				for (int j = 1; j <= n; j++) {
					addedge(n + 1 + i, j, link[i][j]);
					addedge(j, n + 1 + i, link[i][j]);
				}
			}
		Prim();
		mia = min(mia, ans);
	}
	printf("%lld\n", mia);
	return 0;
}
