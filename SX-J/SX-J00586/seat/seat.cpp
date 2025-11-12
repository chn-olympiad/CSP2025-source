#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	int g[100 + 5], ch = 0;
	int c = 0, r = 0;
	cin >> n >> m;
	for (int k = 0; k <= n * m; k++) {
		cin >> g[k];
	}
	for (int z = 0; z <= n * m; z++) {
		if (g[z] < g[z + 1]) {
			g[z] = ch;
			g[z] = g[z + 1];
			g[z + 1] = ch;
			break;
		} else {
			break;
		}
		for (int i = 0; i <= n; i++) {
			c = g[z];
			for (int j = 0; j <= m; j++) {
				r = g[z + 1];
			}

		}
	}

	cout << c << " " << r << endl;
	return 0;
}