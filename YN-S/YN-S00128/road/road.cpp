#include <bits/stdc++.h>
#define maxn 10050
#define maxm 100050
#define inf 1000000000100
#define ll long long
using namespace std;
int n, m, k;

struct edge {
	int to, val, nxt;
} e[maxm * 2];
int h[maxm * 2];
int cnt;
int c[maxn], a[maxn][maxn];
ll ans;
ll dis[maxn];
int vis[maxn];

inline void add(int u, int v, int w) {
	e[++cnt].to = v;
	e[cnt].val = w;
	e[cnt].nxt = h[u];
	h[u] = cnt;
	return;
}

struct node {
	int ps, ds;
	friend bool operator < (node a, node b) {
		return a.ds > b.ds;
	}
} tmp;
priority_queue<node>q;

void Prim() {
	for (int i = 1; i <= n; i++)
		dis[i] = inf;
	tmp.ps = 1;
	dis[1] = 0;
	tmp.ds = 0;
	q.push(tmp);
	while (!q.empty()) {
		int u = q.top().ps;
		int d = q.top().ds;
		q.pop();
		for (int i = h[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			int w = e[i].val;
			if (dis[v] > w) {
				dis[v] = w;
				tmp.ds = dis[v];
				tmp.ps = v;
				q.push(tmp);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		ans += dis[i];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	Prim();
	cout << ans;
	return 0;
}