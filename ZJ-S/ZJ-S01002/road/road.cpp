#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e4 + 100, M = 1.2e6 + 10, mod = 998244353;
// Long Long 111
struct Edge {
	int u, v, w;
	bool operator < (const Edge &A) const {
		return w < A.w;
	}
} E[M], e[M];
int n, m, k, fa[N], vis[N], c[N], a[20][N], tot, ban[N], r[20];
int find(int u) { return u == fa[u] ? u : fa[u] = find(fa[u]); }
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n + k; i++) {
		fa[i] = i;
	}
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		E[i] = {u, v, w};
	}
	sort(E + 1, E + m + 1);
	ll ans = 0;
	for (int i = 1; i <= m; i++) {
		int u = E[i].u, v = E[i].v, w = E[i].w;
		if (find(u) != find(v)) {
			ans += w;
			fa[find(v)] = find(u);
			e[++tot] = {u, v, w};
		}
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	sort(e + 1, e + tot + 1);
	for (int i = 1; i <= tot; i++) E[i] = e[i];
	m = tot;
	for (int j = 1; j <= k; j++) {
		ll res = c[j];
		for (int i = 1; i <= k; i++) vis[i] = 0;
		vis[j] = 1;
		for (int i = 1; i <= n; i++) e[++tot] = {n + j, i, a[j][i]};
		sort(e + 1, e + tot + 1);
		for (int i = 1; i <= n + k; i++) {
			fa[i] = i;
		}
		for (int i = 1; i <= tot; i++) {
			int u = e[i].u, v = e[i].v, w = e[i].w;
			if (find(u) != find(v) && !ban[u]) {
				res += w;
				fa[find(v)] = find(u);
				if (u > n && !vis[u - n]) res += c[u - n], vis[u - n] = 1;
			}
		}
		if (res <= ans) {
			ans = res;
		} else {
			ban[n + j] = 1;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= k; i++) if (!ban[n + i]) r[++cnt] = i;
	k = cnt;
	
	for (int s = 1; s < (1 << k); s++) {
		for (int i = 1; i <= m; i++) e[i] = E[i];
		tot = m;
		ll res = 0;
		for (int i = 1; i <= k; i++) if (s >> (i - 1) & 1) {
			for (int j = 1; j <= n; j++) e[++tot] = {n + r[i], j, a[r[i]][j]};
			res += c[r[i]];
		}
		sort(e + 1, e + tot + 1);
		for (int i = 1; i <= n + k; i++) {
			fa[i] = i;
		}
		for (int i = 1; i <= tot; i++) {
			int u = e[i].u, v = e[i].v, w = e[i].w;
			if (find(u) != find(v)) {
//			dbg("TTT", u, v, w);
				res += w;
				fa[find(v)] = find(u);
			}
		}
		if (res <= ans) {
			ans = res;
		}
	}
	cout << ans << '\n';
	return 0;
}


