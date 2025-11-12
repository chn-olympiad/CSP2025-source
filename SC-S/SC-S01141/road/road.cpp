#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e4 + 7;
const ll M = 1e6 + 7;
ll n, m, k;
struct road {
	ll u, v, w;
}de[M];
ll ans;
ll c[17];
ll a[17][N];

bool cmp(road u, road v) {
	return u.w < v.w;
}

ll fa[N];

ll find_fa(ll x) {
	if (fa[x] == x) {
		return fa[x];
	}
	return fa[x] = find_fa(fa[x]);
}

void merge(ll x, ll y) {
	ll xx = find_fa(x);
	ll yy = find_fa(y);
	
	if (xx != yy) {
		fa[xx] = yy;
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> k;
	
	for (ll i = 0; i <= n; ++i) {
		fa[i] = i;
	}
	
	for (ll i = 1; i <= m; ++i) {
		cin >> de[i].u >> de[i].v >> de[i].w;
//		merge(de[i].u, de[i].v);
	}
	
	for (ll i = 1; i <= k; ++i) {
		cin >> c[i];
		for (ll j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	
	if (k == 0) {
		sort(de + 1, de + m + 1, cmp);
		for (ll i = 1; i <= m; ++i) {
			ll u = de[i].u;
			ll v = de[i].v;
			if (find_fa(u) != find_fa(v)) {
				fa[find_fa(u)] = find_fa(v);
				ans = ans + de[i].w;
			}
		}
		cout << ans;
		return 0;
	}
	
	return 0;
}