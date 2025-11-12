#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 5;
int f[N << 1], w[15][N], c[N], form[N];
bool vis[N];
int n, m, k;
int res;
struct Edge {
	int u, v, l;
}a[M], q[N];
inline bool cmp(Edge a, Edge b) {
	return a.l < b.l;
}
inline void init() {
	for (int i = 1; i <= n * 2; i++)
		f[i] = i, vis[i] = 0;
}
inline int find(int x) {
	if (f[x] == x)
		return f[x];
	return f[x] = find(f[x]);
}
inline void dfs(int u, int sum, int ress) {
	if (ress >= res)
		return ;
	if (u > k) {
		init();
		int verb = m;
		for (int i = 1; i <= sum; i++)
			for (int j = 1; j <= n; j++) {
				Edge ex;
				ex.u = j;
				ex.v = n + i;
				ex.l = w[form[i]][j];
				a[++verb] = ex;
			}
		sort(a + 1, a + verb + 1, cmp);
		int rest = 0;
		int cnt = 0;
		for (int i = 1; i <= verb; i++) {
			int x = find(a[i].u), y = find(a[i].v);
			if (x != y) {
				if (!vis[x])
					cnt++, vis[x] = 1;
				if (!vis[y])
					cnt++, vis[y] = 1;
				f[x] = y;
				rest += a[i].l;
			}
			if (cnt == n + sum)
				break;
			if (rest + ress >= res)
				return ;
		}
		res = min(res, ress + rest);
		return ;
	}
	dfs(u + 1, sum, ress);
	form[sum + 1] = u;
	dfs(u + 1, sum + 1, ress + c[u]);
}
inline void solvea() {
	init();
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++) {
			Edge ex;
			ex.u = j;
			ex.v = n + i;
			ex.l = w[i][j];
			a[++m] = ex;
		}
	sort(a + 1, a + m + 1, cmp);
	int rest = 0;
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		int x = find(a[i].u), y = find(a[i].v);
		if (x != y) {
			if (!vis[x])
				cnt++, vis[x] = 1;
			if (!vis[y])
				cnt++, vis[y] = 1;
			f[x] = y;
			rest += a[i].l;
		}
		if (cnt == n + k)
			break;
	}
	cout << rest << "\n";
	return ;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].l);
	bool flag = 0;
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		if (c[i] != 0) {
			flag = 1;
		}
		for (int j = 1; j <= n; j++) {
			scanf("%d", &w[i][j]);
		}
	}
	if (!flag) {
		solvea();
		return 0;
	}
//	cout << 1 << "\n";
	sort(a + 1, a + m + 1, cmp);
	init();
	res = 0;
	int cnt = 0;
	int tot = 0;
	for (int i = 1; i <= m; i++) {
		int x = find(a[i].u), y = find(a[i].v);
		if (x != y) {
			f[x] = y;
			q[++tot] = a[i];
			res += a[i].l;
		}
	}
	for (int i = 1; i <= tot; i++)
		a[i] = q[i];
	m = tot;
//	dfs(1, 0, 0);
	printf("%d\n", res);
	return 0;
}
