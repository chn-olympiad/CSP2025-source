#include <bits/stdc++.h>
using namespace std;
const int N = 10005, M = 1000005, K = 15;
int n, m, k, c[K], a[K][N], fa[N + K], E[M], cnt, w[M + N * K];
long long ans = 0x3f3f3f3f3f3f3f3fll;

struct EDGE {
	int u, v, w;
} edge[M + N * K];

struct TREE {
	int e[N + K], tot;
} tr[1034];

inline int read() {
	int x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
		ch = getchar();
	while (ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	return x;
}

inline bool cmp(int x, int y) {
	return w[x] < w[y];
}

int find(int x) {
	if (fa[x] == x)
		return x;
	fa[x] = find(fa[x]);
	return fa[x];
}

void run(int op) {
	stable_sort(E + 1, E + cnt + 1, cmp);
	for (int i = 1; i <= n + k; ++i)
		fa[i] = i;
	long long s = 0;
	for (int i = 1; i <= cnt; ++i) {
		int x = edge[E[i]].u, y = edge[E[i]].v, z = edge[E[i]].w, rx = find(x), ry = find(y);
		if (rx == ry)
			continue;
//		printf("%d %d %d\n", x, y, z);
		s += z, fa[rx] = ry, tr[op].e[++tr[op].tot] = E[i];
	}
//	printf("%d %lld\n", op, s);
	for (int i = 1; i <= k; ++i) {
		if (op & (1 << (i - 1)))
			s += c[i];
	}
//	printf("%d %lld\n", op, s);
	ans = min(ans, s);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; ++i)
		edge[i].u = read(), edge[i].v = read(), edge[i].w = read(), w[i] = edge[i].w;
	for (int i = 1; i <= k; ++i) {
		c[i] = read();
		for (int j = 1; j <= n; ++j)
			a[i][j] = read(), edge[m + (i - 1) * n + j] = {n + i, j, a[i][j]}, w[m + (i - 1)*n + j] = edge[m +
			          (i - 1) * n + j].w;
	}
	cnt = m;
	for (int i = 1; i <= m; ++i)
		E[i] = i;
	run(0);
	for (int i = 1; i < (1 << k); ++i) {
		int lb = (i&(-i)), x = 0;
		cnt = tr[i - lb].tot;
		for (int j = 1; j <= cnt; ++j)
			E[j] = tr[i - lb].e[j];
		while (lb)
			++x, lb >>= 1;
		for (int j = 1; j <= n; ++j)
			E[++cnt] = m + (x - 1) * n + j;
		run(i);
	}
	printf("%lld\n", ans);
	return 0;
}
