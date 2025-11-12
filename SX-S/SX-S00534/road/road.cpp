#include <bits/stdc++.h>
using namespace std;
int n, m, k, c[100], a, ans, f[10005][10005];

struct road {
	int u;
	int v;
	int w;
} r[100010];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		cin >> r[i].u >> r[i].v >> r[i].w;
		if (r[i].u > r[i].v) {
			swap(r[i].u, r[i].v);
		}
		if (f[r[i].u][r[i].v] != 0)
			f[r[i].u][r[i].v] = min(f[r[i].u][r[i].v], r[i].w);
		else
			f[r[i].u][r[i].v] = r[i].w;
	}

	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ans += f[i][j];
		}
	}
	cout << ans;
	return 0;
}