#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e4 + 50, maxm = 1e6 + 5;

int n, m, k, fa[maxn], cnt[15];

struct Edge {
	int u, v; ll w;
	
	bool operator< (const Edge &tmp) const {
		return w < tmp.w;
	}
} edge[maxm << 1], e[maxn << 1];

ll c[15], a[15][maxn], val[maxn];

int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) cin >> edge[i].u >> edge[i].v >> edge[i].w;
	ll ans = 0; bool ff = 1; int tmp = m;
	for(int i = 1; i <= k; i++) {
		cin >> c[i]; ans += c[i];
		if(c[i]) ff = 0;
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
			edge[++m] = (Edge){j, n + i, a[i][j]};
		}
	}
	if(ff || !k) {
		iota(fa + 1, fa + n + k + 1, 1);
		sort(edge + 1, edge + m + 1);
		for(int i = 1; i <= m; i++) {
			int u = find(edge[i].u), v = find(edge[i].v);
			if(u != v) {
				ans += edge[i].w, fa[u] = v;
				if(u > n) cnt[u - n]++, val[u - n] = edge[i].w;
				if(v > n) cnt[v - n]++, val[v - n] = edge[i].w;
			}
		}
		for(int i = 1; i <= k; i++)
			if(cnt[i] == 1) ans -= (c[i] + val[i]);
		cout << ans << "\n";
	}
	else {
		m = tmp;
		ans = 1e18;
		for(int i = 0; i < (1 << k); i++) {
			int ecnt = 0;
			for(int j = 1; j <= m; j++) e[++ecnt] = edge[j];
			ll res = 0;
			for(int j = 1; j <= k; j++) {
				if((1 << (j - 1)) & i) {
					res += c[j];
					for(int l = 1; l <= n; l++) e[++ecnt] = (Edge){l, n + j, a[j][l]};
				}
			}
			iota(fa + 1, fa + n + k + 1, 1);
			sort(e + 1, e + ecnt + 1);
			for(int j = 1; j <= ecnt; j++) {
				int u = find(e[j].u), v = find(e[j].v);
				if(u != v) res += e[j].w, fa[u] = v;
			}
			ans = min(ans, res);
		}
		cout << ans << "\n";
	}
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