#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define File(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std;
const int N = 2e4 + 10, M = 1e6 + 10;
int n, m, k, u, v, w, c[N], a[20][N], f[N], cnt, sum, tot, ans = 1e18;
int find(int x) {
	if (x == f[x]) return x;
	return f[x] = find(f[x]);
}
struct Edge {
	int u, v, w;
} E[M], e[M];
bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}
void kruskal() {
	for (int i = 1; i <= sum; i ++) f[i] = i;
	int i = 1, j = 1;
	while (sum --) {
		int u, v, w;
		if (j >= cnt || i <= m && E[i].w <= e[j].w) {
			u = E[i].u;
			v = E[i].v;
			w = E[i].w;
			i ++;
		}
		else {
			u = e[j].u;
			v = e[j].v;
			w = e[j].w;
			j ++;
		}
		if (find(u) != find(v)) {
			int ru = f[u];
			int rv = f[v];
			f[ru] = rv;
			tot += w;
		}
	}
	ans = min(ans, tot);
}
signed main() {
	File("road");
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++) {
		cin >> u >> v >> w;
		E[i] = {u, v, w};
	}
	for (int i = 1; i <= k; i ++) {
		cin >> c[i];
		for (int j = 1; j <= n; j ++) cin >> a[i][j];
	}
	sort(E + 1, E + m + 1, cmp);
	if (k == 0) {
		for (int i = 1; i <= n; i ++) f[i] = i;
		int ans = 0;
		for (int i = 1; i <= m; i ++) {
			int u = E[i].u;
			int v = E[i].v;
			int w = E[i].w;
			if (find(u) != find(v)) {
				int ru = f[u];
				int rv = f[v];
				f[ru] = rv;
				ans += w;
			}
		}
		cout << ans << endl;
		return 0;
	}
	for (int i = 0; i < (1 << k); i ++) {
		tot = 0, cnt = 0, sum = m;
		for (int j = 1; j <= k; j ++) {
			if ((i >> j - 1) & 1) {
				sum ++;
				tot += c[j];
				for (int p = 1; p <= n; p ++) {
					e[++ cnt] = {sum, p, a[j][p]};
				}
			}
		}
		sort(e + 1, e + cnt + 1, cmp);
		kruskal();
	}
	cout << ans << endl;
	return 0;
}
