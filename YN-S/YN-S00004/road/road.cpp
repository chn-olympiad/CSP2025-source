#include <bits/stdc++.h>
using namespace std;
const int M = 1e8 + 5;
const int N = 1e4 + 5;
int n, m, k;

struct node {
	int from, to;
	int w;
};
node edge[M];
int fa[N], rk[N];

int find(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
int c[11], a[11][10005];

void bin(int x, int y) {
	if (rk[x] > rk[y])
		fa[y] = x;
	else {
		if (rk[x] == rk[y])
			rk[y]++;
		fa[x] = y;
	}
}

bool cmp(node a, node b) {
	return a.w < b.w;
}
long long ans;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &edge[i].from, &edge[i].to, &edge[i].w);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	}
	if (k != 0) {
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= n; j++)
				for (int u = 1; u <= n; u++) {
					if (u == j)
						continue;
					edge[++m].from = j;
					edge[m].to = u;
					edge[m].w = c[i] + a[i][j] + a[i][u];
				}
	}
	sort(edge + 1, edge + 1 + m, cmp);
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
		rk[i] = 1;
	}
	for (int i = 1; i <= m; i++) {
		int f = edge[i].from;
		int t = edge[i].to;
		int x = find(f);
		int y = find(t);
		if (x == y)
			continue;
		bin(x, y);
		ans += edge[i].w;
	}
	printf("%ld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}