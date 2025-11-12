#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10, M = 1e6+10;
long long n, m, k, lts, sum;
int zb[N][N], c[20][N], f[N][N], vis[N][N];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		long long u, v, w;
		cin >> u >> v >> w;
		sum += w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i][0];
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
		}
	}
	cout << sum;
	return 0;
}
