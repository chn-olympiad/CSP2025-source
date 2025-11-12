#include <bits/stdc++.h>
#define maxn 10005
#define maxm 1000006
using namespace std;
int n, m, k, cnt, ans;
int fa[maxn];

struct node {
	int u, v, w;
} bian[maxm];

int find(int x) {
	if (fa[x] == x)
		return x;
	else
		return fa[x] = find(fa[x]);
}

bool cmp(node x, node y) {
	return x.w < y.w;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		bian[++cnt].u = u;
		bian[cnt].v = v;
		bian[cnt].w = w;
	}
	for (int i = 1; i <= k; i++) {
		int w;
		for (int j = 1; j <= n; j++) {
			scanf("%d", &w);
			bian[++cnt].u = i;
			bian[cnt].v = j;
			bian[cnt].w = w;
		}
	}
	sort(bian + 1, bian + cnt + 1, cmp);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= cnt; i++) {
		if (find(bian[i].u) != find(bian[i].v)) {
			fa[find(bian[i].u)] = find(bian[i].v);
			ans += bian[i].w;
		}
	}
	cout << ans;
	return 0;
}
