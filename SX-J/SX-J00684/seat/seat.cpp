#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int c;
	cin >> c;
	int r[n * m];
	int a[n + 3][m + 3];
	for (int i = 1; i <= a[n]; i++) {
		for (int s = 1; s <= a[m]; s++) {
			cin >> a[i][s];
			if (c > r[n * m]) {
				cout << a[1][1];
			} else {
				cout << a[n][m];
			}
		}
	}


	return 0;
}