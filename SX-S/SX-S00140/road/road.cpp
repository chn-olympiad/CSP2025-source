#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int v[1005], u[1005], w[1005];
int c[15];
int a[15][10002];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i], w[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	return 0;
}
