#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e18;
int n, m, k;
int u[1000010];
int v[1000010];
int w[1000010];
int c[15];
int a[10010];
int jp[1000010];

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	int g = N;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
		}
		int f = 0;
		int z = 0;
		int q = 0;
		for (int j = 1; j <= m; j++) {
			if (u[j] == i) {
				f += min(w[j], a[v[j]]);
				if (a[v[j]] < w[j]) {
					q = 1;
				}
				jp[v[j]] = 1;
				z += w[j];
			} else if (v[j] == i) {
				f += min(w[j], a[u[j]]);
				if (a[v[j]] <= w[j]) {
					q = 1;
				}
				jp[v[j]] = 1;
				z += w[j];
			}
		}
		for (int j = 1; j <= n; j++) {
			if (jp[j] == 1) {
				jp[j] = 0;
			} else {
				if (j != i) {
					f += a[j];
					z = N;
				}
			}
		}
		if (q == 1) {
			f += c[i];
		}
		g = min(g, z);
		g = min(g, f);
	}
	cout << g;
}