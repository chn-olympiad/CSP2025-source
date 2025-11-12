#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e4 + 5;
struct node {
	int u, v, w;
};
vector <node> ed;
int n, m, k, ans, T, f[N], tot;
inline bool cmp (node x, node y) {
	return x.w < y.w;
}
inline int find (int x) {
	if (f[x] == x) return x;
	return f[x] = find (f[x]);
}
signed main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	ios :: sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n + k; i++)
		f[i] = i;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		ed.push_back ({u, v, w});
		tot++;
	}
	for (int u = 1; u <= k; u++) {
		int c, w;
		cin >> c;
		for (int v = 1; v <= n; v++) {
			cin >> w;
			if (c == 0) {
				ed.push_back ({u + n, v, w});
				tot++;
			}
		}
	}
	stable_sort (ed.begin (), ed.end (), cmp);
	for (int i = 0; i < tot; i++) {
		int u = ed[i].u;
		int v = ed[i].v;
		int w = ed[i].w;
		if (find (u) != find (v)) {
			ans += w;
			f[find (u)] = f[find (v)];
		}
	}
	cout << ans;
	return 0;
}