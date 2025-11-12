#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k, f[100005];

struct Eedge {
	int u, v, w;
} e[1000006];

bool cmp(Eedge x, Eedge y) {
	return x.w < y.w;
}

int find(int x) {
	if (f[x] == x)
		return x;
	f[x] = find(f[x]);
	return f[x];
}

void kruskal() {
	int ans = 0;
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v, fu = find(u), fv = find(v), w = e[i].w;
		if (fu == fv)
			continue;
		ans += w;
		f[fu] = fv;
	}
	cout << ans;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	if (!k) {
		for (int i = 1; i <= m; i++)
			cin >> e[i].u >> e[i].v >> e[i].w;
		kruskal();
	} else
		cout << 0;
	return 0;
}