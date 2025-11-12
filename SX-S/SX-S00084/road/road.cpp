#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, q, fa[10014], u[1200005], v[1200005], w[1200005], c[10005], newb[10005], realans, tot, ac;
bool b[1200005], oldb[1200005];
priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;

ll getfa(ll x) {
	if (fa[x] == x)
		return x;
	return fa[x] = getfa(fa[x]);
}

int main() {

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> q;
	for (ll i = 1; i <= n; i++)
		fa[i] = i;
	for (ll i = 1; i <= m; i++) {
		tot++;
		cin >> u[tot] >> v[tot] >> w[tot];
		pq.push(make_pair(w[i], i));
	}
	ll num = 0;
	while (num < n - 1 && pq.size()) {
		ll x = pq.top().first, y = pq.top().second;
		pq.pop();
		ll uu = u[y], vv = v[y];
		ll uuu = getfa(u[y]), vvv = getfa(v[y]);
		if (uuu != vvv) {
			num++;
			fa[uuu] = vvv;
			realans += x;
			b[y] = 1;
		}
	}

	for (ll i = 1; i <= q; i++) {
		cin >> c[i];
		for (ll j = 1; j <= i; j++)
			newb[j] = 0;
		for (ll j = 1; j <= tot; j++) {
			oldb[j] = b[j];
			fa[j] = j;
		}

		while (pq.size())
			pq.pop();
		for (ll j = 1; j <= n; j++) {
			ll x;
			cin >> x;
			u[++tot] = n + i;
			v[tot] = j;
			w[tot] = x;
			b[tot] = 1;
		}
		for (ll j = 1; j <= tot; j++) {
			if (b[j] == 1)
				pq.push(make_pair(w[j], j));
			b[j] = 0;
		}
		num = 0;
		ll  ans = 0, oldac = ac;
		ac++;
		while (num < n + ac - 1 && pq.size()) {
			ll x = pq.top().first, y = pq.top().second;
			pq.pop();
			ll uu = u[y], vv = v[y];
			ll uuu = getfa(u[y]), vvv = getfa(v[y]);
			if (uuu != vvv) {
				num++;
				fa[uuu] = vvv;
				ans += x;
				b[y] = 1;
				if (uu > n )
					newb[uu - n]++;
				if (vv > n)
					newb[vv - n]++;

			}
		}
		ll cc = 0, jian = 0;
		for (ll j = 1; j <= i; j++) {
			if (newb[j] > 1)
				cc += c[i];
			else {
				ac--;
				for (ll l = m + (j - 1) * n + 1; l <= m + j * n; l++) {
					if (b[l] == 1) {
						b[l] = 0;
						jian += w[l];
					}
				}
			}
		}
		if (ans + cc - jian > realans || newb[i] <= 1) {
			for (ll j = 1; j <= tot; j++)
				b[j] = oldb[j];
			ac = oldac;
		} else {
			realans = ans + cc - jian;
		}
	}
	cout << realans;
	/*
	4 4 0
	1 4 6
	2 3 7
	4 2 5
	4 3 4
	1 1 8 2 4
	100 1 3 2 4
	*/
}
