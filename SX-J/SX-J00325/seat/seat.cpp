#include <bits/stdc++.h>
using namespace std;
int m, n, s = 0;
int g = 0;

int a[11][11] = {{0}};
int u = 0, h = 0;
int j[121] = {0};
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < m * n; i++) {
		cin >> j[i];
		g++;
	}
	s = j[0];
	sort(j, j + m *n);
	for (int i = 0; i < m; i++) {
		for (int z = 0; z < n; z++) {
			g--;
			a[z][i] = j[g];
			if (a[z][i] == s) {
				u = z + 1, h = i + 1;
				cout << h << " " << u;
				return 0;
			}
		}
		i++;
		for (int z = n - 1; z >= 0; z--) {
			g--;
			a[z][i] = j[g];
			if (a[z][i] == s) {
				u = z + 1, h = i + 1;
				cout << h << " " << u;
				return 0;
			}
		}
	}
	return 0;
}
