//202511012025csp road tyk
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5, M = 2e6 + 6, A = 1e3 + 5; //
int fa[N];
long long dis[A][A], a[N];
priority_queue<pair<long long, pair<int, int>>>w;

int find(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, cnt = 1;
	long long ans = 0;
	cin >> n >> m >> k;
	int m2 = m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		long long val;
		cin >> u >> v >> val;
		w.push({-val, {u, v}});
	}
	if (k) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = 1e18;
		for (int i = 1; i <= k; i++) {
			long long c;
			cin >> c;
			for (int j = 1; j <= n; j++)
				cin >> a[j];
			for (int j = 1; j <= n; j++)
				for (int b = i + 1; b <= n; b++)
					dis[j][b] = min(dis[j][b], c * 3 / n + a[j] + a[b]);
		}
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				w.push({-dis[i][j], {i, j}});
	}
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	while (!w.empty()) {
		long long val = -w.top().first, u = w.top().second.first, v = w.top().second.second;
		w.pop();
		//cout << val << " " << u << " " << v << "\n";
		int fu = find(u), fv = find(v);
		if (fu != fv) {
			fa[fa[u]] = fa[v];
			ans += val;
			cnt++;
		}
		if (cnt == n)
			break;
	}
	cout << ans << "\n";
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