#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 2e5 + 5;
const int M = 1e6 + 5;
struct Edge {
	int u, v, w, flag;
} e[M];
int fa[N];
int Find(int u) {
	if (fa[u] == u) return u;
	return fa[u] = Find(fa[u]);
}
int a[15][N];
int lowbit(int x) { return x & (-x); }
int Findc(int x) {
	int res = 0;
	while (x) {
		res ++;
		x -= lowbit(x);
	}
	return res;
}
int ans = 0;
int n, m, k, c[N];
Edge e2[M << 1]; int top;
void dfs(int u, int S) {
	if (u == k + 1) return;
	int etot = Findc(S) + n - 1;
	int A = top;
	for (int i = 1 ; i <= etot ; i ++) e2[++ top] = e[i];

	for (int i = 1 ; i <= n ; i ++)
		e[++ etot] = (Edge) {
		u + n, i, a[u][i], 0
	};
	sort(e + 1, e + etot + 1, [&](Edge x, Edge y) {
		return x.w < y.w;
	});	
	int res = 0;
	for (int i = 1 ; i <= n + k ; i ++)
		fa[i] = i;
	for (int i = 1 ; i <= etot ; i ++) {
		int xx = Find(e[i].u), yy = Find(e[i].v);
		if (xx != yy) {
			fa[xx] = yy;
			res += e[i].w;
			e[i].flag = 1;
		} else e[i].flag = 0;
	}
	sort(e + 1, e + etot + 1, [&](Edge x, Edge y) {
		if (x.flag && y.flag) return x.w < y.w;
		return x.flag > y.flag;
	});
	for (int i = 1 ; i <= k ; i ++)
		if (S & (1 << (i - 1))) res += c[i];
	res += c[u];
	ans = min(res, ans);
	dfs(u + 1, (S + (1 << (u - 1))));
	for (int i = A + 1 ; i <= top ; i ++) e[i - A] = e2[i];
	top = A;
	dfs(u + 1, S);
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1 ; i <= m ; i ++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	for (int i = 1 ; i <= k ; i ++) {
		cin >> c[i];
		for (int j = 1 ; j <= n ; j ++) cin >> a[i][j];
	}
	sort(e + 1, e + m + 1, [&](Edge x, Edge y) {
		return x.w < y.w;
	});
	for (int i = 1 ; i <= n ; i ++) fa[i] = i;
	for (int i = 1 ; i <= m ; i ++) {
		int xx = Find(e[i].u), yy = Find(e[i].v);
		if (xx != yy) {
			fa[xx] = yy;
			ans += e[i].w;
			e[i].flag = 1;
		}
	}
//	cout << Findc(10);
//	cout << ans << '\n';
	sort(e + 1, e + m + 1, [&](Edge x, Edge y) {
		if (x.flag && y.flag) return x.w < y.w;
		return x.flag > y.flag;
	});
//	for (int i = 1 ; i < n ; i ++) 
//		cout << e[i].u << ' ' << e[i].v << ' ' << e[i].w << '\n';
	dfs(1, 0);
	cout << ans;
	return 0;
}