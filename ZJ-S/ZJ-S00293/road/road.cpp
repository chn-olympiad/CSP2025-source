#include <bits/stdc++.h>
using namespace std;
const int N = 1e4, M = 1e6, K = 10;
using ll = long long;
struct edge { int u, v, w; } e[M + 5];
struct node { int v, w; };
int a[11][N + 3], fa[N + 5], lm;
ll dp[N + 5][1 << K | 3], val[N + 5][1 << K | 3], join[N + 5][1 << K | 3];
//ll mnn[N + 5][1 << K | 3];
vector<node> g[N + 5];
int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void dfs(int u, int f) {
	for (int S = 0; S <= lm; S++) dp[u][S] = val[u][S] + join[u][S];
	for (auto& v : g[u]) {
		if (v.v == f) continue ;
		dfs(v.v, u);
		for (int S = 0; S <= lm; S++) {
			ll mn = dp[v.v][0] + v.w; // problems
			if (S) mn = min(mn, dp[v.v][S] - join[u][S]);
//			for (int T = S; T; T = (T - 1) & S) 
//				mn = min(mn, dp[v.v][T] - join[u][T]);
			dp[u][S] += mn;
		}
	}
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		e[i] = {u, v, w};
	}
	for (int i = 0; i < k; i++) {
		cin >> a[i][0];
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	sort(e + 1, e + m + 1, [](edge& x, edge& y) { return x.w < y.w; });
	for (int i = 1; i <= n; i++) fa[i] = i;
	ll tmp = 0;
	for (int i = 1, fx, fy, cnt = 0; i <= m; i++) {
		if (cnt >= n - 1) break ;
		fx = find(e[i].u), fy = find(e[i].v);
		if (fx == fy) continue ;
		fa[fy] = fx, ++cnt, tmp += e[i].w;
		g[e[i].u].push_back({e[i].v, e[i].w}), g[e[i].v].push_back({e[i].u, e[i].w});
	}
	if (k == 0) { cout << tmp << '\n'; return 0; } // 16
	lm = (1 << k) - 1;
	for (int i = 1; i <= n; i++)
		for (int S = 0; S <= lm; S++)
			for (int j = 0; j < k; j++)
				if (S >> j & 1)
					val[i][S] += a[j][i], join[i][S] += a[j][0];
	dfs(1, 1);
	ll ans = 0x3f3f3f3f3f3f3f3f;
	for (int S = 0; S <= lm; S++) ans = min(ans, dp[1][S]);
	cout << ans << '\n';
	// #3 504898585
	return 0;
}
/*
为什么不会 T2 啊 
*/
