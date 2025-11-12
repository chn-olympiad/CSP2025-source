#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k;
const ll N = 2e6 + 10;

struct Edge {
	ll u, v, w;
} edge[N];

bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}



ll  h[N] = {0}, p[N];

ll find(ll x) {
	if (p[x] != x)
		p[x] = find(p[x]);
	return x;
}

void unite(ll x, ll y) {
	ll rootx = find(x);
	ll rooty = find(y);
	if (rootx == rooty)
		return;
	if (h[rootx] < h[rooty])
		p[rootx] = rooty;
	else {
		p[rooty] = rootx;
		if (h[rootx] == h[rooty])
			h[rootx]++;
	}
}

void kruskal(ll n, ll cnt) {
	sort(edge + 1, edge + cnt + 1, cmp);
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
	ll opq = 0;
	ll tot = 0;
	for (ll i = 1; i <= cnt; i++) {
		ll u1 = edge[i].u, v1 = edge[i].v;
		if (find(u1) != find(v1)) {
			unite(u1, v1);
			opq++;
			tot += edge[i].w;
		}
		if (opq == n - 1)
			break;
	}

	cout << tot;

}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n >> m >> k;

	for (ll i = 1; i <= m; i++) {
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}
	ll c[k + 1][n + 1];
	ll z;

	for (ll i = 1; i <= k; i++) {
		cin >> z;
		for (ll j = 1; j <= n; j++) {
			cin >> c[i][j];
		}
	}
	ll cnt = m;
	for (ll l = 1; l <= k; l++) {
		for (ll i = 1; i <= n - 1; i++) {
			for (ll j = i + 1; j <= n; j++) {
				edge[++cnt].w = c[l][i] + c[l][j];
				edge[cnt].u = i;
				edge[cnt].v = j;
			}
		}
	}
	kruskal(n, cnt);
	return 0;
}
