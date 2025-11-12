#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
ll n, m, k, c[15], a[15][10050], times[15], val[15], fa[10005];
map<ll, ll> mp;
bitset<15> qui;
bitset<10050> vis;
ll ans = 2e18, dis[10050];

struct node {
	ll u, v, w;
	bool operator > (node b) const {
		return w > b.w;
	}
};

vector<node> e[10050];

ll prim() {
	ll res = 0, cnt = 0;
	vis.reset();
	for (ll i = 1; i <= n + k; i++)
		dis[i + k] = 2e18;
	for (ll i = 1; i <= k; i++)
		val[i] = times[i] = 0;
	priority_queue<node, vector<node>, greater<node> > q;
	q.push({n + k + 1, k + 1, 0});
	while (!q.empty()) {
		ll d = q.top().w, u = q.top().v, fa = q.top().u;
		q.pop();
		if (vis[u])
			continue;
		res += d;
		if (u > k)
			cnt++;
		if (fa <= k)
			times[u]++;
		if (u <= k)
			times[u]++, val[u] = d;
		dis[u] = 0;
		vis[u] = true;
		for (node ed : e[u]) {
			ll v = ed.v, w = ed.w;
			if ((v <= k && qui[v]) || v > k)
				if (dis[v] > w) {
					dis[v] = w;
					q.push({u, v, dis[v]});
				}
		}
	}
	for (ll i = 1; i <= k; i++)
		if (times[i] == 1)
			res -= val[i];
	return cnt >= n ? res : 2e18;
}

void dfs(ll pos, ll sum)  {
	if (pos > k) {
		ans = min(ans, prim());
		return;
	}
	dfs(pos + 1, sum);
	qui[pos] = 1;
	dfs(pos + 1, sum + c[pos]);
	qui[pos] = 0;
}

vector<node> edg;

ll find(ll x) {
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

bool cmp(node a, node b) {
	return a.w < b.w;
}

void solve1() {
	ans = 0;
	for (ll i = 1; i <= n; i++)
		fa[i] = i;
	for (ll i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		edg.push_back({u, v, w});
	}
	sort(edg.begin(), edg.end(), cmp);
	for (node ed : edg) {
		ll u = find(ed.u), v = find(ed.v), w = ed.w;
		if (u == v)
			continue;
		fa[u] = v;
		ans += w;
	}
	cout << ans << '\n';
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m >> k;
	if (k == 0)
		solve1(), exit(0);
	memset(a, 0x3f, sizeof(a));
	for (ll i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		e[u + k].push_back({v + k, w});
		e[v + k].push_back({u + k, w});
	}
	for (ll i = 1; i <= k; i++) {
		cin >> c[i];
		for (ll j = 1, x; j <= n; j++) {
			cin >> x;
			e[i].push_back({k + j, x});
			e[j + k].push_back({i, x + c[j]});
		}
	}
	dfs(1, 0);
	cout << ans << '\n';
	return 0;
}
