#include <bits/stdc++.h>
#define ll long long
#define PII pair <int, int>
#define fi first
#define se second
#define debug() cout << "-----------\n";
using namespace std;
const int MAXM = 1e6 + 100;
const int MAXN = 1e4 + 100;
const int INF = 1e9;

int n, m, k;
int a[20][MAXN];
ll c[20];
int fa[MAXN];
pair <ll, PII> e[MAXM];
ll ans;
int cur;

struct Edge {
	int u, v;
	int w;
	int id;
} h[MAXM];
int tot;

int find (int u) {
	if (u == fa[u])
		return u;
	else
		return fa[u] = find (fa[u]);
}

void merge (int u, int v) {
	fa[u] = find (v);
}

bool cmp (Edge x, Edge y) {
	int xx = (cur >> x.id) & 1, yy = (cur >> y.id) & 1;
	if (xx == yy)
		return x.w < y.w;
	return xx > yy;
}

void kruskal1 () {
	sort (e + 1, e + 1 + m);
	for (int i = 1; i <= m; ++ i) {
		ll w = e[i].fi;
		int u = e[i].se.fi, v = e[i].se.se;
		if (fa[find (u)] == fa[find (v)]) {
			continue;
		}
		merge (u, v);
		h[++ tot] = {u, v, w, 0};
		ans += w;
	}
}

void kruskal2 () {
	for (int i = 1; i <= n; ++ i)
		fa[i] = i;
	int t = 0;
	int tt = 0;
	ll cnt = 0;
	for (int i = 1; i <= k; ++ i) {
		if ((cur >> i) & 1) {
			++ t;
			cnt += c[i];
			fa[i + n] = i + n;
		}
	}
	sort (h + 1, h + 1 + tot, cmp);
	for (int i = 1; i <= tot; ++ i) {
		if (tt > n + k - 1)
			continue;
		ll w = h[i].w;
		int u = h[i].u, v = h[i].v;
		if (fa[find (u)] == fa[find (v)]) {
			continue;
		}
		merge (u, v);
		tt ++;
		cnt += w;
	}

	ans = min (ans, cnt);
}

signed main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);

	ios :: sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++ i) {
		int u, v, w;
		cin >> u >> v >> w;
		e[i] = {w, {u, v}};
	}
	for (int i = 1; i <= k; ++ i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++ j) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; ++ i)
		fa[i] = i;

	kruskal1 ();

	for (int i = 1; i <= k; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			h[++tot] = {i + n, j, a[i][j], i};
		}
	}

	for (int num = 1; num < (1 << k); ++ num) {
		cur = (num << 1) + 1;
		kruskal2 ();
	}

	cout << ans;

	return 0;
}
