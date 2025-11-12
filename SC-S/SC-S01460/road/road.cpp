#include <bits/stdc++.h>
char *p1, *p2, buf[100000];
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread (buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++)
#define ll long long
using namespace std;

template <typename T> void read (T &x) {
	x = 0; int f = 1; char ch = getchar ();
	while (!isdigit (ch)) f = (ch == '-') ? -1 : f, ch = getchar ();
	while (isdigit (ch)) x = x * 10 + (ch & 15), ch = getchar (); x *= f;
}

const int N = 10010, M = 1000010;
int n, m, k, c[10], a[10][N], fa[N], cnt[1024]; ll ans, sum[1024];
int findfa (int u) { return u == fa[u] ? u : fa[u] = findfa (fa[u]); }

struct edge {
	int u, v, w;
	bool operator < (const edge &rhs) const {
		return w < rhs.w;
	}
} e[M], g[1024][N];

ll kruskal (int S, int B) {
	ll now = 0;
	int sz = __builtin_popcount (S);
	sort (e + 1, e + B + 1);
	for (int i = 1; i <= n + sz; i++) fa[i] = i;
	for (int i = 1, u, v; i <= B; i++) {
		u = findfa (e[i].u);
		v = findfa (e[i].v);
		if (u == v) continue;
		now += e[i].w, fa[u] = v;
		g[S][++cnt[S]] = e[i];
	}
	return now;
}

signed main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	// freopen ("road4.in", "r", stdin);
	// freopen ("myB.txt", "w", stdout);
	read (n), read (m), read (k);
	for (int i = 1, u, v, w; i <= m; i++) {
		read (u), read (v), read (w);
		e[i] = {u, v, w};
	}
	for (int i = 0; i < k; i++) {
		read (c[i]);
		for (int j = 1; j <= n; j++)
			read (a[i][j]);
	}
	ans = kruskal (0, m);
	for (int S = 1; S < (1 << k); S++) {
		int low = S & -S, x = __lg (low);
		int sz = __builtin_popcount (S);
		sum[S] = sum[S ^ low] + c[x];
		for (int i = 1; i <= cnt[S ^ low]; i++) e[i] = g[S ^ low][i];
		for (int i = 1; i <= n; i++) e[i + cnt[S ^ low]] = {n + sz, i, a[x][i]};
		ans = min (ans, kruskal (S, cnt[S ^ low] + n) + sum[S]);
	}
	printf("%lld\n", ans);
	return 0;
}