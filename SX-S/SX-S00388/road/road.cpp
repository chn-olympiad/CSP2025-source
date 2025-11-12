#include <bits/stdc++.h>
using namespace std;
int n, m, z2[15][10006], x[1000006], y[1000006], z1[1000006], k, c[15];
long long ans = 0x3f3f3f3f, sum, sum1[50], sum2;
bool f[16], fl;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> x[i] >> y[i] >> z1[i];
		sum2 += z1[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> z2[i][j];
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= k; i++) {
			if (z1[j] > z2[i][x[j]] + z2[i][y[j]]) {
				z1[j] = z2[i][x[j]] + z2[i][y[j]];
			}
		}
		sum += z1[j];
	}
	cout << sum;
}