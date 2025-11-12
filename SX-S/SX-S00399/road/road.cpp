#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	int u, v, w;
	int c, a[10000][10], p = 0;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
	}
	for (int i = 0; i < k; i++) {
		cin >> c;
		p += c;
		for (int j = 0; j < n; j++) {
			cin >> a[j][i];
		}
	}
	cout << p << endl;
	return 0;
}
