#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
static struct Edge {
	long long u, v, w;
} edge[N << 2], ed[N << 2];
static long long n, m, k, fa[N], ins[15], top, ans = LONG_MAX, cnt, c[15], tt[15][N], wast, minn = LONG_MAX;
static long long find(long long u) {
	return fa[u] = (u == fa[u]) ? u : find(fa[u]);
}
static bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}
static long long kruskal(long long cned) {
	sort(edge + 1, edge + cnt + 1, cmp);
	long long s1 = 0, s2 = 0;
	for (long long i = 1; i <= cnt; ++i) {
		long long fu = find(edge[i].u), fv = find(edge[i].v);
		if (fu == fv) continue ;
		s1 += edge[i].w;
		fa[fu] = fv;
		++s2;
		if (s2 == cned - 1) return s1;
	}
	return -1;
}
static void back() {
	for (long long i = 1; i <= n + k; ++i) fa[i] = i;
	for (long long i = 1; i <= m; ++i) edge[i] = ed[i];
	cnt = m;
}
static void chose(long long x, long long tik) {
	if (x == k + 1) {
		back();
		for (long long i = 1; i <= top; ++i)
			for (long long j = 1; j <= n; ++j)
				edge[++cnt] = {n + ins[i], j, tt[ins[i]][j]};
		long long res = kruskal(top + n);
		if (res == -1) return ;
		ans = min(res + tik, ans);
		return ;
	}
	ins[++top] = x;
	chose(x + 1, tik + c[x]);
	ins[top--] = 0;
	chose(x + 1, tik);
}
static void read(long long &x) {
	x = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n), read(m), read(k);
	for (long long i = 1, u, v, w; i <= m; ++i) {
		read(u), read(v), read(w);
		ed[i] = edge[i] = {u, v, w};
	}
	cnt = m;
	for (long long i = 1; i <= k; ++i) {
		read(c[i]);
		for (long long j = 1; j <= n; ++j)
			read(tt[i][j]);
	}
	chose(1, 0);
	printf("%lld", ans);
	return 0;
}