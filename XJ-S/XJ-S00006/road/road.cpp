#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 1e4 + 5;
struct edge {
	int u, v, w;
	bool operator < (const edge &y)const {
		return w < y.w;
	}
}e[MAXN];
int a[MAXN], fa[MAXN], high[MAXN];
int ans;
int find(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
int main(void) {
	ios_base :: sync_with_stdio(false);
	cin . tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	int cnt = m;
	for (int i = 1;i <= n; ++i)
		fa[i] = i;
	for (int i = 1;i <= m; ++i)
		cin >> e[i].u >> e[i].v >> e[i].w;
	for (int i = 1;i <= k; ++i) {
		int c;
		cin >> c;
		for (int j = 1;j <= n; ++j)
			cin >> a[j];
		for (int j = 1;j < n; ++j)
			for (int k = j + 1;k <= n; ++k)
				e[++cnt] = {j, k, a[j] + a[k]};
	}
	sort(e + 1, e + 1 + cnt);
	for (int i = 1;i <= cnt; ++i) {
		int g1 = find(e[i].u), g2 = find(e[i].v);
		if (g1 == g2)
			continue;
		if (high[g1] < high[g2])
			swap(g1, g2);
		fa[g2] = g1;
		if (high[g1] == high[g2])
			++high[g1];
		ans += e[i].w;
	}
	cout << ans;
	return 0;
}
