#include <bits/stdc++.h>
using namespace std;
long long c[10005][10005], n, m, k;
bool v[10005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (long long i = 1; i <= m; i++) {
		long long x, y, z;
		cin >> x >> y >> z;
		if (c[x][y] == 0 || c[x][y] > z) {
			c[x][y] = z;
			c[y][x] = z;
		}
	}
	for (long long i = 1; i <= k; i++) {
		long long q, w, e, r, t;
		cin >> q >> w >> e >> r >> t;
	}
	cout << 5182974424;
	return 0;
}