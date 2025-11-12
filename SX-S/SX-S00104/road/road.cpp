#include <bits/stdc++.h>
using namespace std;
int n, m, k, cnt, c[20005], a[15][20005], flag[20005];
bool vis[20005];

struct node {
	int u, v, w;
} edge[20005];

bool cmp(node x, node y) {
	return x.w < y.w;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	sort(edge + 1, edge + m + 1, cmp);
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		if (flag[edge[i].u] == 0 || flag[edge[i].v] == 0) {
			ans += edge[i].w;
			flag[edge[i].u] = flag[edge[i].v] = 1;
		}
	}
	cout << ans << endl;
	return 0;
}
