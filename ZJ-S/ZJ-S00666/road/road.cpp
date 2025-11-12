#include <bits/stdc++.h>
constexpr long long Inf = acosl(-1) * 1E18L;
namespace UF {
	int f[10240], rnk[10240];
	int find(int x) {
		return f[x] != x ? f[x] = find(f[x]) : x;
	}
	void merge(int x, int y) {
		x = find(x), y = find(y);
		if(rnk[x] > rnk[y])
			f[y] = x;
		else
			rnk[y] += rnk[x] == rnk[y], f[x] = y;
	}
	bool same(int x, int y) {
		return x = find(x), y = find(y), x == y;
	}
	void clear() {
		for(int i = 0; i < 10240; i++)
			f[i] = i, rnk[i] = 0;
	}
}
int n, m, k, c[12];
struct edge {
	int u, v, w;
	constexpr bool operator < (const edge &b) const {
		return w < b.w;
	}
} e[1048576], w[12][10240];
void MST() {
	std::sort(e + 1, e + m + 1), UF::clear();
	for(int i = 1, j = 1; i <= m; i++)
		if(!UF::same(e[i].u, e[i].v))
			UF::merge(e[i].u, e[i].v), e[j] = e[i], j++;
	m = n - 1;
}
void merge_MST(const edge *ae, int an, const edge *be, int bn, edge *o) {
	int en = an + bn;
	std::merge(ae, ae + an, be, be + bn, o), UF::clear();
	for(int i = 0, j = 0; i < en; i++)
		if(!UF::same(o[i].u, o[i].v))
			UF::merge(o[i].u, o[i].v), o[j] = o[i], j++;
}
long long ans = Inf;
void DFS(int x, const edge *es, int esn, long long cc) {
	if(x == k + 1) {
		for(int i = 0; i < esn; i++)
			cc += es[i].w;
		ans = std::min(ans, cc);
		return;
	}
	DFS(x + 1, es, esn, cc);
	edge d[20480];
	merge_MST(es, esn, w[x] + 1, n, d),
	DFS(x + 1, d, esn + 1, cc + c[x]);
}
int main() {
	freopen("road.in", "rb", stdin);
	freopen("road.out", "wb", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++)
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	MST();
	for(int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for(int j = 1; j <= n; j++)
			scanf("%d", &w[i][j].w),
			w[i][j].u = i + n, w[i][j].v = j;
		std::sort(w[i] + 1, w[i] + n + 1);
	}
	DFS(1, e + 1, m, 0), printf("%lld\n", ans);
	return 0;
}
