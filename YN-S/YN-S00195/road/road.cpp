#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
	ll v, w;
};

struct node2 {
	ll u, v, c;
	bool operator > (const node2 a) const {
		return c > a.c;
	}
};

vector<node> G[10015];
ll n, m, k, ans, co[15], vis[10005], fa[10005];
priority_queue<node2, vector<node2>, greater<node2> > pq;

ll find (ll x) {
	if (fa[x] == x) {
		return x;
	}
	return fa[x] = find(fa[x]);
}

void join (ll x, ll y) {
	fa[find(x)] = find(y);
}

void kruskal () {
	ll cnt = 0;
	while (cnt < n) {
		node2 p = pq.top();
		pq.pop();
		ll u = p.u, v = p.v, c = p.c;
		if (u > v) {
			swap(u, v);
		}
		if (find(u) != find(v)) {
			join(u, v), ans += c;
			if (!vis[u]) {
				cnt++, vis[u]++;
			}
			if (!vis[v] && v <= n) {
				cnt++, vis[v]++;
			}
		}
	}
}

int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
		pq.push({u, v, w});
	}
	for (int i = 1; i <= k; i++) {
		cin >> co[i];
		for (int v = 1, w; v <= n; v++) {
			cin >> w;
			pq.push({i + n, v, w});
		}
	}
	for (int i = 1; i <= n + k; i++) {
		fa[i] = i;
	}
	kruskal();

	cout << ans << endl;
	return 0;
}