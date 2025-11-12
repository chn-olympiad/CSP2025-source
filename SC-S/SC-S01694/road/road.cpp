#include <bits/stdc++.h>
#define fup(i, l, r) for (int i = (l); i <= (r); i++)
#define fdw(i, l, r) for (int i = (l); i >= (r); i--)
using lld = long long;
const int N = 1e4 + 5, M = 1e6 + 5;
int n, m, k, A[15][N], ufs[N + 15], C[15];
struct Edge {
	int u, v, w;
} edge[N * 15 + M], ed[N * 15 + M];
int tot;
int fa[N + 15];
int find(int x) { return ufs[x] == x ? x : ufs[x] = find(ufs[x]); }
int find2(int x) { return fa[x] == x ? x : fa[x] = find2(fa[x]); }
bool check() {
	fup(i, 1, k) if (C[i] != 0) return false;
	fup(i, 1, k) {
		bool f = false;
		fup(j, 1, n) {
			if (!A[i][j]) f = true;
		}
		if (!f)
			return false;
	}
	return true;
}
bool used[15];
void krus(lld& res) {
	fup(i, 1, tot) ed[i] = edge[i];
	// memcpy(ed, edge, sizeof edge);
	fup(i, 1, n + k) ufs[i] = i;
	std::sort(ed + 1, ed + tot + 1, [](const Edge& a, const Edge& b) { return a.w < b.w; });
	fup(i, 1, tot) {
		int u = ed[i].u, v = ed[i].v;
		if (find(u) != find(v)) {
			// printf("%d %d %d\n", u, v, ed[i].w);
			ufs[find(u)] = find(v);
			res += ed[i].w;
		}
	}
}
lld ans = 1e18;
void DFS(int j, lld res) {
	if (j > k) {
		// printf("res = %lld: ", res);
		krus(res);
		// printf("res = %lld\n", res);
		ans = std::min(res, ans);
		return;
	}
	used[j] = false;
	DFS(j + 1, res);

	// printf("j = %d: ", j);
	// fup(i, 1, tot) printf("(%d, %d)\n", edge[i].u, edge[i].v);
	used[j] = true;
	int t = tot;
	fup(i, 1, n) edge[++tot] = { j + n, i, A[j][i] };
	DFS(j + 1, res + C[j]);
	tot = t;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	fup(i, 1, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edge[++tot] = { u, v, w };
	}
	fup(j, 1, k) {
		scanf("%d", C + j);
		fup(i, 1, n) scanf("%d", A[j] + i);
	}
	if (check()) {
		// printf("!!!\n");
		ans = 0;
		fup(j, 1, k) {
			ans += C[j];
			fup(i, 1, n) edge[++tot] = { j + n, i, A[j][i] };
		}
		krus(ans);
		printf("%lld\n", ans);
	} else {
		int tt = 0;
		fup(i, 1, n + k) ufs[i] = i;
		memcpy(ed, edge, sizeof ed);
		std::sort(ed + 1, ed + tot + 1, [](const Edge& a, const Edge& b) { return a.w < b.w; });
		// lld sum = 0;
		fup(i, 1, tot) {
			int u = ed[i].u, v = ed[i].v;
			// printf("%d %d %d\n", ed[i].u, ed[i].v, ed[i].w);
			if (find(u) != find(v)) {
				ufs[find(u)] = find(v);
				// sum += ed[i].w;
				// if (u <= n && v <= n) {
					// printf("%d %d %d\n", ed[i].u, ed[i].v, ed[i].w);
					edge[++tt] = ed[i];
				// }
			}
		}
		tot = tt;
		// fup(i, 1, tot) {
		// 	if (ed[i].u <= n && ed[i].v <= n && find2(ed[i].u) != find2(ed[i].v)) {
		// 		printf("%d %d %d\n", ed[i].u, ed[i].v, ed[i].w);
		// 		edge[++tt] = ed[i];
		// 	}
		// }

		ans = 1e18;
		DFS(1, 0);
		printf("%lld\n", ans);
	}
	fclose(stdin), fclose(stdout);
	return 0;
}