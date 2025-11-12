#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1000005;

struct ED {
	ll to, nxt, w;
} edge[N * 2];
ll head[N];
ll cnt = 1;

inline void add(ll u, ll v, ll w) {
	edge[cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].nxt = head[u];
	head[u] = cnt++;
}
priority_queue <pair<ll, ll> > q;
ll dist[N];
bool vis[N];

inline void dj(ll s) {
	memset(vis, 0, sizeof vis);
	memset(dist, 0x3f, sizeof dist);
	dist[s] = 0;
	q.push(make_pair(-dist[s], s));
	while (q.size()) {
		ll u = q.top().second;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (ll i = head[u]; i; i = edge[i].nxt) {
			ll v = edge[i].to;
			if (vis[v])
				continue;
			if (dist[v] > dist[i] + edge[i].w) {
				dist[v] = dist[u] + edge[i].w;
				q.push(make_pair(-dist[v], v));
			}
		}
	}
}
bool flag1 = 1;
ll n, m, k;
ll e[15], va[15][N];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	ll a, b, c;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
	}
	for (int i = 1; i <= k; i++) {
		cin >> e[i];
		if (e[i] != 0)
			flag1 = 0;
		for (int j = 1; j <= n; j++) {
			cin >> va[i][j];
			if (va[i][j] != 0)
				flag1 = 0;
		}
	}
	if (flag1 == 1) {
		cout << 0 << '\n';
		return 0;
	} else {
		dj(1);
		cout << dist[n] << '\n';

	}
	return 0;
}
