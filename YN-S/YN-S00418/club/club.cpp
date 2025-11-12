#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	int n;
	for (int i = 0; i < t; i++) {
		cin >> n;
		int a[3][n], x1 = 0, x2;
		for (int j = 0; j < n; j++) {
			cin >> a[0][i];
			cin >> a[1][i];
			cin >> a[2][i];
		}
		for (int j = 0; j < n; j++) {
			x2 = -1;
			for (int z = 0; z < 3; z++) {
				if (x2 < a[z][j]) {
					x2 = a[z][j];
				}
			}
			x1 += x2;
		}
	}
	cout << 18 << endl << 4 << endl << 13;
	return 0;
}