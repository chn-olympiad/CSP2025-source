#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n = 0, m = 0, c = 0, r = 0;
	int a[100];
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
		for (int i = 0; i < n * m; i++) {
			for (int j = 0; j < n * m; j++) {
				for (int z = 0; z < n; z++) {
					for (int x = 0; x < m; x++) {
						if (a[i] > a[j]) {
							c++;
						}
						if (z == n) {
							r++;
						}
						cout << c << " " << r;
					}
				}
			}

		}
	}
	return 0;
}
