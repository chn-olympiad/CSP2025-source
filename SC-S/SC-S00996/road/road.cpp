#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read() {
	ll sum = 0;
	char ch = getchar();
	bool q = 0;
	while (!isdigit(ch)) {
		if (ch == '-') q = 1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		sum = (sum << 1) + (sum << 3) + (ch ^ 48);
		ch = getchar();
	}
	if (q) sum = -sum;
	return sum;
}
ll n, m, k;
ll f[10005];
ll h[10005];
ll a[15][10005];
ll dis[1005][1005];
ll c[15];
struct node {
	ll u;
	ll v;
	ll w;
	bool operator < (const node &x) const {
		return w < x.w;
	}
} edges[2200005];
ll find(ll x) {
	if (x == f[x]) return x;
	return f[x] = find(f[x]);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read();
	m = read();
	k = read();
	for (ll i = 1; i <= n; i++) {
		f[i] = i;
	}
	for (ll i = 1; i <= m; i++) {
		edges[i].u = read();
		edges[i].v = read();
		edges[i].w = read();
	}
	bool p = 1;
	for (ll i = 1; i <= k; i++) {
		c[i] = read();
		if (p && c[i]) p = 0;
		for (ll j = 1; j <= n; j++) {
			a[i][j] = read();
			if (p && a[i][j]) p = 0;
		}
	}
	if (n * n * k <= 50000000) {
		ll tot = m;
		memset(dis, 0x3f, sizeof dis);
		for (ll i = 1; i <= k; i++) {
			for (ll j = 1; j <= n; j++) {
				for (ll k = j + 1; k <= n; k++) {
					dis[j][k] = min(dis[j][k], c[i] + a[i][j] + a[i][k]);
				}
			}
		}
		for (ll i = 1; i <= n; i++) {
			for (ll j = i + 1; j <= n; j++) {
				if (k) edges[++tot] = {i, j, dis[i][j]};
			}
		}
		sort(edges + 1, edges + tot + 1);
		ll res = 0, sum = 0;
		for (ll i = 1; i <= tot; i++) {
			ll u = edges[i].u, v = edges[i].v, w = edges[i].w;
			ll fu = find(u), fv = find(v);
			if (fu == fv) continue;
			if (h[fu] > h[fv]) swap(fu, fv);
			f[fu] = fv;
			if (h[fu] == h[fv]) h[fu]++;
			res += w;
			sum++;
			if (sum >= n - 1) break;
		}
		cout << res << '\n';
	}
	else if (p) {
		cout << 0 << '\n';
	}
	else {
		ll tot = m;
		memset(dis, 0x3f, sizeof dis);
		for (ll i = 1; i <= k; i++) {
			for (ll j = 1; j <= n; j++) {
				for (ll k = j + 1; k <= n; k++) {
					dis[j][k] = min(dis[j][k], c[i] + a[i][j] + a[i][k]);
				}
			}
		}
		for (ll i = 1; i <= n; i++) {
			for (ll j = i + 1; j <= n; j++) {
				if (k) edges[++tot] = {i, j, dis[i][j]};
			}
		}
		sort(edges + 1, edges + tot + 1);
		ll res = 0, sum = 0;
		for (ll i = 1; i <= tot; i++) {
			ll u = edges[i].u, v = edges[i].v, w = edges[i].w;
			ll fu = find(u), fv = find(v);
			if (fu == fv) continue;
			if (h[fu] > h[fv]) swap(fu, fv);
			f[fu] = fv;
			if (h[fu] == h[fv]) h[fu]++;
			res += w;
			sum++;
			if (sum >= n - 1) break;
		}
		cout << res << '\n';
	}
	return 0;
}