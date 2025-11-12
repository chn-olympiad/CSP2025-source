#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
const int M = 1000005;
int head[M], tot = 1, dis[M];
bool vis[N], a[11][M], c[N];

struct t {
	long long w;
	int to, nxt;
} edge[M * 2];

void add(int u, int v, int ww) {
	edge[++tot].to = v;
	edge[tot].w = ww;
	edge[tot].nxt = head[u];
	head[u] = tot;
}

priority_queue<pair<int, int> >q;

void di(int s) {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[s] = 0;
	q.push(make_pair(0, s));
	while (q.size()) {
		int x = q.top().second;
		q.pop();
		if (vis[x]) {
			continue;
		}
		vis[x] = 1;

		for (int i = head[x]; i; i = edge[i].nxt) {
			int y = edge[i].to;
			int z = edge[i].w;
			if (dis[y] > dis[x] + z) {
				dis[y] = dis[x] + z;
				q.push(make_pair(-dis[y], y));
			}


		}
	}
}


int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "r", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}

	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; i <= n; j++) {
			cin >> a[i][j];
		}
	}
	int sum = 0;

	for (int i = 1; i <= n; i++) {
		di(i);
		int k = 0;
		for (int j = 1; j <= n; j++)
			k = max(k, dis[j]);
		sum = k;
	}
	cout << sum << endl;
	return 0;

}
