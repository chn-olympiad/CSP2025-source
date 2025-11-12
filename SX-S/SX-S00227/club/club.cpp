#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int n, m, h = 0, o[100] = {}, a = 0, b = 0, c = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m;
		for (int y = 1; y <= m; y++) {
			for (int p = 1; p <= n; p++) {
				cin >> o[p];
				if (h <= o[p]) {
					if (p == 1) {
						a = a + o[p];
						h = o[p];
					}
					if (p == 2) {
						b = b + o[p];
						a = a - o[p - 1];
						h = o[p];
					}
					if (p == 3) {
						c = c + o[p];
						b = b - o[p - 1];
						h = 0;
					}

				}
			}
		}
	}
	cout << b << endl << c << endl << a;
	return 0;
}
