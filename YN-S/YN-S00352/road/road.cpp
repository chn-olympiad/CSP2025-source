#include <bits/stdc++.h>
using namespace std;

struct cpl {
	int x, y;
};

bool cmp(cpl a, cpl b) {
	return a.x > b.x;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int a[10005], b[15];
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= 10004; i++)
		a[i] = 1e9;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u] = min(a[u], w);
		a[v] = min(a[v], w);
	}
	int nu = 1e9;
	for (int i = 1; i <= k; i++) {
		cin >> b[i];
		cpl c[10005];
		for (int j = 1; j <= m; j++) {
			cin >> c[j].x;
			c[j].y = j;
		}
		sort(c + 1, c + n + 1, cmp);
		if (c[1].x + c[2].x > b[i])
			continue;
		nu = min(nu, b[i]);
		if (nu != b[i])
			continue;
		a[c[n].y] = min(a[c[n].y], c[n].x);
		a[c[n - 1].y] = min(a[c[n - 1].y], c[n - 1].x);
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
	}
	sum += nu;
	cout << sum << endl;
	return 0;
}