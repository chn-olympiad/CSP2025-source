#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 1e4 + 5;
ll fa[maxn], a[15][maxn], c[15];
struct EDGE {
	ll u, v, w, k;
	bool operator < (const EDGE tmp) const {
		if (w + c[k] == tmp.w + c[tmp.k]) {
			return k == 0;
		} else {
			return w + c[k] > tmp.w + c[tmp.k];
		}
	}
};
priority_queue<EDGE> e;
ll find (int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	c[0] = 0;
	ll n, m, k;
	ll ans = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		e.push({u, v, w, 0});
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
		for (int j = 1; j <= n; j++) {
			for (int l = j + 1; l <= n; l++) {
				e.push({j, l, a[i][j] + a[i][l], i});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	ll cnt = 0;
	while (cnt < n - 1) {
		EDGE edge = e.top();
		e.pop();
		if (find(edge.u) == find(edge.v)) {
			continue;
		} else {
			cnt++;
			int x = find(edge.u), y = find(edge.v);
			fa[x] = y;
			ans += edge.w + c[edge.k];
			c[edge.k] = 0;
		}
	}
	cout << ans;
	return 0;
}