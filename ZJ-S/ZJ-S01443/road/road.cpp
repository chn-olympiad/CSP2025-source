#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10010, K = 15;
const int M = 1000010 + K * N;
int n, m, k, u[M], v[M], st[M], p[M], q[M];
ll w[M], c[N], ans;
namespace dsu {
	int fa[N];
	void init () {
		for (int i = 1; i <= n + k; i++) {
			fa[i] = i;
		}
	}
	int find (int u) {
		return u == fa[u]? u: (fa[u] = find (fa[u]));
	}
	void unionn (int u, int v) {
		fa[find (u)] = find (v);
	}
}
void read (int& x) {
	char c = getchar ();
	while (!isdigit (c)) {
		c = getchar ();
	}
	x = 0;
	while (isdigit (c)) {
		x = (x << 3) + (x << 1) + (c ^ '0');
		c = getchar ();
	}
}
void read (ll& x) {
	char c = getchar ();
	while (!isdigit (c)) {
		c = getchar ();
	}
	x = 0;
	while (isdigit (c)) {
		x = (x << 3) + (x << 1) + (c ^ '0');
		c = getchar ();
	}
}
int main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	read (n), read (m), read (k);
	for (int i = 1; i <= m; i++) {
		read (u[i]), read (v[i]), read (w[i]);
		p[i] = i;
	}
	sort (p + 1, p + m + 1, [] (int x, int y) { return w[x] < w[y]; });
	dsu::init ();
	int ec = 0;
	for (int i = 1; i <= m; i++) {
		if (dsu::find (u[p[i]]) == dsu::find (v[p[i]])) {
			continue;
		}
		q[++ec] = p[i];
		dsu::unionn (u[p[i]], v[p[i]]);
		if (ec == n - 1) {
			break;
		}
	}
	for (int i = 1; i <= k; i++) {
		read (c[i]);
		for (int j = 1; j <= n; j++) {
			read (w[++m]);
			u[m] = i + n, v[m] = j, st[m] = i;
			q[++ec] = m;
		}
	}
	swap (ec, m);
	sort (q + 1, q + m + 1, [] (int x, int y) { return w[x] < w[y]; });
	ans = 0x7f7f7f7f7f7f7f7fll;
	for (int S = 0; S < (1 << k); S++) {
		dsu::init ();
		ll cnt = 0;
		int ts = n - 1;
		for (int i = 1; i <= k; i++) {
			if (S >> (i - 1) & 1) {
				cnt += c[i];
				ts++;
			}
		}
		int ec = 0;
		for (int i = 1; i <= m; i++) {
			if (st[q[i]] != 0 && !(S >> (st[q[i]] - 1) & 1)) {
				continue;
			}
			if (dsu::find (u[q[i]]) == dsu::find (v[q[i]])) {
				continue;
			}
			cnt += w[q[i]];
			dsu::unionn (u[q[i]], v[q[i]]);
			if (++ec == ts) {
				break;
			}
		}
		ans = min (ans, cnt);
	}
	printf ("%lld\n", ans);
	return 0;
}