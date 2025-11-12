#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, k;
struct node {
	ll u, v, w;
};
vector<node> e;
ll buy[10004], a[10004], fa[10004];

bool cmp(node a, node b) {
	return a.w < b.w;
}

ll find(ll x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

ll D() {
	for (ll i = 1; i <= n; i++) {
		fa[i] = i;
	}
	sort(e.begin(), e.end(), cmp);
	ll cnt = 0, ans = 0;
	for (ll i = 0; i <= e.size(); i++) {
		ll u = e[i].u, v = e[i].v, w = e[i].w;
		ll u1 = find(u), v1 = find(v);
		if (u1 == v1) continue;
		fa[u1] = v;
		ans += w;
		cnt++; 
		
		if (cnt == n - 1) {
			return ans;
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	ll u, v, w;
	for (ll i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		e.push_back({u, v, w});
	}

	for (ll i = 1; i <= k; i++) {
		cin >> buy[i];
		for (ll j = 1; j <= n; j++) {
			cin >> a[j];
		}
		for (ll j = 1; j <= n; j++) {
			for (ll k = j + 1; k <= n; k++) {
				e.push_back({j, k, buy[i] + a[j] + a[k]});
			}
		}
	}

	cout << D();
}