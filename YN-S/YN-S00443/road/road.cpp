#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e4 + 15, M = 4e6 + 5;
ll n, m, k, c[N], tot, fa[N], vvis[N];

struct wy {
	ll u, v, w;
};
vector<wy>e;

bool cmp(wy x, wy y) {
	return x.w < y.w;
}

ll find(ll x) {
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (ll i = 1; i <= m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		e.push_back({u, v, w});
	}
	tot = n;
	for (ll i = 1; i <= k; i++) {
		cin >> c[i];
		tot++;
		for (ll j = 1; j <= n; j++) {
			ll w;
			cin >> w;
			e.push_back({tot, j, w});
		}
	}
	sort(e.begin(), e.end(), cmp);
	ll minn = 1e18;
	for (ll i = 0; i <= (1 << k) - 1; i++) {
		memset(vvis, 0, sizeof(vvis));
		ll aans = 0;
		for (ll i = 1; i <= tot; i++)
			fa[i] = i;
		for (ll j = 1; j <= k; j++) {
			if ((i >> (j - 1)) & 1)
				vvis[n + j] = 1;
			else
				aans += c[j];
		}
		for (ll j = 0; j <= e.size(); j++) {
			ll xx = find(e[j].u), yy = find(e[j].v);
			if (xx != yy && vvis[e[j].u] == 0 && vvis[e[j].v] == 0) {
				fa[xx] = yy;
				aans += e[j].w;
			}
		}
		minn = min(minn, aans);
	}
	cout << minn;
	return 0;
}
