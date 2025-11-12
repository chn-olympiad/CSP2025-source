#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+7, M = 2e6+7;
int n, m, k, ans, c[13][N];
int head[N], cnt, fa[N];

struct str {
	int fro, nex, to, val;
} edge[2 * M];

bool cmp(str a, str b) {
	return a.val < b.val;
}

void add(int u, int v, int w) {
	edge[++cnt].val = w;
	edge[cnt].to = v;
	edge[cnt].fro = u;
	edge[cnt].nex = head[u];
	head[u] = cnt;
}

int find(int x) {
	if (x == fa[x])
		return x;
	fa[x] = find(x);
	return fa[x];
}

void mermge(int u, int v) {
	fa[find(u)] = find(v);
	return ;
}

int kruscal() {
	sort(edge + 1, edge + 1 + cnt, cmp);
	int res = 0;
	for (int i = 1; i <= cnt; i++) {
		int u = edge[i].fro, v = edge[i].to, w = edge[i].val;
		if (find(u) == find(v))
			continue;
		mermge(u, v);
		res += w;
	}
	return res;
}
int cao[14], tot;

void dfs(int x) {
	if (x == 0) {
		int ress = 0;
		for (int i = 1; i <= tot; i++) {
			ress += c[cao[i]][0];
			for (int j = 1; j <= n; j++) {
				add(i + n, j, c[cao[i]][j]);
				add(j, i + n, c[cao[i]][j]);
			}
		}
		ress += kruscal();
		ans = max(ans, ress);
		cnt = 2 * m;
		return ;
	}
	cao[++tot] = x;
	dfs(x - 1);
	tot--;
	dfs(x - 1);
	return ;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add(u, v, w);
		add(u, v, w);
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++)
			scanf("%d", &c[i][j]);
	}
	if (k == 0)
		printf("%d", kruscal());
	else {

		dfs(k);
		printf("%d", ans);
	}
	return 0;
}