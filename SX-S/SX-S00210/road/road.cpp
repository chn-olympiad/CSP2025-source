#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
long long c[20], b[20][1010], g[1010][1010], v[1010][1010];
long long n, m, k, minv = LLONG_MAX;

struct st {
	long long u;
	long long v;
	long long w;
} a[N];

void dfs(int k, long long s, int cnt) {
	if (cnt == n + 1) {
		minv = min(minv, s);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (g[k][i] != 0) {
			s = s + g[k][i];
			v[k][i] = 0;
			v[i][k] = 0;
			dfs(i, s, cnt + 1);
			v[k][i] = 1;
			v[i][k] = 1;
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	memset(g, 0, sizeof(g));
	for (int i = 1; i <= m; i++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
		g[a[i].u][a[i].v] = a[i].w;
		g[a[i].v][a[i].u] = a[i].w;
		v[a[i].v][a[i].u] = 1;
		v[a[i].u][a[i].v] = 1;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			cin >> b[i][j];
	}
	dfs(1, 0, 0);
	cout << minv / 2;
	return 0;
}