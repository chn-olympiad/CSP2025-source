#include <bits/stdc++.h>

using namespace std;

#define P pair<long long,int>
const int N = 2e6+5;
int n, m, k; //n--城市数量 m--道路数量 k--乡镇数量
int u, v, w, ci;

struct node {
	int to, w, next;
} edge[N];
int first[10015];
int cnt;
priority_queue<P, vector<P>, greater<P> >p;
int dis[10015];
bool book[10015];

inline void add(int u, int v, int w) {
	edge[++cnt] = {v, w, first[u]};
	first[u] = cnt;
}

signed main() {

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	for (int i = 1; i <= k; i++) {
		cin >> ci;
		for (int j = 1; j <= n; j++) {
			cin >> w;
			add(n + i, j, ci + w);
			add(j, n + i, ci + w);
		}
	}
	n += k;
	for (int i = 1; i <= n; i++) {
		dis[i] = INT_MAX;
	}
	dis[1] = 0;
	p.push(make_pair(dis[1], 1));
	while (!p.empty()) {
		int u = p.top().second;
		p.pop();
		if (book[u] == 1)
			continue;
		book[u] = 1;
		for (int i = first[u]; i; i = edge[u].next) {
			int v = edge[i].to;
			if (dis[v] > dis[u] + edge[i].w) {
				dis[v] = dis[u] + edge[i].w;
				p.push(make_pair(dis[v], v));
			}
		}
	}
	int mmin = INT_MAX;
	for (int i = 1; i <= n; i++) {
		if (book[i] == 0) {
			mmin = min(mmin, dis[i]);
		}

	}
	cout << mmin;

	return 0;
}
