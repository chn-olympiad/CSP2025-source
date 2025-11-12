#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 100;
int n, m, k, fa[N], cnt, ans, t;
struct node{
	int u;
	int v;
	int w;	
}a[N];
int cmp(node x, node y) {
	return x.w < y.w;
}
int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]); 
}
void solve() {
	for (int i = 1; i <= n + k; i++) {
		fa[i] = i;
	}
	sort(a + 1, a + t + 1, cmp);
	for (int i = 1; i <= t && cnt < n + k - 1; i++) {
		int u = find(a[i].u);
		int v = find(a[i].v);
		if (u == v) continue;
		fa[u] = v;
		ans += a[i].w;
		cnt ++;
	}
	cout << ans;
	return ;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		a[i].u = u;
		a[i].v = v;
		a[i].w = w;
	}
	t = m;
	if (k == 0) solve();
	else {
		for (int i = 1; i <= k; i++) {
			int c;
			cin >> c;
			for (int j = 1; j <= n; j++) {
				int w;
				cin >> w;
				a[++t] = {i + n, j, w};
			}
		}
		solve();
	}
	return 0;
}