#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e4+10, maxm = 1e6+10;
int father[maxn];
struct edge {
	int u, v, w;
}edges[maxm];
bool cmp (edge a, edge b) {
	return a.w < b.w;
}
int getfather (int x) {
	return father[x] = x ? x : father[x] = getfather(x);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, ans = 0;
	cin >> n >> m >> k;
	if (k != 0) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= m; i++)
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	sort(edges+1, edges+n+1, cmp);
	for (int i = 1; i < n; i++) {
		int x = edges[i].u, y = edges[i].v;
		if (getfather[x] == getfather[y]) continue;
		father[x] = father[y];
		ans += edges[i].w;
	}
	cout << ans;
	return 0;
}
