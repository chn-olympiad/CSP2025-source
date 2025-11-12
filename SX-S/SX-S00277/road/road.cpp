#include <bits/stdc++.h>
const int N = 1e6+5;
#define ll long long
const ll mod = 1e18;

struct bian {
	int u, v, w, id;
} edge[N * 15];
int fa[N];

int find(int x) {
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

inline bool cmp(bian x, bian y) {
	return x.w < y.w;
}
int c[N], a[15][N];
bool flag[15];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
		edge[i].id = 0;
	}
	int cnr = m;
	std::sort(edge + 1, edge + m + 1, cmp);
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			cnr++;
			edge[cnr] = {n + i, j, a[i][j], i};
		}
	}
	for (int i = 1; i <= n + k; i++) {
		fa[i] = i;
	}
	ll cost = 0;
	if (k == 0) {
		for (int i = 1; i <= m; i++) {
			if (fa[find(edge[i].u)] == fa[find(edge[i].v)])
				continue;
			fa[find(edge[i].u)] = find(edge[i].v);
			cost += 1LL * edge[i].w;
		}
		return 0;
	}
	int num = pow(2, k);
	ll minn = mod;
	flag[0] = 1;
	std::sort(edge + 1, edge + cnr + 1, cmp);
	for (int i = 0; i < num; i++) {
		for (int j = 1; j <= k; j++) {
			flag[j] = 0;
		}
		for (int j = 1; j <= n + k; j++)
			fa[j] = j;
		cost = 0ll;
		for (int j = 1; j <= k; j++) {
			if ((i >> (j - 1)) & 1) {
				cost += 1ll * c[j];
				flag[j] = 1;
			}
		}
		for (int j = 1; j <= cnr; j++) {
			if (!flag[edge[j].id]) {
				continue;
			}
			if (fa[find(edge[j].u)] == fa[find(edge[j].v)])
				continue;
			fa[find(edge[j].u)] = find(edge[j].v);
			cost += edge[j].w;
		}
		minn = std::min(minn, cost);
	}
	printf("%lld\n", minn);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
