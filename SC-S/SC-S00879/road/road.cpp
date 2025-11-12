#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
map<int, map<int, int>> mp;
int ed = 0;
int fa[N];
struct edge {
	int u, v, w;
}; 
edge g[N];
int wp[N];
int findroot(int x) {
	return fa[x] == x ? x : fa[x] = findroot(fa[x]);
}
void merge(int x, int y) {
	int xr = findroot(x);
	int yr = findroot(y);
	if (xr == yr) {
		return ;
	}
	fa[xr] = yr;
}
void add(int u, int v, int w) {
	ed++;
	g[ed].u = u;
	g[ed].v = v;
	g[ed].w = w;
}
bool cmp(edge A, edge B) {
	return A.w < B.w;
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	for (int i = 1; i <= k; i++) {
		cin >> wp[i];
	}
	if (k == 0) {
		int ans = 0;
		int tot = 0;
		sort(g + 1, g + ed + 1, cmp);
		for (int i = 1; i <= ed; i++) {
			int ur = findroot(g[i].u), vr = findroot(g[i].v), ws = g[i].w;
			if (ur != vr) {
//				cout << ans << '\n';
				ans += ws;
				tot++;
				merge(ur, vr);
//				if (tot == n - 1) {
//					cout << ans << '\n';
//					return 0;
//				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}