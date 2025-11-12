#include <bits/stdc++.h>
using namespace std;
#define int long long
struct edge {
	int u, v, w;
	bool operator <(edge other) const{ 
		return w == other.w ? v < other.v : w < other.w;
	}
};
const int N = 10110;
set<edge> s;
int n, k, m;
int fa[100100], c[100100], a[N][N], siz[N];
int ans = 0x7fffFFFFffffFFFF;
int find_(int x) {
	return fa[x] == x ? x : (fa[x] = find_(fa[x]));
}
void dfs(int x, int sum, int tot) {
	if (x > k) {
		for (int i = 1; i <= tot; i++) {
			fa[i] = i;
			siz[i] = 1;
		}
		for (edge e : s) {
			int u = find_(e.u), v = find_(e.v);
			if (u == v) continue;
			sum += e.w;
			if (siz[v] > siz[u]) {
				fa[u] = v;
				siz[v] += siz[u];
			} else {
				fa[v] = u;
				siz[u] += siz[v];
			}
			if (sum > ans) {
				return;
			}
			if (siz[v] == tot || siz[u] == tot) {
				break;
			}
		}
		ans = sum;
		return;
	}
	if (sum > ans) {
		return;
	}
	dfs(x + 1, sum, tot);
	for (int i = 1; i <= n; i++) {
		s.insert(edge{i, tot + 1, a[x][i]});
	}
	dfs(x + 1, sum + c[x], tot + 1);
	for (int i = 1; i <= n; i++) {
		s.erase(s.find(edge{i, tot + 1, a[x][i]}));
		
	}
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	edge e;
	for (int i = 1; i <= m; i++) {
		cin >> e.u >> e.v >> e.w;
		s.insert(e);
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	dfs(1, 0, n);
	cout << ans;
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
