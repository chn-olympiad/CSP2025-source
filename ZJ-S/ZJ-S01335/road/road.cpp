// T2 road
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge {
	int u, v; ll w;
} e[2000010];
int cnt, n, m, k, fa[10010]; ll ans, c[15], a[15][10010];
int findfather(int x) {
	if (x == fa[x]) return x;
	else return fa[x] = findfather(fa[x]);
}
bool cmp(edge p, edge q) {
	return p.w < q.w;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1, u, v; i <= m; i++) {
		ll w;
		cin >> u >> v >> w;
		e[++cnt] = edge{u, v, w};
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) 
			cin >> a[i][j];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			ll cc = 1e18;
			for (int t = 1; t <= k; t++) 
				cc = min(cc, a[t][i] + a[t][j] + c[t]);
			e[++cnt] = edge{i, j, cc};
		}
	}
	sort(e + 1, e + 1 + cnt, cmp);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= cnt; i++) {
		int x = e[i].u, y = e[i].v;
		int fx = findfather(x), fy = findfather(y);
		if (fx != fy) {
			fa[fx] = fy;
			ans += e[i].w;
		}
	}
	cout << ans;
	return 0;
}