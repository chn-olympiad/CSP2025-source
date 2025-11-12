#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
const int maxx = 10005;
int n, m, k, cnt = 1, head[maxn], u, v, w, c[15];
int dis[maxn], ans;
bool vis[maxn];

struct node {
	int w, to, nxt;
} edge[maxn * 2 + 20 * maxx];

void add(int x, int y, int w) {
	edge[cnt].w = w;
	edge[cnt].to = y;
	edge[cnt].nxt = head[x];
	head[x] = cnt++;
}
/*void spfa(int s) {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	q.push(s);
	v[s] = 1;
	dist[s] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop;
		v[x] = 0;
		for (int i = head[x]; i; i = edge[i].nxt) {
			int y = q.push();
			if (dis[x] + edge[i].w < dist[y]) {
				dist[y] = dis[x] + edge[i].w;
				if (v[y] == 0) {
					v[y] == 1;
				}
			}
		}
	}
}*/

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &w);
			add(n + 1, j, w);
			add(j, n + 1, w);
		}
	}
	for (int i = 1; i <= m; i++) {
		ans = ans + edge[i].w;
	}
	printf("%d", ans);
	return 0;
}
