#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[10005][10005];
long long sum;
int c[1000005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				a[i][j] = 0;
			else
				a[i][j] = -1047000000;
		}
	}
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u][v] = a[v][u] = min(a[u][v], w);
		sum += a[u][v];
	}
	int mmax = 0;
	int q = 1;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i][j] > 0) {
				c[q] = a[i][j];
			}
		}
	}
	sort(c + 1, c + q + 1);
	for (int i = 1; i < n; i++) {

	}
	cout << sum - mmax;
}