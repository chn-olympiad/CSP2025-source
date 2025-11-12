// 我们终会化作春风
// Think twice, code once.
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define eputchar(c) putc(c, stderr)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eputs(str) fputs(str, stderr), putc('\n', stderr)
using namespace std;

int n, m, k;
struct edge {
	int u, v, w;

	edge() = default;
	edge(int u, int v, int w): u(u), v(v), w(w) {}
} e[1000005];
int cost[15];
edge w[15][10005];
vector<edge> vec;
struct dsu {
	int fa[10015];

	void clear() {for (int i = 1; i < 10015; i++) fa[i] = i; return;}
	int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
	void merge(int x, int y) {fa[find(x)] = find(y); return;}
	int query(int x, int y) {return find(x) == find(y);}
} d;
long long ans;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	sort(e + 1, e + m + 1, [](const edge &x, const edge &y) {return x.w < y.w;});
	d.clear();
	for (int i = 1; i <= m; i++)
		if (!d.query(e[i].u, e[i].v)) vec.push_back(e[i]), d.merge(e[i].u, e[i].v), ans += e[i].w;
	// eprintf("%lld\n", ans);
	for (int i = 1; i <= k; i++) {
		scanf("%d", &cost[i]);
		for (int j = 1; j <= n; j++) scanf("%d", &w[i][j].w), w[i][j].u = n + i, w[i][j].v = j;
		sort(w[i] + 1, w[i] + n + 1, [](const edge &x, const edge &y) {return x.w < y.w;});
	}
	for (int S = 1; S < 1 << k; S++) {
		int mm = n - 1 + __builtin_popcount(S) * n;
		vector<edge> ee(vec);
		ee.reserve(mm);
		long long res = 0;
		for (int i = 1; i <= k; i++)
			if (S >> (i - 1) & 1) {
				res += cost[i];
				int mid = ee.size();
				for (int j = 1; j <= n; j++) ee.emplace_back(w[i][j]);
				inplace_merge(ee.begin(), ee.begin() + mid, ee.end(),
					[](const edge &x, const edge &y) {return x.w < y.w;});
			}
		// if (S == 1)
		// 	for (edge e : ee) eprintf("%d %d %d\n", e.u, e.v, e.w);
		d.clear();
		for (edge e : ee)
			if (!d.query(e.u, e.v)) d.merge(e.u, e.v), res += e.w;
		ans = min(ans, res);
	}
	printf("%lld\n", ans);
	return 0;
}