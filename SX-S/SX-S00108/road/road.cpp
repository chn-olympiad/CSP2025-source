#include <bits/stdc++.h>
using namespace std;
long long n, m, k, x, y, z, c[15], fa[100005], ant, ans, v[15];

struct edg {
	long long u, v, w, ol;
} edge[2000005];

bool cmp(edg a, edg b) {
	return a.w < b.w;
}


int find(int p) {
	if (p == fa[p])
		return p;
	return fa[p] = find(fa[p]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld%lld", &x, &y, &z);
		edge[i].u = x;
		edge[i].v = y;
		edge[i].w = z;
		edge[i].ol = 0;
	}
	c[0] = 0;
	int cnt = m;
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &z);
			cnt++;
			edge[cnt].u = i + n;
			edge[cnt].v = j;
			edge[cnt].w = z ;
			edge[cnt].ol = i;
		}
	}
	for (int i = 1; i <= 100005; i++) {
		fa[i] = i;
	}
	sort(edge + 1, edge + 1 + cnt, cmp);
	int e = 0;
	ant = 0;
	while (ant < n + k - 1) {
		e++;
		int p = edge[e].u;
		int q = edge[e].v;
//		printf("%d %d\n", fa[p], fa[q]);
		if (find(p) == find(q)) {
			continue;
		} else {
			fa[p] = find(q);
			ant++;
			ans += edge[e].w;
			v[edge[e].ol] ++;
		}
	}
	for (int i = 1; i <= k; i++) {
		if (v[i] != 0)
			ans += c[i];
	}
	printf("%lld", ans);
	return 0;
}
