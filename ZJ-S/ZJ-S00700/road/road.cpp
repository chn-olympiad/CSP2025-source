#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

const int N = 1e4 + 10, M = 1e6 + 10, K = 15;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int n, m, k;
struct E {
	int u, v, w;
	inline friend bool operator<(const E &a, const E &b) {
		return a.w < b.w;
	}
} oe[M], e[N], ee[N * K];
int c[K], val[K][N];

int fa[N];
int get(int x) {
	return fa[x] == x ? x : fa[x] = get(fa[x]);
}
inline bool merge(int u, int v) {
	u = get(u), v = get(v);
	if (u == v) return false;
	return fa[u] = v, true;
}

inline void read(int &x) {
	x = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar());
	for (; '0' <= c && c <= '9'; c = getchar())
		x = (x << 3) + (x << 1) + (c ^ 48);
}

int main() {
#ifndef XuYueming
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
#endif
	read(n), read(m), read(k);
	for (int i = 1, u, v, w; i <= m; ++i) {
		read(u), read(v), read(w);
		oe[i] = {u, v, w};
	}
	for (int i = 1; i <= k; ++i) {
		read(c[i]);
		for (int j = 1; j <= n; ++j) {
			read(val[i][j]);
		}
	}
	sort(oe + 1, oe + m + 1);
	for (int i = 1; i <= n; ++i) fa[i] = i;
	int nm = 0;
	for (int i = 1; i <= m; ++i)
		if (merge(oe[i].u, oe[i].v))
			e[++nm] = oe[i];
	m = nm;
	ll ans = inf;
	for (unsigned s = 0; s < 1u << k; ++s) {
		ll sum = 0;
		int ec = 0;
		for (int i = 1; i <= k; ++i) {
			if (~s & 1 << (i - 1)) continue;
			sum += c[i];
			for (int j = 1; j <= n; ++j)
				ee[++ec] = {n + i, j, val[i][j]};
		}
		sort(ee + 1, ee + ec + 1);
		for (int i = 1; i <= n + k; ++i) fa[i] = i;
		int i = 1, j = 1;
		while (i <= m || j <= ec) {
			E cur;
			if (i <= m && (j > ec || e[i] < ee[j]))
				cur = e[i++];
			else
				cur = ee[j++];
			if (merge(cur.u, cur.v)) sum += cur.w;
		}
		ans = min(ans, sum);
	}
	printf("%lld", ans);
	return 0;
}
