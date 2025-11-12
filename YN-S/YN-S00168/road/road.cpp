#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 3, K = 10, inf = 0x3f3f3f3f;


struct e {
	int u, v, w;
} g[10000003];
int n, m, k, cntg;
int d[N][N], a[K][N], f[N], ans;

int fd(int x) {
	return f[x] == x ? x : f[x] = fd(f[x]);
}

int di() {
	int cnt = 0, i;
	sort(g, g + cntg, [](e i, e j) {
		return i.w > j.w;
	});
	while (cnt != n - 1) {
		e en = g[i--];
		int fu = fd(en.u), fv = fd(en.v);
		if (fu != fv) {
			f[en.u] = fv;
			ans += en.w;
			cnt++;
		}
	}
	return ans;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.ans", "w", stdout);
	cin >> n >> m >> k;
	memset(d, inf, N * N);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		d[u][v] = d[v][u] = w;
	}
	for (int i = 1; i <= k; i++) {
		int c;
		cin >> c;
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			for (int y = 1; y <= j; y++) {
				if (j != y)
					d[j][y] = d[y][j] = min(d[j][y], a[i][j] + a[i][y]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		f[i] = i;
		for (int j = 1; j <= n; j++) {
			g[cntg++] = {i, j, d[i][j]};
		}
	}
	cout << di();
	return 0;
}
