#include <bits/stdc++.h>
using namespace std;
int head[5000005], dt[5000005], vi[5000005], cnt = 0, n, m, k, uu, vv, ww, a[5000005];

struct node {
	int to, nxt, w;
} edge[50000005];

void add(int u, int v, int w) {
	cnt++;
	edge[cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].nxt = head[u];
	head[u] = cnt;
}
priority_queue<pair<int, int> > q;

void dj(int s) {
	memset(dt, 0x3f, sizeof(dt));
	memset(vi, 0, sizeof(vi));
	dt[s] = 0;
	q.push(make_pair(0, s));
	while (!q.empty()) {
		int x = q.top().second;
		q.pop();
		vi[x] = 1;
		for (int i = head[x]; i; i = edge[i].nxt) {
			int y = edge[i].to;
			if (vi[y] == 0 && dt[y] > dt[x] + edge[i].w) {
				dt[y] = dt[x] + edge[i].w;
				q.push(make_pair(-dt[y], y));
			}
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> uu >> vv >> ww;
		add(uu, vv, ww);
		add(vv, uu, ww);
	}
	for (int j = 1; j <= k; j++) {
		for (int i = 1; i <= n + 1; i++) {
			cin >> a[i];
		}
	}
	dj(1);
	cout << dt[m];
	return 0;
}
