#include <bits/stdc++.h>
using namespace std;
int n, m, k, tot = 1;
int cn[15];

struct node {
	int va, to, nxt;
} edge[4000010];
int head[4000010];

void add(int u, int v, int w) {
	edge[tot].to = v;
	edge[tot].va = w;
	edge[tot].nxt = head[u];
	head[u] = tot;
	tot++;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	int a, b, c, d, e;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
		add(b, a, c);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &cn[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &e);
			add(j + i, j, d + e);
			add(j, j + i, d + e);
		}
	}
	for (int i = 1; i)
		return 0;
}
