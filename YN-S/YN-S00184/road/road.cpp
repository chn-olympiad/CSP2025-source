#include <bits/stdc++.h>
using namespace std;

struct node {
	int to, w;
	friend bool operator<(node a, node b) {
		return a.w > b.w;
	}
} tmp;
const int maxm = 2200010, maxn = 10005;
int n, m, k, cnt = 0;
int h[maxm], nxt[maxm], to[maxm], val[maxm];

void add(int a, int b, int c) {
	cnt++;
	to[cnt] = b;
	val[cnt] = c;
	nxt[cnt] = h[a];
	h[a] = cnt;
}
long long dis[maxn], ans = 0;
bool vis[maxn];

void prim() {
	priority_queue < node > q;
	memset(dis, 0x3f3f3f, sizeof(dis));
	dis[1] = 0;
	tmp.to = 1, tmp.w = 0;
	q.push(tmp);
	while (!q.empty()) {
		tmp = q.top();
		q.pop();
		int d = tmp.to, e = tmp.w;
		if (vis[d])
			continue;
		vis[d] = 1;
		ans += e;
		for (int i = h[d]; i; i = nxt[i]) {
			int f = to[i];
			if (dis[f] > dis[d] + val[i]) {
				dis[f] = val[i];
				tmp.to = f, tmp.w = dis[f];
				q.push(tmp);
			}
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	for (int i = 1; i <= k; i++) {
		int va;
		cin >> va;
		for (int j = 1; j <= n; j++) {
			int wv;
			cin >> wv;
			add(i + n, j, wv + va);
			add(j, i + n, wv + va);
		}
	}
	prim();
	cout << ans;
	return 0;
}