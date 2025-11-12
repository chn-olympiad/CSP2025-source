#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t, n, m, k, f[10025][10025], a[10025][10025];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		f[1][i] = 0;
		for (int j = 1; j <= n; j++) {

			a[i][j] = 1e9;
			a[j][i] = 1e9;

		}
	}

	for (int i = 1; i <= m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		a[u][v] = w;
		a[v][u] = w;

	}
	for (int i = 1; i <= k; i++) {
		ll w;
		cin >> w;

		for (int j = 1; j <= m; j++) {
			cin >> w;
			a[n + i][j] = w;
			a[j][n + i] = w;
		}
	}


	for (int i = 2; i <= n + k; i++) {
		f[i] = 1e9;
		for (int j = 1; j < i; j++) {
			f[i] = min(f[i - 1] + a[i][j], f[i]);
		}

	}
	t = 1e9;
	for (int i = n; i <= n + k; i++) {
		t = min(t, f[i]);
	}
	cout << t;




}