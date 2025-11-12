#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; 1 <= i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		if (v != u) {
			u = i;
		}
		for (int j = 1; 1 <= j <= k; j++) {
			int c;
			string a[n];
			cin >> c ;
			c = j;
			cout << c + u + v ;
		}
	}
	return 0;
}
