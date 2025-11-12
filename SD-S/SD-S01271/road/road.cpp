#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, M = 1e6 + 10;
int n, m, k;
long long c, a[N];
long long d[N][N];
int cnt;
struct edge {
	int u, v;
	long long w;
} E[M << 2];
bool cmp(edge a, edge b) {
	return a.w < b.w;
}
int fa[N];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
vector<pair<int, int> > vec; 
long long kruskal() {
	sort(E + 1, E + cnt + 1, cmp);
	for (int i = 1; i <= n; ++ i) {
		fa[i] = i;
	}
	long long tot = 0;
	for (int i = 1; i <= cnt; ++ i) {
		int u = E[i].u, v = E[i].v;
		long long w = E[i].w;
		if (find(u) != find(v)) {
			fa[find(u)] = find(v);
			vec.push_back({u, v});
//			cout << u << " " << v << '\n';
			tot += w;
		}
	}
	return tot;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	memset(d, 0x3f, sizeof d);
	for (int i = 1; i <= m; ++ i) {
		int u, v, w;
		cin >> u >> v >> w;
		E[i] = {u, v, w};
		d[u][v] = d[v][u] = w;
	}
	cnt = m;
	if (k == 0) {
		long long res = kruskal();
		cout << res;
		return 0;
	}
	for (int i = 1; i <= k; ++ i) {
		cin >> c;
		for (int j = 1; j <= n; ++ j) {
			cin >> a[j];
		}
		for (int u = 1; u <= n; ++ u) {
			for (int v = 1; v <= u; ++ v) {
				if (u == v) continue;
				d[u][v] = d[v][u] = min(d[u][v], a[u] + a[v] + c);
			}
		}
	}
	long long now = kruskal(), tot = 0;
	for (int i = 0; i < (int)vec.size(); ++ i) {
		tot += d[vec[i].first][vec[i].second];
	}
//	cout << tot;
	for (int u = 1; u <= n; ++ u) {
		for (int v = 1; v <= u; ++ v) {
//			cout << d[u][v] << ' ';
			if (u == v) continue;
			E[++ cnt] = {u, v, d[u][v]};
		} 
//		cout << '\n';
	}
	long long res = kruskal();
	cout << min(res, min(tot, now));
	return 0;
}
/*
64pts


5 6 1
1 2 4
1 5 1
3 5 2
2 3 6
4 5 3
3 4 7
0 1 1 1 1 1
*/
