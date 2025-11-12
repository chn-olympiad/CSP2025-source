#include <bits/stdc++.h>
using namespace std;

struct node {
	int u, v, w;
} ed[2000100];
int dist[15], tot, fa[10050];

bool operator<(node a, node b) {
	return a.w < b.w;
}

void add(int u, int v, int w) {
	ed[tot].u = u;
	ed[tot].v = v;
	ed[tot++].w = w;
}

int find(int x) {
	if (x != fa[x])
		return fa[x] = find(fa[x]);
	return fa[x];
}
int m;

long long kuls() {
	sort(ed, ed + m);
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		int u = ed[i].u, v = ed[i].v;
		if (find(u) != find(v)) {
			ans += ed[i].w;
			fa[find(u)] = find(v);
		}
	}
	return ans;
}

int main() {

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= n + 50; i++) {
		fa[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
	}
	int an = 0;
	for (int i = 1; i <= k; i++) {
		scanf("%d", &dist[i]);
		an = max(an, dist[i]);
		for (int j = 1; j <= n; j++) {
			int w;
			scanf("%d", &w);
			an = max(an, w);
		}
	}
	if (an == 0) {
		printf("0\n");
		return 0;
	}
	long long ans = kuls();
	printf("%lld\n", ans);
	return 0;
}
