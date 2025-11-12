#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e4+10, M = 1e6+10;

int n, m, k, c[12], fa[N], cnt, arr[12][N];
ll ans;

struct edge {
	int u, v;
	ll val;
} e[M];

bool cmp(edge s1, edge s2) {
	return s1.val < s2.val;
}

int find(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

void kruskal() {
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v;
		u = find(u);
		v = find(v);
		if (u != v) {
			cnt++;
			fa[u] = v;
			ans += e[i].val;
		}
		if (cnt == n - 1)
			continue;
	}
	printf("%lld", ans);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%lld", &e[i].u, &e[i].v, &e[i].val);
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++)
			scanf("%d", &arr[i][j]);
	}
	if (k == 0)
		kruskal();
	return 0;
}
