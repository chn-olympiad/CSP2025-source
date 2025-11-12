#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef int ll;

ll n, m, k, u, v, w;

struct edge {
	ll v, w, next;
} e[2200005];
ll head[200005], cnt;

ll c[15], a[15][200005];

void add_edge(ll u, ll v, ll w) {
	e[++cnt] = {v, w, head[u]};
	head[u] = cnt;
}

bool chengshihua[15];

struct node {
	ll u, w;
	bool operator<(const node &a) const {
		return w > a.w;
	}
};

priority_queue<node> q;
bool vis[200005];

ll prim() {
	for (int i = 1; i <= n + k; i ++) vis[i] = 0;
	ll s = 1;
	ll ans = 0, tcnt = 1;
	q.push({s, 0});
	while (!q.empty()) {
		node no = q.top();
		ll u = no.u, w = no.w;
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		ans += w;
		tcnt ++;
		for (int i = head[u]; i; i = e[i].next) {
			ll v = e[i].v, w = e[i].w;
			if (v > n && !chengshihua[v-n]) continue;
			if (!vis[v]) {
				q.push({v, w});
			}
		}
		if (tcnt == n + k) return ans;
	}
	return ans;
}

ll ans = 1e9;

void dfs(ll u) {
	ll cost = 0;
	for (int i = 1; i <= k; i ++) cost += c[i] * chengshihua[i];
	cost += prim();
	ans = min(ans, cost);
	for (int i = u + 1; i <= k; i ++) {
		chengshihua[i] = true;
		dfs(i);
		chengshihua[i] = false;
	}
}

int main () {
	freopen("road3.in", "r", stdin);
	freopen("road3.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++) {
		cin >> u >> v >> w;
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	for (int i = 1; i <= k; i ++) {
		cin >> c[i];
		for (int j = 1; j <= n; j ++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= k; i ++) {
		for (int j = 1; j <= n; j ++) {
			add_edge(j, n+i, a[i][j]);
			add_edge(n+i, j, a[i][j]);
		}
	}
	dfs(0);
	cout << ans;
	return 0;
}
