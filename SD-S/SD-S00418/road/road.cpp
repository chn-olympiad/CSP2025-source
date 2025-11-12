#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int fa[1000005];
struct edge {
	int from, to, w;
}e[100005];
bool cmp(edge xx, edge yy) {
	return xx.w < yy.w;
}
bool find(int x) {
	if (fa[x] == x) {
		return x;
	} else {
		return fa[x] = find(fa[x]);
	}
}
void add(int x, int y) {
	fa[x] = y;
} 
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[++k].from = u;
		e[k].to = v;
		e[k].w = w;
	}
	if (k == 0) {
		sort(e + 1, e + n + 1, cmp);
		long long ans = 0;
		for (int i = 1; i <= m; i++) {
			if (find(e[i].from) != find(e[i].to)) {
				add(e[i].from, e[i].to);
				ans += e[i].w;
				cout << ans << " ";
			}
		}
		cout << ans << endl;
	} else {
		cout << 0 << endl;
	}
	return 0;
}
