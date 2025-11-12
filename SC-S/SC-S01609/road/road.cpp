#include <bits/stdc++.h>
using namespace std;

const int M = 1e7 + 5;
const int N = 1e4 + 5;

int n, m, k;

int ltt;
struct startree {
	int u, v, w;
} g[M];
void addedge(int u, int v, int w) {
	g[++ltt] = (startree) {
		u, v, w
	};
}
bool cmp(startree x, startree y) {
	return x.w < y.w;
}
int fa[N];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int ans;
int tac[N][N];
int cst[N];
int con[N][N];

void kruskal2() {
	sort(g + 1, g + 1 + ltt, cmp);
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
	}
	int _cnt = 0;
	for (int i = 1; i <= ltt; ++i) {
		int u = g[i].u, v = g[i].v;
		int fu = find(u), fv = find(v);
		if (fu != fv) {
			ans += g[i].w;
			fa[fu] = fv;
			++_cnt;
			if (_cnt == n) {
				return;
			}
		}
	}
	return;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		addedge(u, v, w);
	}
	for (int j = 1; j <= n; ++j) {
		for (int k = 1; k <= n; ++k) {
			tac[j][k] = 1e9;
		}
	}
	for (int i = 1; i <= k; ++i) {
		scanf("%d", &cst[i]);
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &con[i][j]);
		}
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				tac[j][k] = min(tac[j][k], con[i][j] + con[i][k] + cst[i]);
			}
		}
	}

	for (int j = 1; j <= n; ++j) {
		for (int k = 1; k <= n; ++k) {
			addedge(j, k, tac[j][k]);
		}
	}
	kruskal2();
	printf("%d", ans);
	return 0;
}
