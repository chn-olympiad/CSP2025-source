// I LOVE CCF!!!!!!!!!
#include <bits/stdc++.h>
using namespace std;
int n, m, k, ex[15][1010], cost[15];
bool vis[15];
long long ans = 1e18, initcost = 0;

struct edge {
	int u, v, w;
} e[1100010], en[1100010];
int fa[10030];

int find(int a) {
	return fa[a] = fa[a] == a ? a : find(fa[a]);
}

void join(int x, int y) {
	int a = find(x), b = find(y);
	if (a != b)
		fa[a] = b;
}

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

int clear() {
	initcost = 0;
	int top = m;
	for (int i = 1; i <= k; i++)
		if (vis[i]) {
			initcost += cost[i];
			for (int j = 1; j <= n; j++)
				e[++top].u = i + n, e[top].v = j, e[top].w = ex[i][j];
		}
	return top;
}

void kruskal(int top) {
	long long now = initcost;
	for (int i = 1; i <= top; i++)
		en[i].u = e[i].u, en[i].v = e[i].v, en[i].w = e[i].w;
	sort(en + 1, en + top + 1, cmp);
	for (int i = 1; i <= top; i++) {
		if (find(en[i].u) == find(en[i].v))
			continue;
		else {
			join(en[i].u, en[i].v);
			now += en[i].w;
		}
	}
	ans = min(now, ans);
	for (int i = 1; i <= n + k; i++)
		fa[i] = i;
}

void dfs(int d) {
	if (d > k) {
		kruskal(clear());
		return;
	}
	for (int i = 0; i <= 1; i++) {
		vis[d] = i;
		dfs(d + 1);
		vis[d] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n + k; i++)
		fa[i] = i;
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		e[i].u = u, e[i].v = v, e[i].w = w;
	}
	if (!k)
		kruskal(0);
	else {
		for (int i = 1; i <= k; i++) {
			cin >> cost[i];
			for (int j = 1; j <= n; j++)
				cin >> ex[i][j];
		}
		dfs(1);
	}
	cout << ans;
	return 0;
}