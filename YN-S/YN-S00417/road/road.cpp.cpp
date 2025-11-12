#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[10000][10000], b[10000][10000], x[10000];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		x[i] = a[i][2];
	}
	sort(x, x + 10000);
	cout << x[0];
	fclose(stdin);
	fclose(stdout);
}